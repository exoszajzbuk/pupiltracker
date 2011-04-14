////////////////////////////////////////////////////////////////////////////////
// Filename: main.cpp
// Author:   Balazs KOVACS
// Year:     2010
//
// Description: Application definition and program entry point.
//
////////////////////////////////////////////////////////////////////////////////

// wxWidgets
#include <wx/wx.h>

// others
#include "MainFrame.h"
#include "TrackerModel.h"


////////////////////////////////////////////////////////////
// Class:        PupilTracker
// Derived from: wxApp
//
// Description: Main application class
////////////////////////////////////////////////////////////
class PupilTracker : public wxApp
{
    public:
	    bool OnInit();
};


// imlement macro
IMPLEMENT_APP(PupilTracker)


////////////////////////////////////////////////////////////
// Class name:  PupilTracker
// Method name: OnInit
//
// Description: wxWidgets program entry point.
////////////////////////////////////////////////////////////
bool PupilTracker::OnInit()
{
    // create model
    TrackerModel *model = new TrackerModel();

    // create main frame, with model
    MainFrame *frame = new MainFrame(NULL, model);
    
    // show frame
    frame->Show();
    return true;
}
