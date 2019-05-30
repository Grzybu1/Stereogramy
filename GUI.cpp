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

	m_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(400, 600), wxTAB_TRAVERSAL);
	m_panel->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHTTEXT));
	m_panel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));

	//drawing->Add(m_panel, 1, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL, 5);
	drawing->Add(m_panel, 1, wxALL | wxEXPAND , 5);


	window->Add(drawing, 1, wxALIGN_LEFT | wxEXPAND, 5);
	//window->Add(drawing, 1, wxALIGN_LEFT, 5);

	wxBoxSizer* options;
	options = new wxBoxSizer(wxVERTICAL);

	options->SetMinSize(wxSize(1, 1));
	m_random_dots = new wxButton(this, wxID_ANY, wxT("Random dots"), wxDefaultPosition, wxDefaultSize, 0);
	m_random_dots->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));

	//options->Add(m_random_dots, 1, wxALL | wxALIGN_RIGHT, 5);
	options->Add(m_random_dots, 1, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_load_bitmap = new wxButton(this, wxID_ANY, wxT("Load Bitmap"), wxDefaultPosition, wxDefaultSize, 0);
	m_load_bitmap->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
	m_load_bitmap->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));

	options->Add(m_load_bitmap, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_saveButton = new wxButton(this, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0);
	m_saveButton->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));

	options->Add(m_saveButton, 1, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);


	//window->Add(options, 0, wxALIGN_RIGHT | wxRIGHT | wxALIGN_CENTER_VERTICAL, 3);
	window->Add(options, 0, wxALIGN_CENTER_VERTICAL, 3);


	this->SetSizer(window);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	m_random_dots->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Random_Dots), NULL, this);
	m_load_bitmap->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Load_Bitmap), NULL, this);
	m_saveButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Save_File), NULL, this);
}

MyFrame::~MyFrame()
{
	// Disconnect Events
	m_random_dots->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Random_Dots), NULL, this);
	m_load_bitmap->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Load_Bitmap), NULL, this);
	m_saveButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Save_File), NULL, this);

}
