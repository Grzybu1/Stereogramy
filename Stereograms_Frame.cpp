#include "Stereograms_Frame.h"



Stereograms_Frame::Stereograms_Frame(wxWindow* parent) : MyFrame(parent)
{}

void Stereograms_Frame::Random_Dots(wxCommandEvent& event)
{
	// TODO: Implement Random_Dots
}

void Stereograms_Frame::Load_Bitmap(wxCommandEvent& event)
{
	wxClientDC dc(m_panel);

	wxFileDialog *dialog = new wxFileDialog(this, "Load file", "", "", wxT("Bitmap file (*.bmp)|*.bmp"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (dialog->ShowModal() == wxID_OK)
	{
		bitmap = new wxBitmap(dialog->GetPath(), wxBITMAP_TYPE_ANY);
	}

	wxBufferedDC dcbuffer(&dc);
	dcbuffer.Clear();

	m_panel->PrepareDC(dcbuffer);

	dcbuffer.DrawBitmap(*bitmap, 0, 0, true);
}

void Stereograms_Frame::Save_File(wxCommandEvent& event)
{

	wxFileDialog save(this, "Save as", "", "", "JPG files (*.jpg)|*.jpg", wxFD_SAVE);
	wxClientDC dc(m_panel);

	wxBufferedDC dcB(&dc);
	PrepareDC(dcB);

	wxInitAllImageHandlers();



	if (save.ShowModal() == wxID_OK)
	{
		wxSize panelSize = m_panel->GetVirtualSize();

		wxMemoryDC memory;

		memory.SelectObject(*bitmap);

		memory.Blit(0, 0, panelSize.GetX(), panelSize.GetY(), &dcB, 0, 0, wxCOPY, true);

		image = bitmap->ConvertToImage();

		image.SaveFile(save.GetPath(), wxBITMAP_TYPE_JPEG);
	}
}
