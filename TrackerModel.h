////////////////////////////////////////////////////////////////////////////////
// Filename: TrackerModel.h
// Author:   Balazs KOVACS
// Year:     2010
//
// Description: Header of TrackerModel class.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef __TrackerModel__
#define __TrackerModel__

// OpenCV
#include <cv.h>
#include <highgui.h>

// STL
#include <string.h>
#include <time.h>
#include <deque>

// others
#include "OwnCVImage.h"

// namespaces
using namespace std;


////////////////////////////////////////////////////////////
// Class:       TrackerModel
//
// Description: TrackerModel gives the model of tracking
//              for the GUI.
////////////////////////////////////////////////////////////
class TrackerModel
{
    public:
        // default constructor
        TrackerModel();

        // load and close video files
        bool loadVideoFile(const string& fileDir, const string& fileName);
        void closeVideoFile();

        // process actual or next frame
        bool processThisFrame();
        bool processNextFrame();

        // actual image
        OwnCVImage m_actualFrame;


        // ==========
        // INFOS

        // get file name, dir and path
        string getFilePath();
        string getFileDir();
        string getFileName();
        
        // (re) initializing snake contours
        void initSnakeContour(int x0, int y0, int r, int num);
        void reInitSnakeContour(int thres);

        // get/set Hough statistics
        int getHoughFalseDets();
        void setHoughFalseDets(int num);

        // get/set snake statistics
        int getSnakeReInits();
        void setSnakeReInits(int num);

        // get video width and height
        int getWidth();
        int getHeight();

        // get original and current fps
        double getFPS();
        double getCurrentFPS();

        // functions related to average fps
        double getAvgFPS();
        void calculateAvgFPS();
        void resetAvgFPS();

        // get actual time
        double getTimeAct();

        // get/set actual and last frame numbers
        int getFrameMax();
        int getFrameAct();
        void setFrameAct(int num);


        // ==========
        // RENDERING
            
        // get/set if rendering is on
        bool getIsRendering();
        void setIsRendering(bool render);
        
        // get/set if looping video
        bool getLoopVideo();
        void setLoopVideo(bool loop);
        
        // get if file is loaded
        bool getIsFileLoaded();


        // ==========
        // PROCESSING

        // get/set processing method
        int getProcessMethod();
        void setProcessMethod(int method);

        // get/set if Hough-transform is on
        bool getHoughOn();
        void setHoughOn(bool hough);

        // get/set if snakes are on
        bool getSnakeOn();
        void setSnakeOn(bool snake);

        // get/set if thresholding is on    
        bool getThresholdOn();
        void setThresholdOn(bool threshold);

        // get/set thresholding value
        double getThresholdValue();
        void setThresholdValue(double value);

        // get/set bulrring is on
        bool getBlurOn();
        void setBlurOn(bool blur);

        // get/set blur kernel size
        int getBlurKernel();
        void setBlurKernel(int kernel);

        // get/set Hough's accumulator resolution
        int getHoughAccRes();
        void setHoughAccRes(int accres);

        // get/set Hough' minimum distance
        int getHoughMinDist();
        void setHoughMinDist(int mindist);

        // get/set Hough's Canny parameter
        int getHoughCannyParam();
        void setHoughCannyParam(int cannyparam);

        // get/set Hough's Hough parameter
        int getHoughParam();
        void setHoughParam(int houghparam);

        // get/set Hough's minimum radius
        int getHoughMinRad();
        void setHoughMinRad(int minrad);

        // get/set Hough's maximum radius
        int getHoughMaxRad();
        void setHoughMaxRad(int maxrad);
        
        // get/set snake alpha
        float getSnakeAlpha();
        void setSnakeAlpha(float alpha);

        // get/set snake beta
        float getSnakeBeta();
        void setSnakeBeta(float beta);

        // get/set snake gamma
        float getSnakeGamma();
        void setSnakeGamma(float gamma);

        // get/set snake iters
        int getSnakeIters();
        void setSnakeIters(int iters);

        // get/set snake kernel
        int getSnakeKernel();
        void setSnakeKernel(int kernel);

        // ==========
        // SHOW

        // get/set what to show (Hough)
        int getShowPictureHough();
        void setShowPictureHough(int picture);

        // get/set if draw circles
        bool getShowResultHough();
        void setShowResultHough(bool result);

        // get/set what to show (snakes)
        int getShowPictureSnake();
        void setShowPictureSnake(int picture);

        // get/set if draw snakes
        bool getShowResultSnake();
        void setShowResultSnake(bool result);

        
    private:

        // video capturer
        cv::VideoCapture    m_cap;

        // processing method
        int m_processMethod;

        // statistics
        int m_houghFalseDets;
        int m_snakeReInits;

        // ==========
        // INFOS

        // file directory and name
        string m_fileDir;
        string m_fileName;

        bool m_isRendering;
        bool m_loopVideo;

        // fps variables
        deque<double> m_fpsValues;
        double m_avgFPS;

        // time variables
        double m_timePrev;
        double m_timeNow;

        // get actual time in nanoseconds
        double getTime();

        // threshold variables
        bool m_thresholdOn;
        double m_thresholdValue;    

        // blur variables
        bool m_blurOn;
        int m_blurKernel;

        // Hough transform and Canny variables
        bool m_houghOn;
        int m_houghAccRes;
        int m_houghMinDist;
        int m_houghCannyParam;
        int m_houghParam;
        int m_houghMinRad;
        int m_houghMaxRad;

        // snake variables
        bool m_snakeOn;
        CvPoint* m_snakeContour;
        int m_snakeContourLength;
        int m_snakeContourRadius;
        float m_snakeAlpha;
        float m_snakeBeta;
        float m_snakeGamma;
        float m_snakeKernel;
        CvTermCriteria m_snakeTermCriteria;


        // ==========
        // SHOW

        // what to show
        int m_showPictureHough;
        bool m_showResultHough;

        // draw results
        int m_showPictureSnake;
        bool m_showResultSnake;
};

#endif
