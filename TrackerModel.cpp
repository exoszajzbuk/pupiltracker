////////////////////////////////////////////////////////////////////////////////
// Filename: TrackerModel.cpp
// Author:   Balazs KOVACS
// Year:     2010
//
// Description: Imlementation of TrackerModel class.
//
////////////////////////////////////////////////////////////////////////////////

// STL
#include <iostream>
#include <math.h>

// OpenCV
#include <cv.h>
#include <highgui.h>

// other
#include "TrackerModel.h"

// namespaces
using namespace std;
using namespace cv;

////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: TrackerModel
//
// Description: TrackerModel class default constructor
////////////////////////////////////////////////////////////
TrackerModel::TrackerModel()
{
    // default process method
    // 0 - Hough
    // 1 - snakes
    m_processMethod = 0;

    // default options
    m_isRendering = false;
    m_loopVideo = false;
    m_avgFPS = -1;

    // default statistics
    m_houghFalseDets = 0;
    m_snakeReInits = 0;

    // default average fps
    m_timePrev = 0;
    m_timeNow = 0;

    // default threshold values
    m_thresholdOn = true;
    m_thresholdValue = 25;

    // default blur values
    m_blurOn = true;
    m_blurKernel = 9;

    // default Hough values
    m_houghOn = true;
    m_houghAccRes = 2;
    m_houghMinDist = 480;
    m_houghCannyParam = 300;
    m_houghParam = 17;
    m_houghMinRad = 25;
    m_houghMaxRad = 50;


    // default snake values
    m_snakeOn = true;
    m_snakeContour = NULL;
    m_snakeContourLength = 12;
    m_snakeContourRadius = 150;
    m_snakeAlpha = 1.5;
    m_snakeBeta = 2.0;
    m_snakeGamma = 20.0;
    m_snakeKernel = 29;
    m_snakeTermCriteria.epsilon = 5;
    m_snakeTermCriteria.max_iter = 7;
    m_snakeTermCriteria.type = CV_TERMCRIT_ITER;

    // default show options
    m_showPictureHough = 0;
    m_showResultHough = true;

    m_showPictureSnake = 0;
    m_showResultSnake = true;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: initSnakeContour
//
// Description: This method initializes snake contour
//              to given position (in a circle).
////////////////////////////////////////////////////////////
void TrackerModel::initSnakeContour(int x0, int y0, int r, int num)
{
    // if already initialized, destroy
    if (m_snakeContour != NULL)
    {
        delete m_snakeContour;
    }

    // create contour
    m_snakeContour = new CvPoint[num];
    m_snakeContourLength = num;

    // set points to a circle
    double deg = 360/num;
    double rad = deg * (M_PI/180);

    for (int i = 0; i < num; i++)
    {
        int x = (int)(x0 + r*cos(i*rad));
        int y = (int)(y0 + r*sin(i*rad));

        if (x > getWidth())
        {
            x = getWidth();
        }

        if (x < 0)
        {
            x = 0;
        }

        if (y > getHeight())
        {
            y = getHeight();
        }

        if (y < 0)
        {
            y = 0;
        }

        m_snakeContour[i].x = x;
        m_snakeContour[i].y = y;
    }
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: initSnakeContour
//
// Description: This method checks if snake contour
//              needs to be reinitialized, and
//              reinitializes it if needed.
////////////////////////////////////////////////////////////
void TrackerModel::reInitSnakeContour(int thres)
{
    // temporary variables
    int x_min = getWidth();
    int x_max = 0;
    int x_sum = 0;

    int y_min = getHeight();
    int y_max = 0;
    int y_sum = 0;

    // calculate 'bonding box'
    for (int i = 0; i < m_snakeContourLength; i++)
    {
        int x = m_snakeContour[i].x;
        int y = m_snakeContour[i].y;

        if (x > x_max)
        {
            x_max = x;
        }
        
        if (x < x_min)
        {
            x_min = x;
        }

        if (y > y_max)
        {
            y_max = y;
        }
        
        if (y < y_min)
        {
            y_min = y;
        }

        x_sum += x;
        y_sum += y;
    }

    double x_avg = x_sum / m_snakeContourLength;
    double y_avg = y_sum / m_snakeContourLength;

    if ((x_max - x_min) < thres && (y_max - y_min) < thres)
    {
        // reinit contour
//        initSnakeContour(getWidth()/2, getHeight()/2, m_snakeContourRadius, m_snakeContourLength);
        initSnakeContour((int)x_avg, (int)y_avg, getWidth()/2, m_snakeContourLength);

        // increase error counter
        m_snakeReInits++;
    }

}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: loadVideoFile
//
// Description: This method loads a video file and sets
//              corresponding variables.
////////////////////////////////////////////////////////////
bool TrackerModel::loadVideoFile(const string& fileDir, const string& fileName)
{
    // get full path
    string filePath = fileDir + "/" + fileName;

    // if already opened, release
    if (m_cap.isOpened())
    {
        m_cap.release();
    }

    // try to open
    m_cap.open(filePath);
    
    if (!m_cap.isOpened())
    {
        // cannot open video file
        return false;
    }
    else
    {
        // load succeeded

        // set variables for dir and name
        m_fileDir = fileDir;
        m_fileName = fileName;

        // reset avg fps counter
        resetAvgFPS();
        
        // initializes snake contour
        initSnakeContour(getWidth()/2, getHeight()/2, m_snakeContourRadius, m_snakeContourLength);

        return true;
    }
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: closeVideoFile
//
// Description: This method closes the actually loaded
//              video file.
////////////////////////////////////////////////////////////
void TrackerModel::closeVideoFile()
{
    m_cap.release();
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: processThisFrame
//
// Description: This method processes the actual frame
//              by decreasing the current frame number
//              and calling processNextFrame().
////////////////////////////////////////////////////////////
bool TrackerModel::processThisFrame()
{
    // decrease frame counter
    setFrameAct(getFrameAct());

    // process the next frame
    return processNextFrame();
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: processNextFrame
//
// Description: This method processes the next frame in
//              video using the private variables to
//              determine what to do. (e.g. process
//              method, thresholding, blurring, etc).
////////////////////////////////////////////////////////////
bool TrackerModel::processNextFrame()
{
    // if there're no more frames
    if (m_cap.grab() == false)
    {
        // if looping is true
        if (m_loopVideo == true)
        {
            // back to the beginning
            setFrameAct(0);
            m_cap.grab();
        }
        else
        {
            // calculating average fps
            calculateAvgFPS();

            // stop rendering
            m_isRendering = false;
        }
    }
    // if there're more frames to process
    else
    {
        // temporary variables
        vector<Vec3f> circles;
        Mat img, gray, thr, blur, canny, out;
        IplImage snakeimg;

        // get next frame from capturer
        m_cap.retrieve(img);

        // convert it to grayscale
        cvtColor(img, gray, CV_BGR2GRAY);

        // switch process method
        switch (m_processMethod)
        {

            case 0:
                //**************************************************************
                // BEGIN Hough transform

                // -----
                // THRESHOLDING
                if (m_thresholdOn)
                {
                    // if thresholding is on, process
                    threshold(
                        gray,               // input image
                        thr,                // output image
                        m_thresholdValue,   // threshold value
                        255,
                        THRESH_BINARY
                    );
                }
                else
                {
                    // else just copy
                    thr = gray;
                }

                // -----
                // BLURRING
                if (m_blurOn)
                {
                    // if blurring is on, process
                    GaussianBlur(
                        thr,		                     // input image
                        blur,		                     // output image
                        Size(m_blurKernel,m_blurKernel), // Gaussian kernel-size
                        0,		                         // sigmaX 
                        0,		                         // sigmaY, default=0
                        BORDER_DEFAULT	                 // borderType
                    );
                }
                else
                {
                    // else just copy
                    blur = thr;
                }


                // -----
                // HOUGH TRANSFORM
                if (m_houghOn)
                {
                    HoughCircles(
                        blur,  			     // input image
                        circles,		     // output vector of found circles
                        CV_HOUGH_GRADIENT,	 // the '21HT' method
                        m_houghAccRes,	     // accumulator resolution
                        m_houghMinDist,	     // minimum distance between circles
                        m_houghCannyParam,	 // param1 (Canny-parameter)
                        m_houghParam,	     // param2, default=100
                        m_houghMinRad,       // minimum radius, default=0
                        m_houghMaxRad		 // maximum radius, default=0
                    );
    
                    // check error
                    if (circles.size() != 1)
                    {
                        m_houghFalseDets++;
                    }
                }

                    
                // -----
                // WHAT TO SHOW
                switch (m_showPictureHough)
                {
                    // original (color)
                    case 0:
                        cvtColor(img, out, CV_BGR2RGB);
                    break;

                    // threshold result
                    case 1:     
                        cvtColor(thr, out, CV_GRAY2RGB);
                    break;

                    // blur result
                    case 2:
                        cvtColor(blur, out, CV_GRAY2RGB);
                    break;
    
                    // canny result
                    case 3:
                        // reprocessing with canny
                        Canny(
                            blur,
                            canny,
                            m_houghCannyParam,
                            m_houghCannyParam/2
                        );  
    
                        cvtColor(canny, out, CV_GRAY2RGB);
                    break;
                }


                // ------
                // RESULT
                if (m_showResultHough)
                {
                    // draw detected circles
                    for(size_t i = 0; i < circles.size(); i++)
                    {
                        Point center(
                            cvRound(circles[i][0]), 
                            cvRound(circles[i][1])
                        );
                        int radius = cvRound(circles[i][2]);

                        // draw the circle center
                        circle(out, center, 3, Scalar(0,255,0), -1, 7, 0);

                        // draw the circle outline
                        circle(out, center, radius, Scalar(255,0,0), 1, 8, 0);
                    }
                }
                
                // END Hough transform
                //**************************************************************
            break;


            case 1:
                //**************************************************************
                // BEGIN Acitve Contour Model

                // -----
                // THRESHOLDING
                if (m_thresholdOn)
                {
                    // if thresholding is on, process
                    threshold(
                        gray,               // input image
                        thr,                // output image
                        m_thresholdValue,   // threshold value
                        255,
                        THRESH_BINARY
                    );
                }
                else
                {
                    // else just copy
                    thr = gray;
                }


                // -----
                // BLURRING
                if (m_blurOn)
                {
                    // if blurring is on, process
                    GaussianBlur(
                        thr,		                     // input image
                        blur,		                     // output image
                        Size(m_blurKernel,m_blurKernel), // Gaussian kernel-size
                        0,		                         // sigmaX 
                        0,		                         // sigmaY, default=0
                        BORDER_DEFAULT	                 // borderType
                    );
                }
                else
                {
                    // else just copy
                    blur = thr;
                }


                // -----
                // SNAKE ITERATION
                if (m_snakeOn)
                {   
                    // reinit if needed
                    reInitSnakeContour(15);

                    // get IplImage
                    snakeimg = IplImage(blur);

                    // snake interation
                    cvSnakeImage(
                        &snakeimg,                          // input image
                        m_snakeContour,                     // contour
                        m_snakeContourLength,               // contour length
                        &m_snakeAlpha,                      // alpha
                        &m_snakeBeta,                       // beta
                        &m_snakeGamma,                      // gamma
                        CV_VALUE,                           // single values
                        Size(m_snakeKernel,m_snakeKernel),  // snake kernel
                        m_snakeTermCriteria,                // termination crit.
                        0                                   // calc. gradient
                    );
                }

                // -----
                // WHAT TO SHOW
                switch (m_showPictureSnake)
                {
                    // original (color)
                    case 0:
                        cvtColor(img, out, CV_BGR2RGB);
                    break;

                    // threshold result
                    case 1:
                        cvtColor(thr, out, CV_GRAY2RGB);
                    break;

                    // blur result
                    case 2:
                        cvtColor(blur, out, CV_GRAY2RGB);
                    break;
                }


                // -----
                // RESULT
                if (m_showResultSnake)
                {
                    for (size_t i = 0; i < m_snakeContourLength; i++)
                    {
                        // points
                        circle(
                            out,
                            m_snakeContour[i],
                            3,
                            Scalar(0,255,0),
                            -1,
                            7,
                            0
                        );

                        // line segments
                        if (i > 0)
                        {
                            // draw line segments
                            line(
                                out,
                                m_snakeContour[i],
                                m_snakeContour[i-1],
                                Scalar(255,0,0),
                                1,
                                8,
                                0
                            );
                        }
                    }

                    // draw last line segment
                    line(
                        out,
                        m_snakeContour[0],
                        m_snakeContour[m_snakeContourLength-1],
                        Scalar(255,0,0),
                        1,
                        8,
                        0
                    );
                }

                // END Active Contour Model
                //**************************************************************
            break;
        }

        // set image and changed flag
        m_actualFrame.setImage(out);
        m_actualFrame.setChanged(true);

        // if rendering is on
        if (m_isRendering)
        {
            // save time values
            m_timePrev = m_timeNow;
            m_timeNow = getTime();

            // save current fps in queue
            m_fpsValues.push_front(getCurrentFPS());
        }
    }
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getTime
//
// Description: This method returns current time in
//              nanoseconds.
////////////////////////////////////////////////////////////
double TrackerModel::getTime()
{
    // structure to store time in
    struct timespec time;

    // get current time from monotonic clock
    clock_gettime(CLOCK_MONOTONIC, &time);

    return ((time.tv_sec * 1000000000)+time.tv_nsec);
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getAvgFPS
////////////////////////////////////////////////////////////
double TrackerModel::getAvgFPS()
{
    return m_avgFPS;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: calculateAvgFPS
//
// Description: This method calculates average of
//              of accumulated FPS values.
////////////////////////////////////////////////////////////
void TrackerModel::calculateAvgFPS()
{
    double sum = 0;

    // 
    for (int i = 0; i < m_fpsValues.size(); i++)
    {
        sum += m_fpsValues[i];
    }
    
    m_avgFPS = sum/m_fpsValues.size();
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: resetAvgFPS
//
// Description: This method clears FPS buffer and resets
//              the default -1 value.
////////////////////////////////////////////////////////////
void TrackerModel::resetAvgFPS()
{
    m_fpsValues.clear();
    m_avgFPS = -1;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getIsFileLoaded
////////////////////////////////////////////////////////////
bool TrackerModel::getIsFileLoaded()
{
    return m_cap.isOpened();
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getIsRendering
////////////////////////////////////////////////////////////
bool TrackerModel::getIsRendering()
{
    return m_isRendering;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setIsRendering
////////////////////////////////////////////////////////////
void TrackerModel::setIsRendering(bool render)
{
    m_isRendering = render;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getHoughFalseDets
////////////////////////////////////////////////////////////
int TrackerModel::getHoughFalseDets()
{
    return m_houghFalseDets;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setHoughFalseDets
////////////////////////////////////////////////////////////
void TrackerModel::setHoughFalseDets(int num)
{
    m_houghFalseDets = num;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getSnakeReInits
////////////////////////////////////////////////////////////
int TrackerModel::getSnakeReInits()
{
    return m_snakeReInits;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setSnakeReInits
////////////////////////////////////////////////////////////
void TrackerModel::setSnakeReInits(int num)
{
    m_snakeReInits = num;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getLoopVideo
////////////////////////////////////////////////////////////
bool TrackerModel::getLoopVideo()
{
    return m_loopVideo;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setLoopVideo
////////////////////////////////////////////////////////////
void TrackerModel::setLoopVideo(bool loop)
{
    m_loopVideo = loop;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getProcessMethod
////////////////////////////////////////////////////////////
int TrackerModel::getProcessMethod()
{
    return m_processMethod;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setProcessMethod
////////////////////////////////////////////////////////////
void TrackerModel::setProcessMethod(int method)
{
    m_processMethod = method;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getThresholdOn
////////////////////////////////////////////////////////////
bool TrackerModel::getThresholdOn()
{
    return m_thresholdOn;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setThresholdOn
////////////////////////////////////////////////////////////
void TrackerModel::setThresholdOn(bool threshold)
{
    m_thresholdOn = threshold;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getThresholdValue
////////////////////////////////////////////////////////////
double TrackerModel::getThresholdValue()
{
    return m_thresholdValue;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setThresholdValue
////////////////////////////////////////////////////////////
void TrackerModel::setThresholdValue(double value)
{
    m_thresholdValue = value;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getBlurOn
////////////////////////////////////////////////////////////
bool TrackerModel::getBlurOn()
{
    return m_blurOn;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setBlurOn
////////////////////////////////////////////////////////////
void TrackerModel::setBlurOn(bool blur)
{
    m_blurOn = blur;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getBlurKernel
////////////////////////////////////////////////////////////
int TrackerModel::getBlurKernel()
{
    return m_blurKernel;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setBlurKernel
//
// Description: This method sets blur kernel size,
//              whitch needs to be odd.
////////////////////////////////////////////////////////////
void TrackerModel::setBlurKernel(int kernel)
{
    m_blurKernel = kernel%2==0?kernel-1:kernel;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getHoughOn
////////////////////////////////////////////////////////////
bool TrackerModel::getHoughOn()
{
    return m_houghOn;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setHoughOn
////////////////////////////////////////////////////////////
void TrackerModel::setHoughOn(bool hough)
{
    m_houghOn = hough;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getHoughAccRes
////////////////////////////////////////////////////////////
int TrackerModel::getHoughAccRes()
{
    return m_houghAccRes;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setHoughAccRes
////////////////////////////////////////////////////////////
void TrackerModel::setHoughAccRes(int accres)
{
    m_houghAccRes = accres;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getHoughMinDist
////////////////////////////////////////////////////////////
int TrackerModel::getHoughMinDist()
{
    return m_houghMinDist;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setHoughMindDist
////////////////////////////////////////////////////////////
void TrackerModel::setHoughMinDist(int mindist)
{
    m_houghMinDist = mindist;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getHoughCannyParam
////////////////////////////////////////////////////////////
int TrackerModel::getHoughCannyParam()
{
    return m_houghCannyParam;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setHoughCannyParam
////////////////////////////////////////////////////////////
void TrackerModel::setHoughCannyParam(int cannyparam)
{
    m_houghCannyParam = cannyparam;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getHoughParam
////////////////////////////////////////////////////////////
int TrackerModel::getHoughParam()
{
    return m_houghParam;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setHoughParam
////////////////////////////////////////////////////////////
void TrackerModel::setHoughParam(int houghparam)
{
    m_houghParam = houghparam;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getHoughMinRad
////////////////////////////////////////////////////////////
int TrackerModel::getHoughMinRad()
{
    return m_houghMinRad;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setHoughMinRad
//
// Description: Minimum radius cannot be higher than
//              maximal.
////////////////////////////////////////////////////////////
void TrackerModel::setHoughMinRad(int minrad)
{
    if (minrad <= m_houghMaxRad)
    {
        m_houghMinRad = minrad;
    }
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getHoughMaxRad
////////////////////////////////////////////////////////////
int TrackerModel::getHoughMaxRad()
{
    return m_houghMaxRad;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setHoughMaxRad
//
// Description: Maximum radius cannot be lower than
//              minimal.
////////////////////////////////////////////////////////////
void TrackerModel::setHoughMaxRad(int maxrad)
{
    if (maxrad >= m_houghMinRad)
    {
        m_houghMaxRad = maxrad;
    }
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getSnakeOn
////////////////////////////////////////////////////////////
bool TrackerModel::getSnakeOn()
{
    return m_snakeOn;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setSnakeOn
////////////////////////////////////////////////////////////
void TrackerModel::setSnakeOn(bool snake)
{
    m_snakeOn = snake;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getSnakeAlpha
////////////////////////////////////////////////////////////
float TrackerModel::getSnakeAlpha()
{
    return m_snakeAlpha;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setSnakeAlpha
////////////////////////////////////////////////////////////
void TrackerModel::setSnakeAlpha(float alpha)
{
    m_snakeAlpha = alpha;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getSnakeBeta
////////////////////////////////////////////////////////////
float TrackerModel::getSnakeBeta()
{
    return m_snakeBeta;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setSnakeBeta
////////////////////////////////////////////////////////////
void TrackerModel::setSnakeBeta(float beta)
{
    m_snakeBeta = beta;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getSnakeGamma
////////////////////////////////////////////////////////////
float TrackerModel::getSnakeGamma()
{
    return m_snakeGamma;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setSnakeGamma
////////////////////////////////////////////////////////////
void TrackerModel::setSnakeGamma(float gamma)
{
    m_snakeGamma = gamma;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getSnakeKernel
////////////////////////////////////////////////////////////
int TrackerModel::getSnakeKernel()
{
    return m_snakeKernel;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setSnakeKernel
//
// Description: This method sets snake kernel size, which
//              must be odd.
////////////////////////////////////////////////////////////
void TrackerModel::setSnakeKernel(int kernel)
{
    m_snakeKernel = kernel%2==0?kernel-1:kernel;
}

////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getSnakeIters
////////////////////////////////////////////////////////////
int TrackerModel::getSnakeIters()
{
    return m_snakeTermCriteria.max_iter;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setSnakeIters
////////////////////////////////////////////////////////////
void TrackerModel::setSnakeIters(int iters)
{
    m_snakeTermCriteria.max_iter = iters;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getShowPictureHough
////////////////////////////////////////////////////////////
int TrackerModel::getShowPictureHough()
{
    return m_showPictureHough;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setShowPictureHough
////////////////////////////////////////////////////////////
void TrackerModel::setShowPictureHough(int picture)
{
    m_showPictureHough = picture;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getShowResultHough
////////////////////////////////////////////////////////////
bool TrackerModel::getShowResultHough()
{
    return m_showResultHough;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setShowResultHough
////////////////////////////////////////////////////////////
void TrackerModel::setShowResultHough(bool result)
{
    m_showResultHough = result;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getShowPictureSnake
////////////////////////////////////////////////////////////
int TrackerModel::getShowPictureSnake()
{
    return m_showPictureSnake;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setShowPictureSnake
////////////////////////////////////////////////////////////
void TrackerModel::setShowPictureSnake(int picture)
{
    m_showPictureSnake = picture;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getShowResultSnake
////////////////////////////////////////////////////////////
bool TrackerModel::getShowResultSnake()
{
    return m_showResultSnake;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setShowResultSnake
////////////////////////////////////////////////////////////
void TrackerModel::setShowResultSnake(bool result)
{
    m_showResultSnake = result;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getFilePath
//
// Description: This method returns the full file path.
////////////////////////////////////////////////////////////
string TrackerModel::getFilePath()
{
    return m_fileDir + "/" + m_fileName;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getFileDir
//
// Description: This method returns the directory of
//              loaded file.
////////////////////////////////////////////////////////////
string TrackerModel::getFileDir()
{
    return m_fileDir;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getFileName
//
// Description: This method returns the filename.
////////////////////////////////////////////////////////////
string TrackerModel::getFileName()
{
    return m_fileName;
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getWidth
//
// Description: This method returns the video width.
////////////////////////////////////////////////////////////
int TrackerModel::getWidth()
{
    return (int)m_cap.get(CV_CAP_PROP_FRAME_WIDTH);
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getWidth
//
// Description: This method returns the video height.
////////////////////////////////////////////////////////////
int TrackerModel::getHeight()
{
    return (int)m_cap.get(CV_CAP_PROP_FRAME_HEIGHT);
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getFPS
//
// Description: This method returns the original
//              framerate of video.
////////////////////////////////////////////////////////////
double TrackerModel::getFPS()
{
    return m_cap.get(CV_CAP_PROP_FPS);
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getCurrentFPS
//
// Description: This method returns the current FPS
//              calculated from previous and current
//              time.
////////////////////////////////////////////////////////////
double TrackerModel::getCurrentFPS()
{
    if (m_isRendering)
    {
        return 1000/((m_timeNow-m_timePrev)/1000000);
    }
    else
    {
        return 0;
    }
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getTimeAct
////////////////////////////////////////////////////////////
double TrackerModel::getTimeAct()
{
    return m_cap.get(CV_CAP_PROP_POS_MSEC);
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getFrameMax
////////////////////////////////////////////////////////////
int TrackerModel::getFrameMax()
{
    return m_cap.get(CV_CAP_PROP_FRAME_COUNT);
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: getFrameAct
////////////////////////////////////////////////////////////
int TrackerModel::getFrameAct()
{
    return (int)m_cap.get(CV_CAP_PROP_POS_FRAMES);
}


////////////////////////////////////////////////////////////
// Class name:  TrackerModel
// Method name: setFrameAct
////////////////////////////////////////////////////////////
void TrackerModel::setFrameAct(int num)
{
    m_cap.set(CV_CAP_PROP_POS_FRAMES, (double)num);
}
