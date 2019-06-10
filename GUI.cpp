///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame::MyFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetBackgroundColour(wxColour(250, 133, 244));

	wxBoxSizer* window;
	window = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* drawing;
	drawing = new wxBoxSizer(wxVERTICAL);

	m_panel = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	m_panel->SetScrollRate(5, 5);
	m_panel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));

	drawing->Add(m_panel, 1, wxEXPAND | wxALL, 5);


	window->Add(drawing, 1, wxALIGN_LEFT | wxEXPAND, 5);

	wxBoxSizer* options;
	options = new wxBoxSizer(wxVERTICAL);

	options->SetMinSize(wxSize(1, 1));
	m_load_bitmap = new wxButton(this, wxID_ANY, wxT("Load Bitmap"), wxDefaultPosition, wxDefaultSize, 0);
	m_load_bitmap->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
	m_load_bitmap->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));

	options->Add(m_load_bitmap, 0, wxALIGN_CENTER_HORIZONTAL, 5);

	m_random_dots = new wxButton(this, wxID_ANY, wxT("Random dots"), wxDefaultPosition, wxDefaultSize, 0);
	m_random_dots->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));

	options->Add(m_random_dots, 0, wxALIGN_CENTER_HORIZONTAL, 5);

	m_helpful_dot = new wxCheckBox(this, wxID_ANY, wxT("Helpful dot"), wxDefaultPosition, wxDefaultSize, 0);
	options->Add(m_helpful_dot, 0, wxALIGN_CENTER_HORIZONTAL, 5);

	m_brighter = new wxCheckBox(this, wxID_ANY, wxT("Brighter"), wxDefaultPosition, wxDefaultSize, 0);
	options->Add(m_brighter, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	wxString m_dis_resChoices[] = { wxT("800x600"), wxT("1920x1080"), wxT("1280x720"), wxT("640x480") };
	int m_dis_resNChoices = sizeof(m_dis_resChoices) / sizeof(wxString);
	m_dis_res = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_dis_resNChoices, m_dis_resChoices, 0);
	m_dis_res->SetSelection(2);
	options->Add(m_dis_res, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_threshold = new wxSlider(this, wxID_ANY, 128, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL | wxSL_LABELS);
	options->Add(m_threshold, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_background_color = new wxColourPickerCtrl(this, wxID_ANY, wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW), wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE);
	m_background_color->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));

	options->Add(m_background_color, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_dots_color = new wxColourPickerCtrl(this, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE);
	options->Add(m_dots_color, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_saveButton = new wxButton(this, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0);
	m_saveButton->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));

	options->Add(m_saveButton, 0, wxALIGN_CENTER_HORIZONTAL, 5);


	window->Add(options, 0, wxALIGN_CENTER_VERTICAL, 3);


	this->SetSizer(window);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	m_load_bitmap->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Load_Bitmap), NULL, this);
	m_random_dots->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Random_Dots), NULL, this);
	m_helpful_dot->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame::Helpful_dot), NULL, this);
	m_brighter->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame::Make_brighter), NULL, this);
	m_dis_res->Connect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MyFrame::Display_resolution), NULL, this);
	m_threshold->Connect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame::OnScrollBar), NULL, this);
	m_threshold->Connect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame::OnScrollBar), NULL, this);
	m_threshold->Connect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame::OnScrollBar), NULL, this);
	m_threshold->Connect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame::OnScrollBar), NULL, this);
	m_threshold->Connect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame::OnScrollBar), NULL, this);
	m_threshold->Connect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame::OnScrollBar), NULL, this);
	m_threshold->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::OnScrollBar), NULL, this);
	m_threshold->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame::OnScrollBar), NULL, this);
	m_threshold->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame::OnScrollBar), NULL, this);
	m_background_color->Connect(wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler(MyFrame::Background_color), NULL, this);
	m_dots_color->Connect(wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler(MyFrame::Dots_color), NULL, this);
	m_saveButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Save_File), NULL, this);
}

MyFrame::~MyFrame()
{
	// Disconnect Events
	m_load_bitmap->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Load_Bitmap), NULL, this);
	m_random_dots->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Random_Dots), NULL, this);
	m_helpful_dot->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame::Helpful_dot), NULL, this);
	m_brighter->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(MyFrame::Make_brighter), NULL, this);
	m_dis_res->Disconnect(wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler(MyFrame::Display_resolution), NULL, this);
	m_threshold->Disconnect(wxEVT_SCROLL_TOP, wxScrollEventHandler(MyFrame::OnScrollBar), NULL, this);
	m_threshold->Disconnect(wxEVT_SCROLL_BOTTOM, wxScrollEventHandler(MyFrame::OnScrollBar), NULL, this);
	m_threshold->Disconnect(wxEVT_SCROLL_LINEUP, wxScrollEventHandler(MyFrame::OnScrollBar), NULL, this);
	m_threshold->Disconnect(wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler(MyFrame::OnScrollBar), NULL, this);
	m_threshold->Disconnect(wxEVT_SCROLL_PAGEUP, wxScrollEventHandler(MyFrame::OnScrollBar), NULL, this);
	m_threshold->Disconnect(wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler(MyFrame::OnScrollBar), NULL, this);
	m_threshold->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(MyFrame::OnScrollBar), NULL, this);
	m_threshold->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(MyFrame::OnScrollBar), NULL, this);
	m_threshold->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(MyFrame::OnScrollBar), NULL, this);
	m_background_color->Disconnect(wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler(MyFrame::Background_color), NULL, this);
	m_dots_color->Disconnect(wxEVT_COMMAND_COLOURPICKER_CHANGED, wxColourPickerEventHandler(MyFrame::Dots_color), NULL, this);
	m_saveButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Save_File), NULL, this);

}
