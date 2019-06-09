#include "Stereograms_Frame.h"


void Stereograms_Frame::LoadMask(int threshold = 128)	// Ustawia maskê na podstawie za³adowanej bitmapy
														// Dostosowuje rozmiar bitmapy do wymiarów stereogramu
														// Threshold: wartosc skali szarosci od ktorej obiekt odstaje (0-255)
{
	wxImage img = bitmap->ConvertToImage();
	if (img.GetWidth() > _stereogram.getWidth() / 2)
	{
		int aspect = img.GetWidth() / img.GetHeight();
		img.Rescale(_stereogram.getWidth() / 2, _stereogram.getWidth() / 2 / aspect);
	}

	int hGap = _stereogram.getWidth() / 2 - img.GetWidth(),
		vGap = _stereogram.getHeight() - img.GetHeight();

	for (int i = 0; i < _stereogram.getHeight() * _stereogram.getWidth() / 2; i++)
		mask[i] = 0;

	for (int i = 0; i < img.GetWidth(); i++)
		for (int j = 0; j < img.GetHeight(); j++)
			if (img.GetData()[(j * img.GetWidth() + i) * 3] < threshold)
				mask[(j + vGap) * _stereogram.getWidth() / 2 + (i + hGap)] = 1;
}


Stereograms_Frame::Stereograms_Frame(wxWindow* parent) : MyFrame(parent)
{
	int maskSize = _stereogram.getHeight() * _stereogram.getWidth() / 2;
	mask = new int[maskSize];
}

void Stereograms_Frame::Random_Dots(wxCommandEvent& event)
{
	int *tmp = new int[400 * 600];
	for (int i = 0; i < 400; i++)
	{
		for (int j = 0; j < 600; j++)
		{
			tmp[j * 400 + i] = i < 300 ? i > 200 ? j > 300 ? j < 400 ? 1 : 0 : 0 : 0 : 0;
		}
	}
	_stereogram.createDots();
	_stereogram.movePixels(tmp, 10);
	wxImage dotImage;
	dotImage.SetData(_stereogram.getDots(), _stereogram.getWidth(), _stereogram.getHeight());
	wxClientDC dc(m_panel);
	wxBitmap picture(dotImage);
	dc.DrawBitmap(picture, 0, 0, false);
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

	//dcbuffer.DrawBitmap(*bitmap, 0, 0, true);				Po co rysowaæ obrazek? : Karol

	LoadMask(250);
	_stereogram.movePixels(mask);
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
