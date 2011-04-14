////////////////////////////////////////////////////////////////////////////////
// Filename: MainFrame.h
// Author:   Balazs KOVACS
// Year:     2010
//
// Description: Header of MainFrame class.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef __MainFrame__
#define __MainFrame__

// STL
#include <deque>

// others
#include "TrackerModel.h"
#include "VideoFrame.h"

// forward declarations
class MainWorker;
class VideoFrame;


////////////////////////////////////////////////////////////
// Class:        MainFrame
// Derived from: MainFrameBase
//
// Description: MainFrame class handles most of GUI calls
//              and events.
////////////////////////////////////////////////////////////
class MainFrame
    : public MainFrameBase
{
public:
    // default constructor
	MainFrame(wxWindow* parent, TrackerModel* model);

protected:
    // button/menu events
    void    onButtonOpen(wxCommandEvent& event);
    void    onButtonClose(wxCommandEvent& event);
    void    onButtonExit(wxCommandEvent& event);
    void    onButtonStart(wxCommandEvent& event);
    void    onButtonPause(wxCommandEvent& event);
    void    onButtonAbout(wxCommandEvent& event);

    // radio box events
    void    onRadioMethod(wxCommandEvent& event);
    void    onRadioHoughShow(wxCommandEvent& event);
    void    onRadioSnakeShow(wxCommandEvent& event);

    // slider events
    void    onSliderFrames(wxScrollEvent& event);
    void    onSliderThresholdValue(wxScrollEvent& event);
    void    onSliderBlurKernel(wxScrollEvent& event);
    void    onSliderHoughCanny(wxScrollEvent& event);
    void    onSliderHoughAccRes(wxScrollEvent& event);
    void    onSliderHoughMinDist(wxScrollEvent& event);
    void    onSliderHoughParam(wxScrollEvent& event);
    void    onSliderHoughMinRad(wxScrollEvent& event);
    void    onSliderHoughMaxRad(wxScrollEvent& event);
    void    onSliderSnakeIter(wxScrollEvent& event);
    void    onSliderSnakeKernel(wxScrollEvent& event);

    // checkboxes
    void    onBoxLoopEnable(wxCommandEvent& event);
    void    onBoxThresholdEnable(wxCommandEvent& event);
    void    onBoxBlurEnable(wxCommandEvent& event);
    void    onBoxHoughEnable(wxCommandEvent& event);
    void    onBoxHoughResultEnable(wxCommandEvent& event);
    void    onBoxSnakeEnable(wxCommandEvent& event);
    void    onBoxSnakeResultEnable(wxCommandEvent& event);

    // text controls
    void    onTextCtrlSnakeAlpha(wxCommandEvent& event);
    void    onTextCtrlSnakeBeta(wxCommandEvent& event);
    void    onTextCtrlSnakeGamma(wxCommandEvent& event);

    // idle event handler for rendering
    void    onIdle(wxIdleEvent& event);

private:
    // variables
    TrackerModel*       m_model;        // pointer to model
    VideoFrame*         m_resultFrame;  // pointer to video window
    std::deque<double>  m_fpsQueue;     // deque for fps-formatting

    // methods
    void        activateRenderLoop(bool on);    // activating render-loop 

    void        guiReset();                     // reset to defaults
    void        guiUpdate();                    // update GUI values (while loop)
    void        guiUpdateOnce();                // update GUI values once
    void        videoFrameUpdate();             // reprocess current frame

    wxString    getFormattedTime(double msec);  // get time in "mm:ss:cc"
};

#endif
