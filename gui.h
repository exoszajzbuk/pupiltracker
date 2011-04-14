///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 29 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __gui__
#define __gui__

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/toolbar.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/radiobox.h>
#include <wx/panel.h>
#include <wx/checkbox.h>
#include <wx/slider.h>
#include <wx/textctrl.h>
#include <wx/notebook.h>
#include <wx/statline.h>
#include <wx/statusbr.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_OPENMENU 1000
#define wxID_CLOSEMENU 1001
#define wxID_EXITMENU 1002
#define wxID_STARTPAUSEMENU 1003
#define wxID_OPENTOOL 1004
#define wxID_CLOSETOOL 1005
#define wxID_STARTTOOL 1006
#define wxID_PAUSETOOL 1007
#define wxID_EXITTOOL 1008

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrameBase
///////////////////////////////////////////////////////////////////////////////
class MainFrameBase : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* m_menuBar;
		wxMenu* m_menuFile;
		wxMenu* m_menuTrack;
		wxMenu* m_menuAbout;
		wxToolBar* m_toolBar;
		wxNotebook* m_notebook;
		wxPanel* m_panelGeneral;
		wxStaticText* m_staticTextGeneralCaption;
		wxStaticText* m_staticTextFile;
		wxStaticText* m_staticTextFileValue;
		wxStaticText* m_staticTextRes;
		wxStaticText* m_staticTextResValue;
		wxStaticText* m_staticTextFramerate;
		wxStaticText* m_staticTextFramerateValue;
		wxRadioBox* m_radioBoxMethod;
		wxPanel* m_panelTrackHough;
		wxStaticText* m_staticTextTrackHoughCaption;
		wxCheckBox* m_checkBoxHoughThreshold;
		wxCheckBox* m_checkBoxHoughBlur;
		wxCheckBox* m_checkBoxHoughHough;
		wxRadioBox* m_radioBoxHoughShow;
		wxCheckBox* m_checkBoxHoughShowResult;
		wxPanel* m_panelTrackSnake;
		wxStaticText* m_staticTextTrackSnakeCaption;
		wxCheckBox* m_checkBoxSnakeThreshold;
		wxCheckBox* m_checkBoxSnakeBlur;
		wxCheckBox* m_checkBoxSnakeSnake;
		wxRadioBox* m_radioBoxSnakeShow;
		wxCheckBox* m_checkBoxSnakeShowResult;
		wxPanel* m_panelBinarize;
		wxStaticText* m_staticTextBinarizingCaption;
		wxSlider* m_sliderThresholdValue;
		wxPanel* m_panelBlur;
		wxStaticText* m_staticTextBlurCaption;
		wxSlider* m_sliderBlurKernel;
		wxPanel* m_panelEdge;
		wxStaticText* m_staticTextEdgeCaption;
		wxSlider* m_sliderHoughCanny;
		wxPanel* m_panelHough;
		wxStaticText* m_staticTextHoughCaption;
		wxSlider* m_sliderHoughAccRes;
		wxSlider* m_sliderHoughMinDist;
		wxSlider* m_sliderHoughParam;
		wxSlider* m_sliderHoughMinRad;
		wxSlider* m_sliderHoughMaxRad;
		wxPanel* m_panelSnake;
		wxStaticText* m_staticTextSnakeCaption;
		wxStaticText* m_staticText251;
		wxTextCtrl* m_textCtrlSnakeAlpha;
		wxStaticText* m_staticText261;
		wxTextCtrl* m_textCtrlSnakeBeta;
		wxStaticText* m_staticText271;
		wxTextCtrl* m_textCtrlSnakeGamma;
		wxStaticText* m_staticText29;
		wxSlider* m_sliderSnakeKernel;
		wxStaticText* m_staticText28;
		wxSlider* m_sliderSnakeIter;
		wxSlider* m_sliderFrames;
		wxStaticText* m_staticTextFrames;
		wxStaticText* m_staticTextFramesValue;
		wxStaticText* m_staticTextCurrentFPS;
		wxStaticText* m_staticTextCurrentFPSValue;
		wxStaticText* m_staticTextTime;
		wxStaticText* m_staticTextTimeValue;
		wxStaticText* m_staticTextLoop;
		wxCheckBox* m_checkBoxLoop;
		wxStaticLine* m_staticline2;
		wxPanel* m_panelHoughStat;
		wxStaticText* m_staticText51;
		wxStaticText* m_staticTextHoughStatAvgFPS;
		wxStaticText* m_staticText53;
		wxStaticText* m_staticTextHoughStatFalseDets;
		wxPanel* m_panelSnakeStat;
		wxStaticText* m_staticText55;
		wxStaticText* m_staticTextSnakeStatAvgFPS;
		wxStaticText* m_staticText57;
		wxStaticText* m_staticTextSnakeStatReInits;
		wxStatusBar* m_statusBar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onButtonOpen( wxCommandEvent& event ){ event.Skip(); }
		virtual void onButtonClose( wxCommandEvent& event ){ event.Skip(); }
		virtual void onButtonExit( wxCommandEvent& event ){ event.Skip(); }
		virtual void onButtonStart( wxCommandEvent& event ){ event.Skip(); }
		virtual void onButtonPause( wxCommandEvent& event ){ event.Skip(); }
		virtual void onButtonAbout( wxCommandEvent& event ){ event.Skip(); }
		virtual void onRadioMethod( wxCommandEvent& event ){ event.Skip(); }
		virtual void onBoxThresholdEnable( wxCommandEvent& event ){ event.Skip(); }
		virtual void onBoxBlurEnable( wxCommandEvent& event ){ event.Skip(); }
		virtual void onBoxHoughEnable( wxCommandEvent& event ){ event.Skip(); }
		virtual void onRadioHoughShow( wxCommandEvent& event ){ event.Skip(); }
		virtual void onBoxHoughResultEnable( wxCommandEvent& event ){ event.Skip(); }
		virtual void onBoxSnakeEnable( wxCommandEvent& event ){ event.Skip(); }
		virtual void onRadioSnakeShow( wxCommandEvent& event ){ event.Skip(); }
		virtual void onBoxSnakeResultEnable( wxCommandEvent& event ){ event.Skip(); }
		virtual void onSliderThresholdValue( wxScrollEvent& event ){ event.Skip(); }
		virtual void onSliderBlurKernel( wxScrollEvent& event ){ event.Skip(); }
		virtual void onSliderHoughCanny( wxScrollEvent& event ){ event.Skip(); }
		virtual void onSliderHoughAccRes( wxScrollEvent& event ){ event.Skip(); }
		virtual void onSliderHoughMinDist( wxScrollEvent& event ){ event.Skip(); }
		virtual void onSliderHoughParam( wxScrollEvent& event ){ event.Skip(); }
		virtual void onSliderHoughMinRad( wxScrollEvent& event ){ event.Skip(); }
		virtual void onSliderHoughMaxRad( wxScrollEvent& event ){ event.Skip(); }
		virtual void onTextCtrlSnakeAlpha( wxCommandEvent& event ){ event.Skip(); }
		virtual void onTextCtrlSnakeBeta( wxCommandEvent& event ){ event.Skip(); }
		virtual void onTextCtrlSnakeGamma( wxCommandEvent& event ){ event.Skip(); }
		virtual void onSliderSnakeKernel( wxScrollEvent& event ){ event.Skip(); }
		virtual void onSliderSnakeIter( wxScrollEvent& event ){ event.Skip(); }
		virtual void onSliderFrames( wxScrollEvent& event ){ event.Skip(); }
		virtual void onBoxLoopEnable( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		MainFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Pupil Tracker Demo"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 400,650 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~MainFrameBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VideoFrameBase
///////////////////////////////////////////////////////////////////////////////
class VideoFrameBase : public wxFrame 
{
	private:
	
	protected:
	
	public:
		VideoFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxCAPTION|wxTAB_TRAVERSAL );
		~VideoFrameBase();
	
};

#endif //__gui__
