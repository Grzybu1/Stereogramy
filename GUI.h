///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_H__
#define __GUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/scrolwin.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/slider.h>
#include <wx/clrpicker.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame
///////////////////////////////////////////////////////////////////////////////
class MyFrame : public wxFrame
{
private:

protected:
	wxScrolledWindow* m_panel;
	wxButton* m_load_bitmap;
	wxButton* m_random_dots;
	wxCheckBox* m_helpful_dot;
	wxCheckBox* m_brighter;
	wxChoice* m_dis_res;
	wxSlider* m_threshold;
	wxColourPickerCtrl* m_background_color;
	wxColourPickerCtrl* m_dots_color;
	wxButton* m_saveButton;

	// Virtual event handlers, overide them in your derived class
	virtual void resize(wxSizeEvent& event) { event.Skip(); }
	virtual void Load_Bitmap(wxCommandEvent& event) { event.Skip(); }
	virtual void Random_Dots(wxCommandEvent& event) { event.Skip(); }
	virtual void Helpful_dot(wxCommandEvent& event) { event.Skip(); }
	virtual void Make_brighter(wxCommandEvent& event) { event.Skip(); }
	virtual void Display_resolution(wxCommandEvent& event) { event.Skip(); }
	virtual void OnScrollBar(wxScrollEvent& event) { event.Skip(); }
	virtual void Background_color(wxColourPickerEvent& event) { event.Skip(); }
	virtual void Dots_color(wxColourPickerEvent& event) { event.Skip(); }
	virtual void Save_File(wxCommandEvent& event) { event.Skip(); }


public:

	MyFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Stereogram_generatorinator Korkuc_Kocierz_Korzybski"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(666, 460), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~MyFrame();

};

#endif //__GUI_H__
