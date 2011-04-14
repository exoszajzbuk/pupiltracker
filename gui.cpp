///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 29 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

#include "images/applicationexit16.xpm"
#include "images/applicationexit32.xpm"
#include "images/documentopen16.xpm"
#include "images/documentopen32.xpm"
#include "images/helpabout16.xpm"
#include "images/mediaplaybackpause16.xpm"
#include "images/mediaplaybackpause32.xpm"
#include "images/mediaplaybackstart16.xpm"
#include "images/mediaplaybackstart32.xpm"
#include "images/windowclose16.xpm"
#include "images/windowclose32.xpm"

///////////////////////////////////////////////////////////////////////////

MainFrameBase::MainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 400,650 ), wxSize( 400,650 ) );
	
	m_menuBar = new wxMenuBar( 0 );
	m_menuFile = new wxMenu();
	wxMenuItem* m_menuItemOpen;
	m_menuItemOpen = new wxMenuItem( m_menuFile, wxID_OPENMENU, wxString( wxT("Open") ) + wxT('\t') + wxT("CTRL+O"), wxT("Open a video file..."), wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItemOpen->SetBitmaps( wxBitmap( documentopen16_xpm ) );
	#elif defined( __WXGTK__ )
	m_menuItemOpen->SetBitmap( wxBitmap( documentopen16_xpm ) );
	#endif
	m_menuFile->Append( m_menuItemOpen );
	
	wxMenuItem* m_menuItemClose;
	m_menuItemClose = new wxMenuItem( m_menuFile, wxID_CLOSEMENU, wxString( wxT("Close") ) + wxT('\t') + wxT("CTRL-W"), wxT("Close current file..."), wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItemClose->SetBitmaps( wxBitmap( windowclose16_xpm ) );
	#elif defined( __WXGTK__ )
	m_menuItemClose->SetBitmap( wxBitmap( windowclose16_xpm ) );
	#endif
	m_menuFile->Append( m_menuItemClose );
	
	m_menuFile->AppendSeparator();
	
	wxMenuItem* m_menuItemExit;
	m_menuItemExit = new wxMenuItem( m_menuFile, wxID_EXITMENU, wxString( wxT("Exit") ) + wxT('\t') + wxT("Alt+F4"), wxT("Exit Demo Program..."), wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItemExit->SetBitmaps( wxBitmap( applicationexit16_xpm ) );
	#elif defined( __WXGTK__ )
	m_menuItemExit->SetBitmap( wxBitmap( applicationexit16_xpm ) );
	#endif
	m_menuFile->Append( m_menuItemExit );
	
	m_menuBar->Append( m_menuFile, wxT("&File") );
	
	m_menuTrack = new wxMenu();
	wxMenuItem* m_menuItemStart;
	m_menuItemStart = new wxMenuItem( m_menuTrack, wxID_STARTPAUSEMENU, wxString( wxT("Start") ) + wxT('\t') + wxT("CTRL-S"), wxT("Start tracking..."), wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItemStart->SetBitmaps( wxBitmap( mediaplaybackstart16_xpm ), wxBitmap( mediaplaybackpause16_xpm ) );
	#elif defined( __WXGTK__ )
	m_menuItemStart->SetBitmap( wxBitmap( mediaplaybackstart16_xpm ) );
	#endif
	m_menuTrack->Append( m_menuItemStart );
	
	wxMenuItem* m_menuItemPause;
	m_menuItemPause = new wxMenuItem( m_menuTrack, wxID_ANY, wxString( wxT("Pause") ) + wxT('\t') + wxT("CTRL+P"), wxT("Pause tracking..."), wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItemPause->SetBitmaps( wxBitmap( mediaplaybackpause16_xpm ) );
	#elif defined( __WXGTK__ )
	m_menuItemPause->SetBitmap( wxBitmap( mediaplaybackpause16_xpm ) );
	#endif
	m_menuTrack->Append( m_menuItemPause );
	
	m_menuBar->Append( m_menuTrack, wxT("&Track") );
	
	m_menuAbout = new wxMenu();
	wxMenuItem* m_menuItemAbout;
	m_menuItemAbout = new wxMenuItem( m_menuAbout, wxID_ANY, wxString( wxT("About") ) , wxT("Open 'About' dialog..."), wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItemAbout->SetBitmaps( wxBitmap( helpabout16_xpm ) );
	#elif defined( __WXGTK__ )
	m_menuItemAbout->SetBitmap( wxBitmap( helpabout16_xpm ) );
	#endif
	m_menuAbout->Append( m_menuItemAbout );
	
	m_menuBar->Append( m_menuAbout, wxT("&About") );
	
	this->SetMenuBar( m_menuBar );
	
	m_toolBar = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY ); 
	m_toolBar->AddTool( wxID_OPENTOOL, wxT("Open"), wxBitmap( documentopen32_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Open a video file...") );
	m_toolBar->AddTool( wxID_CLOSETOOL, wxT("Close"), wxBitmap( windowclose32_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Close video file...") );
	m_toolBar->AddSeparator();
	m_toolBar->AddTool( wxID_STARTTOOL, wxT("Start"), wxBitmap( mediaplaybackstart32_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Start tracking...") );
	m_toolBar->AddTool( wxID_PAUSETOOL, wxT("Pause"), wxBitmap( mediaplaybackpause32_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Pause tracking...") );
	m_toolBar->AddSeparator();
	m_toolBar->AddTool( wxID_EXITTOOL, wxT("Exit"), wxBitmap( applicationexit32_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Exit demo program...") );
	m_toolBar->Realize();
	
	wxBoxSizer* b_mainSizer;
	b_mainSizer = new wxBoxSizer( wxVERTICAL );
	
	m_notebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_RIGHT );
	m_notebook->SetFont( wxFont( 10, 74, 90, 90, false, wxT("Sans") ) );
	
	m_panelGeneral = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* b_generalSizer;
	b_generalSizer = new wxBoxSizer( wxVERTICAL );
	
	m_staticTextGeneralCaption = new wxStaticText( m_panelGeneral, wxID_ANY, wxT("General options"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextGeneralCaption->Wrap( -1 );
	m_staticTextGeneralCaption->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	b_generalSizer->Add( m_staticTextGeneralCaption, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sb_currentFileSizer;
	sb_currentFileSizer = new wxStaticBoxSizer( new wxStaticBox( m_panelGeneral, wxID_ANY, wxT("Current file") ), wxVERTICAL );
	
	wxFlexGridSizer* fg_currentFileSizer;
	fg_currentFileSizer = new wxFlexGridSizer( 3, 2, 0, 0 );
	fg_currentFileSizer->AddGrowableCol( 1 );
	fg_currentFileSizer->SetFlexibleDirection( wxHORIZONTAL );
	fg_currentFileSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticTextFile = new wxStaticText( m_panelGeneral, wxID_ANY, wxT("File:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextFile->Wrap( -1 );
	m_staticTextFile->SetFont( wxFont( 10, 70, 90, 90, false, wxEmptyString ) );
	
	fg_currentFileSizer->Add( m_staticTextFile, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_staticTextFileValue = new wxStaticText( m_panelGeneral, wxID_ANY, wxT("testvalue"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextFileValue->Wrap( -1 );
	m_staticTextFileValue->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 93, 90, false, wxEmptyString ) );
	
	fg_currentFileSizer->Add( m_staticTextFileValue, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_staticTextRes = new wxStaticText( m_panelGeneral, wxID_ANY, wxT("Resolution:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextRes->Wrap( -1 );
	m_staticTextRes->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fg_currentFileSizer->Add( m_staticTextRes, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticTextResValue = new wxStaticText( m_panelGeneral, wxID_ANY, wxT("testvalue"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextResValue->Wrap( -1 );
	m_staticTextResValue->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 93, 90, false, wxEmptyString ) );
	
	fg_currentFileSizer->Add( m_staticTextResValue, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticTextFramerate = new wxStaticText( m_panelGeneral, wxID_ANY, wxT("Framerate:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextFramerate->Wrap( -1 );
	fg_currentFileSizer->Add( m_staticTextFramerate, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_staticTextFramerateValue = new wxStaticText( m_panelGeneral, wxID_ANY, wxT("testvalue"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextFramerateValue->Wrap( -1 );
	m_staticTextFramerateValue->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 93, 90, false, wxEmptyString ) );
	
	fg_currentFileSizer->Add( m_staticTextFramerateValue, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	sb_currentFileSizer->Add( fg_currentFileSizer, 0, wxEXPAND, 5 );
	
	b_generalSizer->Add( sb_currentFileSizer, 0, wxEXPAND|wxALL, 5 );
	
	wxString m_radioBoxMethodChoices[] = { wxT("Hough transform"), wxT("Active Contour (Snakes)") };
	int m_radioBoxMethodNChoices = sizeof( m_radioBoxMethodChoices ) / sizeof( wxString );
	m_radioBoxMethod = new wxRadioBox( m_panelGeneral, wxID_ANY, wxT("Tracking method"), wxDefaultPosition, wxDefaultSize, m_radioBoxMethodNChoices, m_radioBoxMethodChoices, 1, wxRA_SPECIFY_COLS );
	m_radioBoxMethod->SetSelection( 0 );
	b_generalSizer->Add( m_radioBoxMethod, 0, wxALL|wxEXPAND, 5 );
	
	m_panelGeneral->SetSizer( b_generalSizer );
	m_panelGeneral->Layout();
	b_generalSizer->Fit( m_panelGeneral );
	m_notebook->AddPage( m_panelGeneral, wxT("General"), true );
	m_panelTrackHough = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* b_trackHoughSizer;
	b_trackHoughSizer = new wxBoxSizer( wxVERTICAL );
	
	m_staticTextTrackHoughCaption = new wxStaticText( m_panelTrackHough, wxID_ANY, wxT("Tracking options"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTrackHoughCaption->Wrap( -1 );
	m_staticTextTrackHoughCaption->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	b_trackHoughSizer->Add( m_staticTextTrackHoughCaption, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sb_houghEnableSizer;
	sb_houghEnableSizer = new wxStaticBoxSizer( new wxStaticBox( m_panelTrackHough, wxID_ANY, wxT("Enable") ), wxVERTICAL );
	
	m_checkBoxHoughThreshold = new wxCheckBox( m_panelTrackHough, wxID_ANY, wxT("Threshold"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBoxHoughThreshold->SetValue(true);
	
	sb_houghEnableSizer->Add( m_checkBoxHoughThreshold, 0, wxALL, 5 );
	
	m_checkBoxHoughBlur = new wxCheckBox( m_panelTrackHough, wxID_ANY, wxT("Gaussian blur"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBoxHoughBlur->SetValue(true);
	
	sb_houghEnableSizer->Add( m_checkBoxHoughBlur, 0, wxALL, 5 );
	
	m_checkBoxHoughHough = new wxCheckBox( m_panelTrackHough, wxID_ANY, wxT("Hough transform (+ Canny)"), wxDefaultPosition, wxDefaultSize, 0 );
	
	sb_houghEnableSizer->Add( m_checkBoxHoughHough, 0, wxALL, 5 );
	
	b_trackHoughSizer->Add( sb_houghEnableSizer, 0, wxEXPAND|wxALL, 5 );
	
	wxString m_radioBoxHoughShowChoices[] = { wxT("Original image"), wxT("Threshold result"), wxT("Gaussian blur result"), wxT("Canny result") };
	int m_radioBoxHoughShowNChoices = sizeof( m_radioBoxHoughShowChoices ) / sizeof( wxString );
	m_radioBoxHoughShow = new wxRadioBox( m_panelTrackHough, wxID_ANY, wxT("Show"), wxDefaultPosition, wxDefaultSize, m_radioBoxHoughShowNChoices, m_radioBoxHoughShowChoices, 1, wxRA_SPECIFY_COLS );
	m_radioBoxHoughShow->SetSelection( 0 );
	b_trackHoughSizer->Add( m_radioBoxHoughShow, 0, wxALL|wxEXPAND, 5 );
	
	m_checkBoxHoughShowResult = new wxCheckBox( m_panelTrackHough, wxID_ANY, wxT("Show detected circles"), wxDefaultPosition, wxDefaultSize, 0 );
	
	b_trackHoughSizer->Add( m_checkBoxHoughShowResult, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_panelTrackHough->SetSizer( b_trackHoughSizer );
	m_panelTrackHough->Layout();
	b_trackHoughSizer->Fit( m_panelTrackHough );
	m_notebook->AddPage( m_panelTrackHough, wxT("Tracking options"), false );
	m_panelTrackSnake = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	m_staticTextTrackSnakeCaption = new wxStaticText( m_panelTrackSnake, wxID_ANY, wxT("Tracking options"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTrackSnakeCaption->Wrap( -1 );
	m_staticTextTrackSnakeCaption->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	bSizer12->Add( m_staticTextTrackSnakeCaption, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sb_snakeEnableSizer1;
	sb_snakeEnableSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_panelTrackSnake, wxID_ANY, wxT("Enable") ), wxVERTICAL );
	
	m_checkBoxSnakeThreshold = new wxCheckBox( m_panelTrackSnake, wxID_ANY, wxT("Threshold"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBoxSnakeThreshold->SetValue(true);
	
	sb_snakeEnableSizer1->Add( m_checkBoxSnakeThreshold, 0, wxALL, 5 );
	
	m_checkBoxSnakeBlur = new wxCheckBox( m_panelTrackSnake, wxID_ANY, wxT("Gaussian blur"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBoxSnakeBlur->SetValue(true);
	
	sb_snakeEnableSizer1->Add( m_checkBoxSnakeBlur, 0, wxALL, 5 );
	
	m_checkBoxSnakeSnake = new wxCheckBox( m_panelTrackSnake, wxID_ANY, wxT("Active Contour"), wxDefaultPosition, wxDefaultSize, 0 );
	
	sb_snakeEnableSizer1->Add( m_checkBoxSnakeSnake, 0, wxALL, 5 );
	
	bSizer12->Add( sb_snakeEnableSizer1, 0, wxALL|wxEXPAND, 5 );
	
	wxString m_radioBoxSnakeShowChoices[] = { wxT("Original image"), wxT("Threshold result"), wxT("Gaussian blur result") };
	int m_radioBoxSnakeShowNChoices = sizeof( m_radioBoxSnakeShowChoices ) / sizeof( wxString );
	m_radioBoxSnakeShow = new wxRadioBox( m_panelTrackSnake, wxID_ANY, wxT("Show"), wxDefaultPosition, wxDefaultSize, m_radioBoxSnakeShowNChoices, m_radioBoxSnakeShowChoices, 1, wxRA_SPECIFY_COLS );
	m_radioBoxSnakeShow->SetSelection( 0 );
	bSizer12->Add( m_radioBoxSnakeShow, 0, wxALL|wxEXPAND, 5 );
	
	m_checkBoxSnakeShowResult = new wxCheckBox( m_panelTrackSnake, wxID_ANY, wxT("Show snakes"), wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizer12->Add( m_checkBoxSnakeShowResult, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_panelTrackSnake->SetSizer( bSizer12 );
	m_panelTrackSnake->Layout();
	bSizer12->Fit( m_panelTrackSnake );
	m_notebook->AddPage( m_panelTrackSnake, wxT("Tracking options"), false );
	m_panelBinarize = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* b_binarizingSizer;
	b_binarizingSizer = new wxBoxSizer( wxVERTICAL );
	
	m_staticTextBinarizingCaption = new wxStaticText( m_panelBinarize, wxID_ANY, wxT("Threshold options"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextBinarizingCaption->Wrap( -1 );
	m_staticTextBinarizingCaption->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	b_binarizingSizer->Add( m_staticTextBinarizingCaption, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sb_binarizingSizer;
	sb_binarizingSizer = new wxStaticBoxSizer( new wxStaticBox( m_panelBinarize, wxID_ANY, wxT("Threshold value") ), wxVERTICAL );
	
	m_sliderThresholdValue = new wxSlider( m_panelBinarize, wxID_ANY, 20, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	m_sliderThresholdValue->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	m_sliderThresholdValue->SetToolTip( wxT("Threshold value.") );
	
	sb_binarizingSizer->Add( m_sliderThresholdValue, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	b_binarizingSizer->Add( sb_binarizingSizer, 0, wxALL|wxEXPAND, 5 );
	
	m_panelBinarize->SetSizer( b_binarizingSizer );
	m_panelBinarize->Layout();
	b_binarizingSizer->Fit( m_panelBinarize );
	m_notebook->AddPage( m_panelBinarize, wxT("Threshold"), false );
	m_panelBlur = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* b_blurSizer;
	b_blurSizer = new wxBoxSizer( wxVERTICAL );
	
	m_staticTextBlurCaption = new wxStaticText( m_panelBlur, wxID_ANY, wxT("Gaussian blur options"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextBlurCaption->Wrap( -1 );
	m_staticTextBlurCaption->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	b_blurSizer->Add( m_staticTextBlurCaption, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sb_blurSizer;
	sb_blurSizer = new wxStaticBoxSizer( new wxStaticBox( m_panelBlur, wxID_ANY, wxT("Kernel size") ), wxVERTICAL );
	
	m_sliderBlurKernel = new wxSlider( m_panelBlur, wxID_ANY, 3, 1, 21, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	m_sliderBlurKernel->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	m_sliderBlurKernel->SetToolTip( wxT("Blur kernel size. The bigger values will result in more blurred image.") );
	
	sb_blurSizer->Add( m_sliderBlurKernel, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	b_blurSizer->Add( sb_blurSizer, 0, wxEXPAND|wxALL, 5 );
	
	m_panelBlur->SetSizer( b_blurSizer );
	m_panelBlur->Layout();
	b_blurSizer->Fit( m_panelBlur );
	m_notebook->AddPage( m_panelBlur, wxT("Gaussian blur"), false );
	m_panelEdge = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* b_edgeSizer;
	b_edgeSizer = new wxBoxSizer( wxVERTICAL );
	
	m_staticTextEdgeCaption = new wxStaticText( m_panelEdge, wxID_ANY, wxT("Canny options"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextEdgeCaption->Wrap( -1 );
	m_staticTextEdgeCaption->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	b_edgeSizer->Add( m_staticTextEdgeCaption, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( m_panelEdge, wxID_ANY, wxT("Canny parameter") ), wxVERTICAL );
	
	m_sliderHoughCanny = new wxSlider( m_panelEdge, wxID_ANY, 100, 0, 500, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	m_sliderHoughCanny->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	m_sliderHoughCanny->SetToolTip( wxT("Canny parameter. Bigger values means less edges.") );
	
	sbSizer9->Add( m_sliderHoughCanny, 0, wxALL|wxEXPAND, 5 );
	
	b_edgeSizer->Add( sbSizer9, 0, wxEXPAND|wxALL, 5 );
	
	m_panelEdge->SetSizer( b_edgeSizer );
	m_panelEdge->Layout();
	b_edgeSizer->Fit( m_panelEdge );
	m_notebook->AddPage( m_panelEdge, wxT("Canny"), false );
	m_panelHough = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* b_houghSizer;
	b_houghSizer = new wxBoxSizer( wxVERTICAL );
	
	m_staticTextHoughCaption = new wxStaticText( m_panelHough, wxID_ANY, wxT("Hough transform options"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextHoughCaption->Wrap( -1 );
	m_staticTextHoughCaption->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	b_houghSizer->Add( m_staticTextHoughCaption, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer11;
	sbSizer11 = new wxStaticBoxSizer( new wxStaticBox( m_panelHough, wxID_ANY, wxT("Accumulator resolution") ), wxVERTICAL );
	
	m_sliderHoughAccRes = new wxSlider( m_panelHough, wxID_ANY, 1, 1, 5, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	m_sliderHoughAccRes->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	m_sliderHoughAccRes->SetToolTip( wxT("Resolution of accumulation array.") );
	
	sbSizer11->Add( m_sliderHoughAccRes, 0, wxALL|wxEXPAND, 5 );
	
	b_houghSizer->Add( sbSizer11, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer12;
	sbSizer12 = new wxStaticBoxSizer( new wxStaticBox( m_panelHough, wxID_ANY, wxT("Minimum distance") ), wxVERTICAL );
	
	m_sliderHoughMinDist = new wxSlider( m_panelHough, wxID_ANY, 50, 0, 480, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	m_sliderHoughMinDist->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	m_sliderHoughMinDist->SetToolTip( wxT("Minimum distance between detected circles.") );
	
	sbSizer12->Add( m_sliderHoughMinDist, 0, wxALL|wxEXPAND, 5 );
	
	b_houghSizer->Add( sbSizer12, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer10;
	sbSizer10 = new wxStaticBoxSizer( new wxStaticBox( m_panelHough, wxID_ANY, wxT("Hough parameter") ), wxVERTICAL );
	
	m_sliderHoughParam = new wxSlider( m_panelHough, wxID_ANY, 50, 0, 500, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	m_sliderHoughParam->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	m_sliderHoughParam->SetToolTip( wxT("Hough parameter. The lower means more detected circles.") );
	
	sbSizer10->Add( m_sliderHoughParam, 0, wxALL|wxEXPAND, 5 );
	
	b_houghSizer->Add( sbSizer10, 0, wxEXPAND|wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer111;
	sbSizer111 = new wxStaticBoxSizer( new wxStaticBox( m_panelHough, wxID_ANY, wxT("Min/Max radius") ), wxVERTICAL );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_sliderHoughMinRad = new wxSlider( m_panelHough, wxID_ANY, 60, 0, 480, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	m_sliderHoughMinRad->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	m_sliderHoughMinRad->SetToolTip( wxT("Minimum radius of detected circles.") );
	
	bSizer11->Add( m_sliderHoughMinRad, 1, wxALL, 5 );
	
	m_sliderHoughMaxRad = new wxSlider( m_panelHough, wxID_ANY, 100, 0, 480, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	m_sliderHoughMaxRad->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	m_sliderHoughMaxRad->SetToolTip( wxT("Maximum radius of detected circles.") );
	
	bSizer11->Add( m_sliderHoughMaxRad, 1, wxALL, 5 );
	
	sbSizer111->Add( bSizer11, 1, wxEXPAND, 5 );
	
	b_houghSizer->Add( sbSizer111, 0, wxALL|wxEXPAND, 5 );
	
	m_panelHough->SetSizer( b_houghSizer );
	m_panelHough->Layout();
	b_houghSizer->Fit( m_panelHough );
	m_notebook->AddPage( m_panelHough, wxT("Hough transform"), false );
	m_panelSnake = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* b_snakeSizer;
	b_snakeSizer = new wxBoxSizer( wxVERTICAL );
	
	m_staticTextSnakeCaption = new wxStaticText( m_panelSnake, wxID_ANY, wxT("Active Contour options"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextSnakeCaption->Wrap( -1 );
	m_staticTextSnakeCaption->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	b_snakeSizer->Add( m_staticTextSnakeCaption, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer121;
	sbSizer121 = new wxStaticBoxSizer( new wxStaticBox( m_panelSnake, wxID_ANY, wxT("Snake parameters") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer2->AddGrowableCol( 1 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText251 = new wxStaticText( m_panelSnake, wxID_ANY, wxT("Alpha:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText251->Wrap( -1 );
	fgSizer2->Add( m_staticText251, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlSnakeAlpha = new wxTextCtrl( m_panelSnake, wxID_ANY, wxT("1.0"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	m_textCtrlSnakeAlpha->SetToolTip( wxT("Snake parameter Alpha. Internal force.") );
	
	fgSizer2->Add( m_textCtrlSnakeAlpha, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText261 = new wxStaticText( m_panelSnake, wxID_ANY, wxT("Beta:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText261->Wrap( -1 );
	fgSizer2->Add( m_staticText261, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_textCtrlSnakeBeta = new wxTextCtrl( m_panelSnake, wxID_ANY, wxT("1.0"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	m_textCtrlSnakeBeta->SetToolTip( wxT("Snake parameter Beta. Internal force.") );
	
	fgSizer2->Add( m_textCtrlSnakeBeta, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText271 = new wxStaticText( m_panelSnake, wxID_ANY, wxT("Gamma:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText271->Wrap( -1 );
	fgSizer2->Add( m_staticText271, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_textCtrlSnakeGamma = new wxTextCtrl( m_panelSnake, wxID_ANY, wxT("1.0"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	m_textCtrlSnakeGamma->SetToolTip( wxT("Snake parameter Gamma. External (image) force.") );
	
	fgSizer2->Add( m_textCtrlSnakeGamma, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText29 = new wxStaticText( m_panelSnake, wxID_ANY, wxT("Window size:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	fgSizer2->Add( m_staticText29, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_sliderSnakeKernel = new wxSlider( m_panelSnake, wxID_ANY, 15, 1, 30, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	m_sliderSnakeKernel->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	m_sliderSnakeKernel->SetToolTip( wxT("Snake window size.") );
	
	fgSizer2->Add( m_sliderSnakeKernel, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText28 = new wxStaticText( m_panelSnake, wxID_ANY, wxT("Iterations:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	fgSizer2->Add( m_staticText28, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_sliderSnakeIter = new wxSlider( m_panelSnake, wxID_ANY, 1, 1, 20, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	m_sliderSnakeIter->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	m_sliderSnakeIter->SetToolTip( wxT("Number of iterations.") );
	
	fgSizer2->Add( m_sliderSnakeIter, 0, wxALL|wxEXPAND, 5 );
	
	sbSizer121->Add( fgSizer2, 1, wxEXPAND, 5 );
	
	b_snakeSizer->Add( sbSizer121, 0, wxEXPAND|wxALL, 5 );
	
	m_panelSnake->SetSizer( b_snakeSizer );
	m_panelSnake->Layout();
	b_snakeSizer->Fit( m_panelSnake );
	m_notebook->AddPage( m_panelSnake, wxT("Active Contour"), false );
	
	b_mainSizer->Add( m_notebook, 1, wxALL|wxEXPAND, 5 );
	
	m_sliderFrames = new wxSlider( this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	m_sliderFrames->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	m_sliderFrames->Enable( false );
	m_sliderFrames->SetToolTip( wxT("Set frames...") );
	
	b_mainSizer->Add( m_sliderFrames, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer125;
	bSizer125 = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* g_statusSizer0;
	g_statusSizer0 = new wxGridSizer( 2, 4, 0, 0 );
	
	m_staticTextFrames = new wxStaticText( this, wxID_ANY, wxT("Frames:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextFrames->Wrap( -1 );
	m_staticTextFrames->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	
	g_statusSizer0->Add( m_staticTextFrames, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextFramesValue = new wxStaticText( this, wxID_ANY, wxT("testvalue"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextFramesValue->Wrap( -1 );
	m_staticTextFramesValue->SetFont( wxFont( 9, 70, 93, 90, false, wxEmptyString ) );
	
	g_statusSizer0->Add( m_staticTextFramesValue, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextCurrentFPS = new wxStaticText( this, wxID_ANY, wxT("FPS:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextCurrentFPS->Wrap( -1 );
	m_staticTextCurrentFPS->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	
	g_statusSizer0->Add( m_staticTextCurrentFPS, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextCurrentFPSValue = new wxStaticText( this, wxID_ANY, wxT("testvalue"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextCurrentFPSValue->Wrap( -1 );
	m_staticTextCurrentFPSValue->SetFont( wxFont( 9, 70, 93, 90, false, wxEmptyString ) );
	
	g_statusSizer0->Add( m_staticTextCurrentFPSValue, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextTime = new wxStaticText( this, wxID_ANY, wxT("Time:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTime->Wrap( -1 );
	m_staticTextTime->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	
	g_statusSizer0->Add( m_staticTextTime, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_staticTextTimeValue = new wxStaticText( this, wxID_ANY, wxT("testvalue"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextTimeValue->Wrap( -1 );
	m_staticTextTimeValue->SetFont( wxFont( 9, 70, 93, 90, false, wxEmptyString ) );
	
	g_statusSizer0->Add( m_staticTextTimeValue, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextLoop = new wxStaticText( this, wxID_ANY, wxT("Loop:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextLoop->Wrap( -1 );
	m_staticTextLoop->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	
	g_statusSizer0->Add( m_staticTextLoop, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_checkBoxLoop = new wxCheckBox( this, wxID_ANY, wxT("on/off"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBoxLoop->SetValue(true);
	
	m_checkBoxLoop->SetFont( wxFont( 9, 70, 93, 90, false, wxEmptyString ) );
	
	g_statusSizer0->Add( m_checkBoxLoop, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer125->Add( g_statusSizer0, 0, wxEXPAND, 5 );
	
	b_mainSizer->Add( bSizer125, 0, wxEXPAND, 5 );
	
	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	b_mainSizer->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );
	
	m_panelHoughStat = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText51 = new wxStaticText( m_panelHoughStat, wxID_ANY, wxT("Average FPS:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	m_staticText51->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	
	bSizer18->Add( m_staticText51, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextHoughStatAvgFPS = new wxStaticText( m_panelHoughStat, wxID_ANY, wxT("testvalue"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextHoughStatAvgFPS->Wrap( -1 );
	m_staticTextHoughStatAvgFPS->SetFont( wxFont( 9, 70, 93, 90, false, wxEmptyString ) );
	
	bSizer18->Add( m_staticTextHoughStatAvgFPS, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText53 = new wxStaticText( m_panelHoughStat, wxID_ANY, wxT("False detections:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText53->Wrap( -1 );
	m_staticText53->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	
	bSizer18->Add( m_staticText53, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextHoughStatFalseDets = new wxStaticText( m_panelHoughStat, wxID_ANY, wxT("testvalue"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextHoughStatFalseDets->Wrap( -1 );
	m_staticTextHoughStatFalseDets->SetFont( wxFont( 9, 70, 93, 90, false, wxEmptyString ) );
	
	bSizer18->Add( m_staticTextHoughStatFalseDets, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_panelHoughStat->SetSizer( bSizer18 );
	m_panelHoughStat->Layout();
	bSizer18->Fit( m_panelHoughStat );
	bSizer16->Add( m_panelHoughStat, 1, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	m_panelSnakeStat = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText55 = new wxStaticText( m_panelSnakeStat, wxID_ANY, wxT("Average FPS:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText55->Wrap( -1 );
	m_staticText55->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	
	bSizer19->Add( m_staticText55, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextSnakeStatAvgFPS = new wxStaticText( m_panelSnakeStat, wxID_ANY, wxT("testvalue"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextSnakeStatAvgFPS->Wrap( -1 );
	m_staticTextSnakeStatAvgFPS->SetFont( wxFont( 9, 70, 93, 90, false, wxEmptyString ) );
	
	bSizer19->Add( m_staticTextSnakeStatAvgFPS, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText57 = new wxStaticText( m_panelSnakeStat, wxID_ANY, wxT("Re-initializations:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText57->Wrap( -1 );
	m_staticText57->SetFont( wxFont( 9, 70, 90, 90, false, wxEmptyString ) );
	
	bSizer19->Add( m_staticText57, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticTextSnakeStatReInits = new wxStaticText( m_panelSnakeStat, wxID_ANY, wxT("testvalue"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextSnakeStatReInits->Wrap( -1 );
	m_staticTextSnakeStatReInits->SetFont( wxFont( 9, 70, 93, 90, false, wxEmptyString ) );
	
	bSizer19->Add( m_staticTextSnakeStatReInits, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_panelSnakeStat->SetSizer( bSizer19 );
	m_panelSnakeStat->Layout();
	bSizer19->Fit( m_panelSnakeStat );
	bSizer16->Add( m_panelSnakeStat, 1, wxEXPAND|wxRIGHT|wxLEFT, 5 );
	
	b_mainSizer->Add( bSizer16, 0, wxEXPAND, 5 );
	
	this->SetSizer( b_mainSizer );
	this->Layout();
	m_statusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	// Connect Events
	this->Connect( m_menuItemOpen->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::onButtonOpen ) );
	this->Connect( m_menuItemClose->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::onButtonClose ) );
	this->Connect( m_menuItemExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::onButtonExit ) );
	this->Connect( m_menuItemStart->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::onButtonStart ) );
	this->Connect( m_menuItemPause->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::onButtonPause ) );
	this->Connect( m_menuItemAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::onButtonAbout ) );
	this->Connect( wxID_OPENTOOL, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::onButtonOpen ) );
	this->Connect( wxID_CLOSETOOL, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::onButtonClose ) );
	this->Connect( wxID_STARTTOOL, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::onButtonStart ) );
	this->Connect( wxID_PAUSETOOL, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::onButtonPause ) );
	this->Connect( wxID_EXITTOOL, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::onButtonExit ) );
	m_radioBoxMethod->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MainFrameBase::onRadioMethod ), NULL, this );
	m_checkBoxHoughThreshold->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MainFrameBase::onBoxThresholdEnable ), NULL, this );
	m_checkBoxHoughBlur->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MainFrameBase::onBoxBlurEnable ), NULL, this );
	m_checkBoxHoughHough->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MainFrameBase::onBoxHoughEnable ), NULL, this );
	m_radioBoxHoughShow->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MainFrameBase::onRadioHoughShow ), NULL, this );
	m_checkBoxHoughShowResult->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MainFrameBase::onBoxHoughResultEnable ), NULL, this );
	m_checkBoxSnakeThreshold->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MainFrameBase::onBoxThresholdEnable ), NULL, this );
	m_checkBoxSnakeBlur->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MainFrameBase::onBoxBlurEnable ), NULL, this );
	m_checkBoxSnakeSnake->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MainFrameBase::onBoxSnakeEnable ), NULL, this );
	m_radioBoxSnakeShow->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MainFrameBase::onRadioSnakeShow ), NULL, this );
	m_checkBoxSnakeShowResult->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MainFrameBase::onBoxSnakeResultEnable ), NULL, this );
	m_sliderThresholdValue->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::onSliderThresholdValue ), NULL, this );
	m_sliderThresholdValue->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::onSliderThresholdValue ), NULL, this );
	m_sliderThresholdValue->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::onSliderThresholdValue ), NULL, this );
	m_sliderThresholdValue->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::onSliderThresholdValue ), NULL, this );
	m_sliderThresholdValue->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::onSliderThresholdValue ), NULL, this );
	m_sliderThresholdValue->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::onSliderThresholdValue ), NULL, this );
	m_sliderThresholdValue->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::onSliderThresholdValue ), NULL, this );
	m_sliderThresholdValue->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::onSliderThresholdValue ), NULL, this );
	m_sliderThresholdValue->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::onSliderThresholdValue ), NULL, this );
	m_sliderBlurKernel->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::onSliderBlurKernel ), NULL, this );
	m_sliderBlurKernel->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::onSliderBlurKernel ), NULL, this );
	m_sliderBlurKernel->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::onSliderBlurKernel ), NULL, this );
	m_sliderBlurKernel->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::onSliderBlurKernel ), NULL, this );
	m_sliderBlurKernel->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::onSliderBlurKernel ), NULL, this );
	m_sliderBlurKernel->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::onSliderBlurKernel ), NULL, this );
	m_sliderBlurKernel->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::onSliderBlurKernel ), NULL, this );
	m_sliderBlurKernel->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::onSliderBlurKernel ), NULL, this );
	m_sliderBlurKernel->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::onSliderBlurKernel ), NULL, this );
	m_sliderHoughCanny->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::onSliderHoughCanny ), NULL, this );
	m_sliderHoughCanny->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::onSliderHoughCanny ), NULL, this );
	m_sliderHoughCanny->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughCanny ), NULL, this );
	m_sliderHoughCanny->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughCanny ), NULL, this );
	m_sliderHoughCanny->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughCanny ), NULL, this );
	m_sliderHoughCanny->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughCanny ), NULL, this );
	m_sliderHoughCanny->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::onSliderHoughCanny ), NULL, this );
	m_sliderHoughCanny->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::onSliderHoughCanny ), NULL, this );
	m_sliderHoughCanny->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::onSliderHoughCanny ), NULL, this );
	m_sliderHoughAccRes->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::onSliderHoughAccRes ), NULL, this );
	m_sliderHoughAccRes->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::onSliderHoughAccRes ), NULL, this );
	m_sliderHoughAccRes->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughAccRes ), NULL, this );
	m_sliderHoughAccRes->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughAccRes ), NULL, this );
	m_sliderHoughAccRes->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughAccRes ), NULL, this );
	m_sliderHoughAccRes->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughAccRes ), NULL, this );
	m_sliderHoughAccRes->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::onSliderHoughAccRes ), NULL, this );
	m_sliderHoughAccRes->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::onSliderHoughAccRes ), NULL, this );
	m_sliderHoughAccRes->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::onSliderHoughAccRes ), NULL, this );
	m_sliderHoughMinDist->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::onSliderHoughMinDist ), NULL, this );
	m_sliderHoughMinDist->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::onSliderHoughMinDist ), NULL, this );
	m_sliderHoughMinDist->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughMinDist ), NULL, this );
	m_sliderHoughMinDist->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughMinDist ), NULL, this );
	m_sliderHoughMinDist->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughMinDist ), NULL, this );
	m_sliderHoughMinDist->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughMinDist ), NULL, this );
	m_sliderHoughMinDist->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::onSliderHoughMinDist ), NULL, this );
	m_sliderHoughMinDist->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::onSliderHoughMinDist ), NULL, this );
	m_sliderHoughMinDist->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::onSliderHoughMinDist ), NULL, this );
	m_sliderHoughParam->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::onSliderHoughParam ), NULL, this );
	m_sliderHoughParam->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::onSliderHoughParam ), NULL, this );
	m_sliderHoughParam->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughParam ), NULL, this );
	m_sliderHoughParam->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughParam ), NULL, this );
	m_sliderHoughParam->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughParam ), NULL, this );
	m_sliderHoughParam->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughParam ), NULL, this );
	m_sliderHoughParam->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::onSliderHoughParam ), NULL, this );
	m_sliderHoughParam->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::onSliderHoughParam ), NULL, this );
	m_sliderHoughParam->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::onSliderHoughParam ), NULL, this );
	m_sliderHoughMinRad->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::onSliderHoughMinRad ), NULL, this );
	m_sliderHoughMinRad->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::onSliderHoughMinRad ), NULL, this );
	m_sliderHoughMinRad->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughMinRad ), NULL, this );
	m_sliderHoughMinRad->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughMinRad ), NULL, this );
	m_sliderHoughMinRad->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughMinRad ), NULL, this );
	m_sliderHoughMinRad->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughMinRad ), NULL, this );
	m_sliderHoughMinRad->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::onSliderHoughMinRad ), NULL, this );
	m_sliderHoughMinRad->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::onSliderHoughMinRad ), NULL, this );
	m_sliderHoughMinRad->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::onSliderHoughMinRad ), NULL, this );
	m_sliderHoughMaxRad->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::onSliderHoughMaxRad ), NULL, this );
	m_sliderHoughMaxRad->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::onSliderHoughMaxRad ), NULL, this );
	m_sliderHoughMaxRad->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughMaxRad ), NULL, this );
	m_sliderHoughMaxRad->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughMaxRad ), NULL, this );
	m_sliderHoughMaxRad->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughMaxRad ), NULL, this );
	m_sliderHoughMaxRad->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughMaxRad ), NULL, this );
	m_sliderHoughMaxRad->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::onSliderHoughMaxRad ), NULL, this );
	m_sliderHoughMaxRad->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::onSliderHoughMaxRad ), NULL, this );
	m_sliderHoughMaxRad->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::onSliderHoughMaxRad ), NULL, this );
	m_textCtrlSnakeAlpha->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrameBase::onTextCtrlSnakeAlpha ), NULL, this );
	m_textCtrlSnakeBeta->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrameBase::onTextCtrlSnakeBeta ), NULL, this );
	m_textCtrlSnakeGamma->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrameBase::onTextCtrlSnakeGamma ), NULL, this );
	m_sliderSnakeKernel->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::onSliderSnakeKernel ), NULL, this );
	m_sliderSnakeKernel->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::onSliderSnakeKernel ), NULL, this );
	m_sliderSnakeKernel->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::onSliderSnakeKernel ), NULL, this );
	m_sliderSnakeKernel->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::onSliderSnakeKernel ), NULL, this );
	m_sliderSnakeKernel->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::onSliderSnakeKernel ), NULL, this );
	m_sliderSnakeKernel->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::onSliderSnakeKernel ), NULL, this );
	m_sliderSnakeKernel->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::onSliderSnakeKernel ), NULL, this );
	m_sliderSnakeKernel->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::onSliderSnakeKernel ), NULL, this );
	m_sliderSnakeKernel->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::onSliderSnakeKernel ), NULL, this );
	m_sliderSnakeIter->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::onSliderSnakeIter ), NULL, this );
	m_sliderSnakeIter->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::onSliderSnakeIter ), NULL, this );
	m_sliderSnakeIter->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::onSliderSnakeIter ), NULL, this );
	m_sliderSnakeIter->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::onSliderSnakeIter ), NULL, this );
	m_sliderSnakeIter->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::onSliderSnakeIter ), NULL, this );
	m_sliderSnakeIter->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::onSliderSnakeIter ), NULL, this );
	m_sliderSnakeIter->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::onSliderSnakeIter ), NULL, this );
	m_sliderSnakeIter->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::onSliderSnakeIter ), NULL, this );
	m_sliderSnakeIter->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::onSliderSnakeIter ), NULL, this );
	m_sliderFrames->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::onSliderFrames ), NULL, this );
	m_sliderFrames->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::onSliderFrames ), NULL, this );
	m_sliderFrames->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::onSliderFrames ), NULL, this );
	m_sliderFrames->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::onSliderFrames ), NULL, this );
	m_sliderFrames->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::onSliderFrames ), NULL, this );
	m_sliderFrames->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::onSliderFrames ), NULL, this );
	m_sliderFrames->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::onSliderFrames ), NULL, this );
	m_sliderFrames->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::onSliderFrames ), NULL, this );
	m_sliderFrames->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::onSliderFrames ), NULL, this );
	m_checkBoxLoop->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MainFrameBase::onBoxLoopEnable ), NULL, this );
}

MainFrameBase::~MainFrameBase()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::onButtonOpen ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::onButtonClose ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::onButtonExit ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::onButtonStart ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::onButtonPause ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrameBase::onButtonAbout ) );
	this->Disconnect( wxID_OPENTOOL, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::onButtonOpen ) );
	this->Disconnect( wxID_CLOSETOOL, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::onButtonClose ) );
	this->Disconnect( wxID_STARTTOOL, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::onButtonStart ) );
	this->Disconnect( wxID_PAUSETOOL, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::onButtonPause ) );
	this->Disconnect( wxID_EXITTOOL, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrameBase::onButtonExit ) );
	m_radioBoxMethod->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MainFrameBase::onRadioMethod ), NULL, this );
	m_checkBoxHoughThreshold->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MainFrameBase::onBoxThresholdEnable ), NULL, this );
	m_checkBoxHoughBlur->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MainFrameBase::onBoxBlurEnable ), NULL, this );
	m_checkBoxHoughHough->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MainFrameBase::onBoxHoughEnable ), NULL, this );
	m_radioBoxHoughShow->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MainFrameBase::onRadioHoughShow ), NULL, this );
	m_checkBoxHoughShowResult->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MainFrameBase::onBoxHoughResultEnable ), NULL, this );
	m_checkBoxSnakeThreshold->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MainFrameBase::onBoxThresholdEnable ), NULL, this );
	m_checkBoxSnakeBlur->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MainFrameBase::onBoxBlurEnable ), NULL, this );
	m_checkBoxSnakeSnake->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MainFrameBase::onBoxSnakeEnable ), NULL, this );
	m_radioBoxSnakeShow->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( MainFrameBase::onRadioSnakeShow ), NULL, this );
	m_checkBoxSnakeShowResult->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MainFrameBase::onBoxSnakeResultEnable ), NULL, this );
	m_sliderThresholdValue->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::onSliderThresholdValue ), NULL, this );
	m_sliderThresholdValue->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::onSliderThresholdValue ), NULL, this );
	m_sliderThresholdValue->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::onSliderThresholdValue ), NULL, this );
	m_sliderThresholdValue->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::onSliderThresholdValue ), NULL, this );
	m_sliderThresholdValue->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::onSliderThresholdValue ), NULL, this );
	m_sliderThresholdValue->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::onSliderThresholdValue ), NULL, this );
	m_sliderThresholdValue->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::onSliderThresholdValue ), NULL, this );
	m_sliderThresholdValue->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::onSliderThresholdValue ), NULL, this );
	m_sliderThresholdValue->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::onSliderThresholdValue ), NULL, this );
	m_sliderBlurKernel->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::onSliderBlurKernel ), NULL, this );
	m_sliderBlurKernel->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::onSliderBlurKernel ), NULL, this );
	m_sliderBlurKernel->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::onSliderBlurKernel ), NULL, this );
	m_sliderBlurKernel->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::onSliderBlurKernel ), NULL, this );
	m_sliderBlurKernel->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::onSliderBlurKernel ), NULL, this );
	m_sliderBlurKernel->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::onSliderBlurKernel ), NULL, this );
	m_sliderBlurKernel->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::onSliderBlurKernel ), NULL, this );
	m_sliderBlurKernel->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::onSliderBlurKernel ), NULL, this );
	m_sliderBlurKernel->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::onSliderBlurKernel ), NULL, this );
	m_sliderHoughCanny->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::onSliderHoughCanny ), NULL, this );
	m_sliderHoughCanny->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::onSliderHoughCanny ), NULL, this );
	m_sliderHoughCanny->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughCanny ), NULL, this );
	m_sliderHoughCanny->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughCanny ), NULL, this );
	m_sliderHoughCanny->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughCanny ), NULL, this );
	m_sliderHoughCanny->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughCanny ), NULL, this );
	m_sliderHoughCanny->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::onSliderHoughCanny ), NULL, this );
	m_sliderHoughCanny->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::onSliderHoughCanny ), NULL, this );
	m_sliderHoughCanny->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::onSliderHoughCanny ), NULL, this );
	m_sliderHoughAccRes->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::onSliderHoughAccRes ), NULL, this );
	m_sliderHoughAccRes->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::onSliderHoughAccRes ), NULL, this );
	m_sliderHoughAccRes->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughAccRes ), NULL, this );
	m_sliderHoughAccRes->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughAccRes ), NULL, this );
	m_sliderHoughAccRes->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughAccRes ), NULL, this );
	m_sliderHoughAccRes->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughAccRes ), NULL, this );
	m_sliderHoughAccRes->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::onSliderHoughAccRes ), NULL, this );
	m_sliderHoughAccRes->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::onSliderHoughAccRes ), NULL, this );
	m_sliderHoughAccRes->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::onSliderHoughAccRes ), NULL, this );
	m_sliderHoughMinDist->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::onSliderHoughMinDist ), NULL, this );
	m_sliderHoughMinDist->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::onSliderHoughMinDist ), NULL, this );
	m_sliderHoughMinDist->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughMinDist ), NULL, this );
	m_sliderHoughMinDist->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughMinDist ), NULL, this );
	m_sliderHoughMinDist->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughMinDist ), NULL, this );
	m_sliderHoughMinDist->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughMinDist ), NULL, this );
	m_sliderHoughMinDist->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::onSliderHoughMinDist ), NULL, this );
	m_sliderHoughMinDist->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::onSliderHoughMinDist ), NULL, this );
	m_sliderHoughMinDist->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::onSliderHoughMinDist ), NULL, this );
	m_sliderHoughParam->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::onSliderHoughParam ), NULL, this );
	m_sliderHoughParam->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::onSliderHoughParam ), NULL, this );
	m_sliderHoughParam->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughParam ), NULL, this );
	m_sliderHoughParam->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughParam ), NULL, this );
	m_sliderHoughParam->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughParam ), NULL, this );
	m_sliderHoughParam->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughParam ), NULL, this );
	m_sliderHoughParam->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::onSliderHoughParam ), NULL, this );
	m_sliderHoughParam->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::onSliderHoughParam ), NULL, this );
	m_sliderHoughParam->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::onSliderHoughParam ), NULL, this );
	m_sliderHoughMinRad->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::onSliderHoughMinRad ), NULL, this );
	m_sliderHoughMinRad->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::onSliderHoughMinRad ), NULL, this );
	m_sliderHoughMinRad->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughMinRad ), NULL, this );
	m_sliderHoughMinRad->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughMinRad ), NULL, this );
	m_sliderHoughMinRad->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughMinRad ), NULL, this );
	m_sliderHoughMinRad->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughMinRad ), NULL, this );
	m_sliderHoughMinRad->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::onSliderHoughMinRad ), NULL, this );
	m_sliderHoughMinRad->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::onSliderHoughMinRad ), NULL, this );
	m_sliderHoughMinRad->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::onSliderHoughMinRad ), NULL, this );
	m_sliderHoughMaxRad->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::onSliderHoughMaxRad ), NULL, this );
	m_sliderHoughMaxRad->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::onSliderHoughMaxRad ), NULL, this );
	m_sliderHoughMaxRad->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughMaxRad ), NULL, this );
	m_sliderHoughMaxRad->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughMaxRad ), NULL, this );
	m_sliderHoughMaxRad->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::onSliderHoughMaxRad ), NULL, this );
	m_sliderHoughMaxRad->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::onSliderHoughMaxRad ), NULL, this );
	m_sliderHoughMaxRad->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::onSliderHoughMaxRad ), NULL, this );
	m_sliderHoughMaxRad->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::onSliderHoughMaxRad ), NULL, this );
	m_sliderHoughMaxRad->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::onSliderHoughMaxRad ), NULL, this );
	m_textCtrlSnakeAlpha->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrameBase::onTextCtrlSnakeAlpha ), NULL, this );
	m_textCtrlSnakeBeta->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrameBase::onTextCtrlSnakeBeta ), NULL, this );
	m_textCtrlSnakeGamma->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrameBase::onTextCtrlSnakeGamma ), NULL, this );
	m_sliderSnakeKernel->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::onSliderSnakeKernel ), NULL, this );
	m_sliderSnakeKernel->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::onSliderSnakeKernel ), NULL, this );
	m_sliderSnakeKernel->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::onSliderSnakeKernel ), NULL, this );
	m_sliderSnakeKernel->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::onSliderSnakeKernel ), NULL, this );
	m_sliderSnakeKernel->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::onSliderSnakeKernel ), NULL, this );
	m_sliderSnakeKernel->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::onSliderSnakeKernel ), NULL, this );
	m_sliderSnakeKernel->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::onSliderSnakeKernel ), NULL, this );
	m_sliderSnakeKernel->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::onSliderSnakeKernel ), NULL, this );
	m_sliderSnakeKernel->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::onSliderSnakeKernel ), NULL, this );
	m_sliderSnakeIter->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::onSliderSnakeIter ), NULL, this );
	m_sliderSnakeIter->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::onSliderSnakeIter ), NULL, this );
	m_sliderSnakeIter->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::onSliderSnakeIter ), NULL, this );
	m_sliderSnakeIter->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::onSliderSnakeIter ), NULL, this );
	m_sliderSnakeIter->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::onSliderSnakeIter ), NULL, this );
	m_sliderSnakeIter->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::onSliderSnakeIter ), NULL, this );
	m_sliderSnakeIter->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::onSliderSnakeIter ), NULL, this );
	m_sliderSnakeIter->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::onSliderSnakeIter ), NULL, this );
	m_sliderSnakeIter->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::onSliderSnakeIter ), NULL, this );
	m_sliderFrames->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MainFrameBase::onSliderFrames ), NULL, this );
	m_sliderFrames->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MainFrameBase::onSliderFrames ), NULL, this );
	m_sliderFrames->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MainFrameBase::onSliderFrames ), NULL, this );
	m_sliderFrames->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MainFrameBase::onSliderFrames ), NULL, this );
	m_sliderFrames->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MainFrameBase::onSliderFrames ), NULL, this );
	m_sliderFrames->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MainFrameBase::onSliderFrames ), NULL, this );
	m_sliderFrames->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MainFrameBase::onSliderFrames ), NULL, this );
	m_sliderFrames->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MainFrameBase::onSliderFrames ), NULL, this );
	m_sliderFrames->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MainFrameBase::onSliderFrames ), NULL, this );
	m_checkBoxLoop->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MainFrameBase::onBoxLoopEnable ), NULL, this );
}

VideoFrameBase::VideoFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* b_mainSizer;
	b_mainSizer = new wxBoxSizer( wxVERTICAL );
	
	this->SetSizer( b_mainSizer );
	this->Layout();
}

VideoFrameBase::~VideoFrameBase()
{
}
