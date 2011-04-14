////////////////////////////////////////////////////////////////////////////////
// Filename: MainFrame.cpp
// Author:   Balazs KOVACS
// Year:     2010
//
// Description: Imlementation of MainFrame class.
//
////////////////////////////////////////////////////////////////////////////////

// STL
#include <string.h>
#include <math.h>
#include <iostream>
#include <deque>

// wxWidgets
#include <wx/wx.h>

// other
#include "MainFrame.h"
#include "gui.h"
#include "images/applicationicon.xpm"

// namespaces
using namespace std;

////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: MainFrame
//
// Description: MainFrame class default constructor
////////////////////////////////////////////////////////////
MainFrame::MainFrame(wxWindow* parent, TrackerModel* model)
    : MainFrameBase(parent)
{
    // protram icon
    SetIcon(applicationicon_xpm);

    // setting model
    m_model = model;

    // resultframe to null
    m_resultFrame = NULL;
    
    // initialize fps queue
    m_fpsQueue.push_front(0);

    // GUI to defualt values
    guiReset();
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: activateRenderLoop
//
// Description: Switches rendering on or off.
////////////////////////////////////////////////////////////
void MainFrame::activateRenderLoop(bool on)
{
    // if not rendering and want to switch on
    if(on and !m_model->getIsRendering())
    {
        // connect evt. handler
        Connect( wxID_ANY, wxEVT_IDLE, wxIdleEventHandler(MainFrame::onIdle) );

        // enable rendering in model
        m_model->setIsRendering(true);
    }
    // if rendering and want to switch off
    else if(!on and m_model->getIsRendering())
    {
        // disconnect evt. handler
        Disconnect( wxEVT_IDLE, wxIdleEventHandler(MainFrame::onIdle) );

        // disable rendering in model
        m_model->setIsRendering(false);
    }
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onIdle
//
// Description: Idle event handler (render loop).
////////////////////////////////////////////////////////////
void MainFrame::onIdle(wxIdleEvent& event)
{
    // if rendering
    if(m_model->getIsRendering())
    {
        // process next frame
        m_model->processNextFrame();
       
        // update GUI and video frame
        guiUpdate();
        m_resultFrame->m_imagePanel->paintNow();
        
        // render continously
        event.RequestMore();
    }
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: guiReset
//
// Description: Set default GUI values.
////////////////////////////////////////////////////////////
void MainFrame::guiReset()
{
    // file name init
    m_staticTextFileValue->SetLabel(wxT("-"));
    m_staticTextFileValue->Enable(false);
    
    // resolution init
    m_staticTextResValue->SetLabel(wxT("-"));
    m_staticTextResValue->Enable(false);

    // framerate init
    m_staticTextFramerateValue->SetLabel(wxT("-"));
    m_staticTextFramerateValue->Enable(false);

    // frame counter init   
    m_staticTextFramesValue->SetLabel(wxT("-/-"));
    m_staticTextFramesValue->Enable(false);
    
    // time counter init
    m_staticTextTimeValue->SetLabel(wxT("--:--:--/--:--:--"));
    m_staticTextTimeValue->Enable(false);    

    // current fps init
    m_staticTextCurrentFPSValue->SetLabel(wxT("-"));
    m_staticTextCurrentFPSValue->Enable(false);

    // hough statistics init
    m_staticTextHoughStatAvgFPS->SetLabel(wxT("-"));
    m_staticTextHoughStatAvgFPS->Enable(false);

    m_staticTextHoughStatFalseDets->SetLabel(wxT("-"));
    m_staticTextHoughStatFalseDets->Enable(false);

    // snake statsistics init
    m_staticTextSnakeStatAvgFPS->SetLabel(wxT("-"));
    m_staticTextSnakeStatAvgFPS->Enable(false);

    m_staticTextSnakeStatReInits->SetLabel(wxT("-"));
    m_staticTextSnakeStatReInits->Enable(false);
    
    // loop checkbox unchecked
    m_checkBoxLoop->Enable(false);
    
    // frame slider at zero, and disabled
    m_sliderFrames->SetValue(0);
    m_sliderFrames->Enable(false);
    
    // menuitems disable (close, start, pause)
    m_menuFile->FindItemByPosition(1)->Enable(false);
    m_menuTrack->FindItemByPosition(0)->Enable(false);
    m_menuTrack->FindItemByPosition(1)->Enable(false);
    
    // toolbar buttons disable (close, start, pause)
    m_toolBar->EnableTool(wxID_CLOSETOOL, false);
    m_toolBar->EnableTool(wxID_STARTTOOL, false);
    m_toolBar->EnableTool(wxID_PAUSETOOL, false);

    // update GUI once
    guiUpdateOnce();
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: guiUpdateOnce
//
// Description: Updates GUI while not in render loop.
//              These settings don't need to be updated on
//              every frame, only when changed (like 
//              setting values)
////////////////////////////////////////////////////////////
void MainFrame::guiUpdateOnce()
{
    // -----
    // depending on process method show only
    // panels and tabs
    int method = m_model->getProcessMethod();
    switch (method)
    {
        // 'Hough' case
        case 0:
            // show Hough tabs, hide snake tabs
            m_panelHough->Show();
            m_panelSnake->Hide();
            m_panelTrackHough->Show();
            m_panelTrackSnake->Hide();

            // show 'Canny' panel
            m_panelEdge->Show();

            // show Hough stas, hide snake stats
            m_panelHoughStat->Show();
            m_panelSnakeStat->Hide();
        break;
        
        // 'snake' case
        case 1:
            // show only snake tabs, hide Hough tabs
            m_panelSnake->Show();
            m_panelHough->Hide();
            m_panelTrackSnake->Show();
            m_panelTrackHough->Hide();

            // hide 'Canny' panel
            m_panelEdge->Hide();

            // show snake stats, hide Hough stats
            m_panelSnakeStat->Show();
            m_panelHoughStat->Hide();
        break;
    }

    // -----
    // set threshold checboxes' state and
    // threshold value from model
    bool threshold = m_model->getThresholdOn()?true:false;
    m_checkBoxHoughThreshold->SetValue(threshold);
    m_checkBoxSnakeThreshold->SetValue(threshold);

    int thresholdvalue = m_model->getThresholdValue();
    m_sliderThresholdValue->SetValue(thresholdvalue);

    // -----
    // set blur checkboxes' state and
    // blur kernel size from model
    bool blur = m_model->getBlurOn()?true:false;
    m_checkBoxHoughBlur->SetValue(blur);
    m_checkBoxSnakeBlur->SetValue(blur);
    
    int kernelsize = m_model->getBlurKernel();
    m_sliderBlurKernel->SetValue(kernelsize);

    // -----
    // enable 'Hough' checkbox on 'Tracking options' tab 
    // depending on model
    bool hough = m_model->getHoughOn()?true:false;
    m_checkBoxHoughHough->SetValue(hough);

    // -----
    // enable 'snake' checbox on 'Tracking options' tab
    // depending on model
    bool snake = m_model->getSnakeOn()?true:false;
    m_checkBoxSnakeSnake->SetValue(snake);

    // -----
    // set radio button value on Hough's 'Tracking options' tab
    // from model (what to show on Hough result)
    int hough_show = m_model->getShowPictureHough();
    m_radioBoxHoughShow->SetSelection(hough_show);

    // -----
    // enable/disable unique radio buttons at Hough transform
    bool hough_show_threshold = m_model->getThresholdOn()?true:false;
    m_radioBoxHoughShow->Enable(1, hough_show_threshold);
    m_radioBoxSnakeShow->Enable(1, hough_show_threshold);
    
    bool hough_show_blur = m_model->getBlurOn()?true:false;
    m_radioBoxHoughShow->Enable(2, hough_show_blur);
    m_radioBoxSnakeShow->Enable(2, hough_show_blur);

    bool hough_show_hough = m_model->getHoughOn()?true:false;
    m_radioBoxHoughShow->Enable(3, hough_show_hough);

    // ----
    // set 'Show detected circles' checkbox to desired state
    bool houghresult = m_model->getShowResultHough()?true:false;
    m_checkBoxHoughShowResult->SetValue(houghresult);
    m_checkBoxHoughShowResult->Enable(hough_show_hough);

    // ---
    // Hough transform's parameters' values from model
    int hough_accres = m_model->getHoughAccRes();
    m_sliderHoughAccRes->SetValue(hough_accres);

    int hough_mindist = m_model->getHoughMinDist();
    m_sliderHoughMinDist->SetValue(hough_mindist);

    int hough_canny = m_model->getHoughCannyParam();
    m_sliderHoughCanny->SetValue(hough_canny);

    int hough_param = m_model->getHoughParam();
    m_sliderHoughParam->SetValue(hough_param);

    int hough_minrad = m_model->getHoughMinRad();
    m_sliderHoughMinRad->SetValue(hough_minrad);

    int hough_maxrad = m_model->getHoughMaxRad();
    m_sliderHoughMaxRad->SetValue(hough_maxrad);

    // -----
    // set radio button value on snake's 'Tracking options' tab
    // from model (what to show on snake result)
    int snake_show = m_model->getShowPictureSnake();
    m_radioBoxSnakeShow->SetSelection(snake_show);

    // ----
    // set 'Show snakes' checkbox to desired state
    bool snakeresult = m_model->getShowResultSnake()?true:false;
    m_checkBoxSnakeShowResult->SetValue(snakeresult);
    m_checkBoxSnakeShowResult->Enable(snake);

    // ---
    // snakes's parameters' values from model
    int snake_iter = m_model->getSnakeIters();
    m_sliderSnakeIter->SetValue(snake_iter);

    int snake_kernel = m_model->getSnakeKernel();
    m_sliderSnakeKernel->SetValue(snake_kernel);

    float snake_alpha = m_model->getSnakeAlpha();
    wxString alpha_string;
    alpha_string << snake_alpha;
    m_textCtrlSnakeAlpha->SetValue(alpha_string);

    float snake_beta = m_model->getSnakeBeta();
    wxString beta_string;
    beta_string << snake_beta;
    m_textCtrlSnakeBeta->SetValue(beta_string);

    float snake_gamma = m_model->getSnakeGamma();
    wxString gamma_string;
    gamma_string << snake_gamma;
    m_textCtrlSnakeGamma->SetValue(gamma_string);

    // -----
    // set loop video checbox state from model
    bool loop = m_model->getLoopVideo()?true:false;
    m_checkBoxLoop->SetValue(loop);

    // if there's a file loaded
    if (m_model->getIsFileLoaded())
    {
        // set file name to label and full path to tooltip
        wxString nameString(m_model->getFileName().c_str(), wxConvUTF8);
        m_staticTextFileValue->SetLabel(nameString);
            
        wxString pathString(m_model->getFilePath().c_str(), wxConvUTF8);
        m_staticTextFileValue->SetToolTip(pathString);
            
        m_staticTextFileValue->Enable(true);

        // -----
        // set width and height information from model
        // and format it
        int w = m_model->getWidth();
        int h = m_model->getHeight();
            
        wxString infoString;
        infoString << w << wxT("x") << h << wxT(" pixels");
        m_staticTextResValue->SetLabel(infoString);
            
        m_staticTextResValue->Enable(true);

        // -----
        // set original framerate information from model
        double of = m_model->getFPS();
        
        wxString fpsString;
        fpsString << of << wxT(" FPS");

        m_staticTextFramerateValue->SetLabel(fpsString);
        m_staticTextFramerateValue->Enable(true);

        // -----
        // activate slider (but no value change)
        int framemax = m_model->getFrameMax();
        m_sliderFrames->SetRange(0, framemax-1);
        m_sliderFrames->Enable(true);

        // -----
        // enable close button on toolbar
        m_menuFile->FindItemByPosition(1)->Enable(true);
        m_toolBar->EnableTool(wxID_CLOSETOOL, true);

        // -----
        // enable Hough statistics' labels
        m_staticTextHoughStatAvgFPS->Enable(true);
        m_staticTextHoughStatFalseDets->Enable(true);

        // -----
        // enable snake statistics' labels
        m_staticTextSnakeStatAvgFPS->Enable(true);
        m_staticTextSnakeStatReInits->Enable(true);

        // -----        
        // only enable what's not need to be changed
        m_staticTextCurrentFPSValue->Enable(true);
        m_staticTextFramesValue->Enable(true);
        m_staticTextTimeValue->Enable(true);
        m_checkBoxLoop->Enable(true);
    }
}



////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: guiUpdate
//
// Description: This function updates GUI values which
//              need to be changed while rendering
////////////////////////////////////////////////////////////
void MainFrame::guiUpdate()
{
    // -----
    // if there's a file loaded
    if (m_model->getIsFileLoaded())
    {

        // -----
        // format 'Current FPS' value using the average of
        // the last 5 values
        double cf2 = 0;
        if (m_model->getIsRendering())
        {
            double cf = m_model->getCurrentFPS();

            // if queue is 'full'
            if (m_fpsQueue.size() > 4)
            {
                // pop one element from back
                m_fpsQueue.pop_back();
            }
            // then push the new one front
            m_fpsQueue.push_front(cf);

            // calculate average
            double sum = 0;
            for (int i = 0; i < m_fpsQueue.size(); i++)
            {
                sum += m_fpsQueue[i];
            }
        
            cf2 = sum/m_fpsQueue.size();
        }
        
        wxString cfString;
        cfString << (int)(cf2>0?cf2:0);
        m_staticTextCurrentFPSValue->SetLabel(cfString);
        
        // -----
        // set frame counter from model
        int frameact = m_model->getFrameAct();
        int framemax = m_model->getFrameMax();
        
        wxString frameString;
        frameString << frameact << wxT("/") << (framemax-1);
        m_staticTextFramesValue->SetLabel(frameString);
        
        // -----
        // set time counter from model
        // with proper formatting
        double of = m_model->getFPS();
        double timeact = m_model->getTimeAct();
        double timemax = (framemax/of)*1000;

        wxString timeString;
        timeString << getFormattedTime(timeact) << wxT("/") << getFormattedTime(timemax);
        m_staticTextTimeValue->SetLabel(timeString);
        
        // -----
        // set slider value to actual frame
        m_sliderFrames->SetValue(frameact);

        // -----
        // update Hough's false detection number
        wxString false_dets;
        false_dets << m_model->getHoughFalseDets();
        m_staticTextHoughStatFalseDets->SetLabel(false_dets);

        // ------
        // update snake's reinitialization number
        wxString re_inits;
        re_inits << m_model->getSnakeReInits();
        m_staticTextSnakeStatReInits->SetLabel(re_inits);

        // -----
        // update calculated average fps (when paused or loop ended)
        double avg = m_model->getAvgFPS();
        wxString avg_string;
        if (avg == -1)
        {
            avg_string = wxT("-");
        }
        else
        {
            avg_string << avg;
        }

        m_staticTextHoughStatAvgFPS->SetLabel(avg_string);
        m_staticTextSnakeStatAvgFPS->SetLabel(avg_string);
        
        // ------
        // if rendering finished (e.g. video ended and no loop on)
        if (!m_model->getIsRendering())
        {
            // enable 'Start' buttons on menu and toolbar
            m_menuTrack->FindItemByPosition(0)->Enable(true);
            m_toolBar->EnableTool(wxID_STARTTOOL, true);
            
            // disable 'Pause' buttons on menu and toolbar
            m_menuTrack->FindItemByPosition(1)->Enable(false);
            m_toolBar->EnableTool(wxID_PAUSETOOL, false);
        }
        // if still rendering
        else
        {
            // disable 'Start' buttons on menu and toolbar
            m_menuTrack->FindItemByPosition(0)->Enable(false);
            m_toolBar->EnableTool(wxID_STARTTOOL, false);
               
            // enable 'Pause' buttons on menu and toolbar
            m_menuTrack->FindItemByPosition(1)->Enable(true);
            m_toolBar->EnableTool(wxID_PAUSETOOL, true);
        }
    }   
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: getFormattedTime
//
// Description: This function returns the time formatted
//              as mm:ss:cc calculated from argument msec.
////////////////////////////////////////////////////////////
wxString MainFrame::getFormattedTime(double msec)
{
    // calculate values
    int centiseconds = (int)(msec/10)%100;
    int seconds = (int)(msec/1000)%60;
    int minutes = (int)(msec/60000);

    // format string    
    wxString back;
//    wxChar* format = new wxChar("%02d:%02d:%02d");
//    back.Printf(format, minutes, seconds, centiseconds);
//    back + wxString::Format("%02d", minutes) + wxT(":") + wxString::Format("%02d", seconds) + wxT(":") + wxString::Format("%02d", centiseconds);
    back << minutes << wxT(":") << seconds << wxT(":") << centiseconds;
 
    // return value   
    return back;   
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onRadioMethod
//
// Description: This method reprocesses current frame and
//              updates the video frame
////////////////////////////////////////////////////////////
void MainFrame::videoFrameUpdate()
{
    // if there's file loaded
    if (m_model->getIsFileLoaded())
    {
        // reprocess current frame
        m_model->processThisFrame();
        m_resultFrame->m_imagePanel->paintNow();
    }
}



////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onRadioMethod
//
// Description: 'Tracking method' radio button's
//              event handler. (on 'General' tab)
////////////////////////////////////////////////////////////
void MainFrame::onRadioMethod(wxCommandEvent& event)
{
    // set method in model
    m_model->setProcessMethod(m_radioBoxMethod->GetSelection());

    // update GUI
    guiUpdateOnce();

    // reprocess actual image and update video frame
    videoFrameUpdate();
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onButtonOpen
//
// Description: 'Open' button's event handler (on menu
//              and toolbar).
////////////////////////////////////////////////////////////
void MainFrame::onButtonOpen(wxCommandEvent& event)
{
    // wildcards of 'open file' dialog
    wxString wildcard =
    wxT("AVI files (*.avi)|*.avi|All files (*.*)|*.*");

	// creating an 'open file' dialog
    wxFileDialog* OpenDialog = new wxFileDialog(
        this,                               // parent window
        wxT("Choose a file to open..."),    // message (title)
        wxEmptyString,                      // default dir
        wxEmptyString,                      // default file
        wildcard,                           // wildcard
        wxOPEN|wxFILE_MUST_EXIST,           // file must exist
        wxDefaultPosition                   // place on default position
    );
 
    // -----
    // if user clicked OK
	if (OpenDialog->ShowModal() == wxID_OK)
	{
        // -----
	    // get file dir and name
	    wxString wxDir = OpenDialog->GetDirectory();
        string stdDir = string(wxDir.mb_str());
        
        wxString wxName = OpenDialog->GetFilename();
        string stdName = string(wxName.mb_str());

        // ----
        // if load in model succeeded
        if (m_model->loadVideoFile(stdDir, stdName))
        {          
            // -----
            // destroy previous video frame
            if (m_resultFrame != NULL) 
            {
                m_resultFrame->Destroy();
            }
            
            // -----
            // create a new video frame
            m_resultFrame = new VideoFrame(this, &m_model->m_actualFrame);

            // ----
            // set video frame properties
            m_resultFrame->SetTitle(wxT("Tracking Result - ")+wxName);

            wxSize size = wxSize(m_model->getWidth()+10, m_model->getHeight()+10);
            m_resultFrame->SetSize(size);
            m_resultFrame->SetMinSize(size);
            m_resultFrame->SetMaxSize(size);
            
            // -----
            // show video frame
            m_resultFrame->Show();

            // -----
            // process next frame
            m_model->processNextFrame();
            m_resultFrame->m_imagePanel->paintNow();
            
            // -----
            // update GUI
            guiUpdate();
            guiUpdateOnce();
        }
        // if something went wrong while loading in model
        else
        {
            // -----
            // display error
            wxMessageBox(
                wxT("Incompatible video file."),
                wxT("Load error."),
                wxOK|wxICON_EXCLAMATION,
                this
            );
        }
	}
 
	// clean up after ourselves
	OpenDialog->Destroy();
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onButtonClose
//
// Description: 'Close' button's event handler on menu
//              and toolbar
////////////////////////////////////////////////////////////
void MainFrame::onButtonClose(wxCommandEvent& event)
{
    // close file in model
    m_model->closeVideoFile();
    
    // reset GUI values
    guiReset();
       
    // destroy video frame
    m_resultFrame->Destroy();
    m_resultFrame = NULL;
    
    // disable render loop
    activateRenderLoop(false);
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onButtonExit
//
// Description: 'Exit' button's event handler (on menu
//              and toolbar).
////////////////////////////////////////////////////////////
void MainFrame::onButtonExit(wxCommandEvent& event)
{
    // close application
    Close();
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onSliderFrames
//
// Description: Frame slider's event handler
////////////////////////////////////////////////////////////
void MainFrame::onSliderFrames(wxScrollEvent& event)
{
    // set desired frame in model
    m_model->setFrameAct(m_sliderFrames->GetValue());

    // process next frame
    m_model->processNextFrame();
    m_resultFrame->m_imagePanel->paintNow();
    
    // update GUI
    guiUpdate();
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onSliderThresholdValue
//
// Description: 'Threshold value' slider event handler
//              (on 'Threshold' tab).
////////////////////////////////////////////////////////////
void MainFrame::onSliderThresholdValue(wxScrollEvent& event)
{
    // set threshold value in model
    m_model->setThresholdValue(m_sliderThresholdValue->GetValue());
    
    // update GUI
    guiUpdateOnce();
    
    // reprocess actual image and update video frame
    videoFrameUpdate();
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onSliderBlurKernel
//
// Description: 'KernelSize' slider's event handler (on
//              'Gaussian blur' tab).
////////////////////////////////////////////////////////////
void MainFrame::onSliderBlurKernel(wxScrollEvent& event)
{
    // set blur kernel size in model
    m_model->setBlurKernel(m_sliderBlurKernel->GetValue());
    
    // update GUI
    guiUpdateOnce();
    
    // reprocess actual image and update video frame
    videoFrameUpdate();
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onSliderHoughCanny
//
// Description: 'Canny parameter' slider's event handler
//              (on 'Canny' tab).
////////////////////////////////////////////////////////////
void MainFrame::onSliderHoughCanny(wxScrollEvent& event)
{
    // set Canny-parameter value in model
    m_model->setHoughCannyParam(m_sliderHoughCanny->GetValue());
    
    // update GUI
    guiUpdateOnce();
    
    // reprocess actual image and update video frame
    videoFrameUpdate();
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onSliderHoughAccRes
//
// Description: 'Accumulator resolution' silder's event
//              handler (on 'Hough transform' tab).
////////////////////////////////////////////////////////////
void MainFrame::onSliderHoughAccRes(wxScrollEvent& event)
{
    // set accumulator resuliton value in model
    m_model->setHoughAccRes(m_sliderHoughAccRes->GetValue());
    
    // update GUI
    guiUpdateOnce();
    
    // reprocess actual image and update video frame
    videoFrameUpdate();
}

////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onSliderHoughMinDist
//
// Description: ...
////////////////////////////////////////////////////////////
void MainFrame::onSliderHoughMinDist(wxScrollEvent& event)
{
    // set mindist value in model
    m_model->setHoughMinDist(m_sliderHoughMinDist->GetValue());
    
    // update GUi
    guiUpdateOnce();
    
    // reprocess actual image and update video frame
    videoFrameUpdate();
}

////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onSliderHoughParam
//
// Description: 'Hough paramtere' slider's event handler
//              (on 'Hough transform' tab).
////////////////////////////////////////////////////////////
void MainFrame::onSliderHoughParam(wxScrollEvent& event)
{
    // set hough parameter in model
    m_model->setHoughParam(m_sliderHoughParam->GetValue());
    
    // update GUI
    guiUpdateOnce();
    
    // reprocess actual image and update video frame
    videoFrameUpdate();
}

////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onSliderHoughMinRad
//
// Description: 'Min radius' slider's event handler
//              (on 'Hough transform' tab).
////////////////////////////////////////////////////////////
void MainFrame::onSliderHoughMinRad(wxScrollEvent& event)
{
    // set minimum radius parameter in model
    m_model->setHoughMinRad(m_sliderHoughMinRad->GetValue());
    
    // update GUI
    guiUpdateOnce();
    
    // reprocess actual image and update video frame
    videoFrameUpdate();
}

////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onSliderHoughMaxRad
//
// Description: 'Max radius' slider's event handler
//              (on 'Hough transform' tab).
////////////////////////////////////////////////////////////
void MainFrame::onSliderHoughMaxRad(wxScrollEvent& event)
{
    // set maximum radius paramter in model
    m_model->setHoughMaxRad(m_sliderHoughMaxRad->GetValue());
    
    // update GUI
    guiUpdateOnce();
    
    // reprocess actual image and update video frame
    videoFrameUpdate();
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onSliderSnakeIter
//
// Description: 'Iterations' slider's event handler
//              (on 'Active Contour' tab).
////////////////////////////////////////////////////////////
void MainFrame::onSliderSnakeIter(wxScrollEvent& event)
{
    // set value in model
    m_model->setSnakeIters(m_sliderSnakeIter->GetValue());
    
    // update GUI
    guiUpdateOnce();

/*    
    // reprocess actual image and update video frame
    videoFrameUpdate();
*/
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onSliderSnakeKernel
//
// Description: 'Window Size' slider's event handler (on
//              'Active Contour' tab).
////////////////////////////////////////////////////////////
void MainFrame::onSliderSnakeKernel(wxScrollEvent& event)
{
    // set blur kernel size in model
    m_model->setSnakeKernel(m_sliderSnakeKernel->GetValue());
    
    // update GUI
    guiUpdateOnce();

/*    
    // reprocess actual image and update video frame
    videoFrameUpdate();
*/
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onTextCtrlSnakeAlpha
//
// Description: 'Alpha' textcontrol's event handler
//              (on 'Active Contour' tab).
////////////////////////////////////////////////////////////
void MainFrame::onTextCtrlSnakeAlpha(wxCommandEvent& event)
{
    // get value in wxString
    wxString value = m_textCtrlSnakeAlpha->GetValue();

    // try to convert to number
    double number;    
    if (value.ToDouble(&number))
    {
        // if succeeded, set parameter in model
        m_model->setSnakeAlpha((float)number);
    }
    else
    {
        // if not a valid number, show error.
        wxMessageBox(
            wxT("Not a valid number."),
            wxT("Value error."),
            wxOK|wxICON_EXCLAMATION,
            this
        );
    }
    
    // update GUI
    guiUpdateOnce();
    
/*
    // reprocess actual image and update video frame
    videoFrameUpdate();
*/
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onTextCtrlSnakeBeta
//
// Description: 'Beta' textcontrol's event handler
//              (on 'Active Contour' tab).
////////////////////////////////////////////////////////////
void MainFrame::onTextCtrlSnakeBeta(wxCommandEvent& event)
{
    // get value in wxString
    wxString value = m_textCtrlSnakeBeta->GetValue();

    // try to convert to number
    double number;
    if (value.ToDouble(&number))
    {
        // if succeeded, set value in model
        m_model->setSnakeBeta((float)number);
    }
    else
    {
        // if not a valid number, display error
        wxMessageBox(
            wxT("Not a valid number."),
            wxT("Value error."),
            wxOK|wxICON_EXCLAMATION,
            this
        );
    }

    // update GUI
    guiUpdateOnce();

/*    
    // reprocess actual image and update video frame
    videoFrameUpdate();
*/
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onTextCtrlSnakeGamma
//
// Description: 'Gamma' textcontrol's event handler
//              (on 'Active Contour' tab).
////////////////////////////////////////////////////////////
void MainFrame::onTextCtrlSnakeGamma(wxCommandEvent& event)
{
    // get value in wxString
    wxString value = m_textCtrlSnakeGamma->GetValue();

    // try to convert to number
    double number;
    if (value.ToDouble(&number))
    {
        // if succeeded, set value in model
        m_model->setSnakeGamma((float)number);
    }
    else
    {
        // if not a valid number, display error
        wxMessageBox(
            wxT("Not a valid number."),
            wxT("Value error."),
            wxOK|wxICON_EXCLAMATION,
            this
        );
    }
    
    // update GUI
    guiUpdateOnce();

/*
    // reprocess actual image and update video frame
    videoFrameUpdate();
*/
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onButtonStart
//
// Description: 'Start' button's event handler (on
//              menu and toolbar).
////////////////////////////////////////////////////////////
void MainFrame::onButtonStart(wxCommandEvent& event)
{
    // enable rendering
    activateRenderLoop(true);

    // reset Hough and snake statistics
    m_model->setHoughFalseDets(0);
    m_model->setSnakeReInits(0);

    // reset average fps
    m_model->resetAvgFPS();
    
    // update GUI
    guiUpdate();
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onButtonPause
//
// Description: 'Stop' button's event handler (on
//              menu and toolbar).
////////////////////////////////////////////////////////////
void MainFrame::onButtonPause(wxCommandEvent& event)
{
    // disable rendering
    activateRenderLoop(false);

    // calculate average fps
    m_model->calculateAvgFPS();
    
    // update GUI
    guiUpdate();
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onButtonAbout
//
// Description: 'About' button's event handler (on menu).
////////////////////////////////////////////////////////////
void MainFrame::onButtonAbout(wxCommandEvent& event)
{
    wxString line1 = wxT("Pupil Tracker Demo application - v1.1\n\n");
    wxString line2 = wxT("Author: Balazs KOVACS\n\n");
    wxString line3 = wxT("Budapest University of Technology and Economics (BUTE)\n");
    wxString line4 = wxT("Faculty of Electrical Engineering and Informatics (VIK)\n");
    wxString line5 = wxT("Department of Measurement and Information Systems (MIT)\n\n");
    wxString line6 = wxT("2010");

    wxString aboutstring = line1+line2+line3+line4+line5+line6;

    wxMessageBox(
        aboutstring,
        wxT("About"),
        wxOK,
        this
    );
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onBoxLoopEnable
//
// Description: 'Loop' checbox event handler.
////////////////////////////////////////////////////////////
void MainFrame::onBoxLoopEnable(wxCommandEvent& event)
{
    // change depending on model
    if (m_model->getLoopVideo())
    {
        m_model->setLoopVideo(false);
    }
    else
    {
        m_model->setLoopVideo(true);
    }

    // update GUI
    guiUpdateOnce();
    guiUpdate();
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onBoxThresholdEnable
//
// Description: 'Threshold' checkbox event handler
//              (on 'Tracking options' tab).
////////////////////////////////////////////////////////////
void MainFrame::onBoxThresholdEnable(wxCommandEvent& event)
{
    // change depending on model
    if (m_model->getThresholdOn())
    {
        m_model->setThresholdOn(false);

        // set 'Show' radioboxes if needed
        if (m_model->getShowPictureHough() == 1
            || m_model->getShowPictureSnake() == 1)
        {
            m_model->setShowPictureHough(0);
            m_model->setShowPictureSnake(0);
        }
    }
    else
    {
        m_model->setThresholdOn(true);
    }

    // update GUI
    guiUpdateOnce();

    // reprocess actual image and update video frame
    videoFrameUpdate();
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onBoxBlurEnable
//
// Description: 'Blur' checkbox event handler
//              (on 'Tracking options' tab).
////////////////////////////////////////////////////////////
void MainFrame::onBoxBlurEnable(wxCommandEvent& event)
{
    // change depending on model
    if (m_model->getBlurOn())
    {
        m_model->setBlurOn(false);

        // set 'Show' radioboxes if needed
        if (m_model->getShowPictureHough() == 2
            || m_model->getShowPictureSnake() == 2)
        {
            m_model->setShowPictureHough(0);
            m_model->setShowPictureSnake(0);
        }
    }
    else
    {
        m_model->setBlurOn(true);
    }

    // update GUI
    guiUpdateOnce();

    // reprocess actual image and update video frame
    videoFrameUpdate();
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onBoxHoughEnable
//
// Description: 'Hough' checkbox event handler
//              (on 'Tracking options' tab).
////////////////////////////////////////////////////////////
void MainFrame::onBoxHoughEnable(wxCommandEvent& event)
{
    if (m_model->getHoughOn())
    {
        m_model->setHoughOn(false);
        m_model->setShowResultHough(false);

        // set 'Show' radiobox if needed
        if (m_model->getShowPictureHough() == 3)
        {
            m_model->setShowPictureHough(0);
        }
    }
    else
    {
        m_model->setHoughOn(true);
    }

    // update GUI
    guiUpdateOnce();

    // reprocess actual image and update video frame
    videoFrameUpdate();
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onBoxHougResultEnable
//
// Description: 'Show detected circles' checkbox event
//              handler (on 'Tracking options' tab).
////////////////////////////////////////////////////////////
void MainFrame::onBoxHoughResultEnable(wxCommandEvent& event)
{
    // change depending on model
    if (m_model->getShowResultHough())
    {
        m_model->setShowResultHough(false);
    }
    else
    {
        m_model->setShowResultHough(true);
    }

    // update GUI
    guiUpdateOnce();

    // reprocess actual image and update video frame
    videoFrameUpdate();
}

////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onBoxSnakeResultEnable
//
// Description: 'Show snakes' checbox event handler
//              (on 'Tracking options' tab).
////////////////////////////////////////////////////////////
void MainFrame::onBoxSnakeResultEnable(wxCommandEvent& event)
{
    // change depeding on model
    if (m_model->getShowResultSnake())
    {
        m_model->setShowResultSnake(false);
    }
    else
    {
        m_model->setShowResultSnake(true);
    }

    // update GUI
    guiUpdateOnce();

    // reprocess actual image and update video frame
    videoFrameUpdate();
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onRadioHoughShow
//
// Description: 'Show' radiobox event handler
//              (on Hough's 'Tracking options' tab).
////////////////////////////////////////////////////////////
void MainFrame::onRadioHoughShow(wxCommandEvent& event)
{
    // set value in model
    m_model->setShowPictureHough(m_radioBoxHoughShow->GetSelection());

    // update GUi
    guiUpdateOnce();

    // reprocess actual image and update video frame
    videoFrameUpdate();
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onRadioSnakeShow
//
// Description: 'Show' radiobox event handler
//              (on snake's 'Tracking options' tab).
////////////////////////////////////////////////////////////
void MainFrame::onRadioSnakeShow(wxCommandEvent& event)
{
    // set value in model
    m_model->setShowPictureSnake(m_radioBoxSnakeShow->GetSelection());

    // update GUI
    guiUpdateOnce();

/*
    // reprocess actual image and update video frame
    videoFrameUpdate();
*/
}


////////////////////////////////////////////////////////////
// Class name:  MainFrame
// Method name: onBoxSnakeEnable
//
// Description: 'Active Contour' checbox event handler
//              (on snake's 'Tracking options' tab).
////////////////////////////////////////////////////////////
void MainFrame::onBoxSnakeEnable(wxCommandEvent& event)
{
    // change depending on model
    if (m_model->getSnakeOn())
    {
        m_model->setSnakeOn(false);
        m_model->setShowResultSnake(false);

        // set 'Show' radiobox if needed
        if (m_model->getShowPictureHough() == 3)
        {
            m_model->setShowPictureHough(0);
            m_model->setShowPictureSnake(0);
        }
    }
    else
    {
        m_model->setSnakeOn(true);
    }

    // update GUI
    guiUpdateOnce();

    // reprocess actual image and update video frame
    videoFrameUpdate();
}
