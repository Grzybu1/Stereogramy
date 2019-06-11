#include "Stereograms_Frame.h"

wxPageSetupDialogData *PageData;

Stereograms_Frame::Stereograms_Frame(wxWindow* parent) : MyFrame(parent)
{
	_stereogramCreator.setWidth(_pixelsWidth);
	_stereogramCreator.setHeight(_pixelsHeight);
	_backgroundColour = m_background_color->GetColour();
	_dotColour = m_dots_color->GetColour(); 
	_mask = new int[_stereogramCreator.getHeight() * _stereogramCreator.getWidth() / 2];
}

Stereograms_Frame::~Stereograms_Frame()
{
	delete[] _mask;
}

void Stereograms_Frame::Draw()
{
	_stereogramCreator.setWidth(_pixelsWidth);
	_stereogramCreator.setHeight(_pixelsHeight);
	wxClientDC dc(m_panel);
	dc.Clear();
	if (!flags[0])					//Sprawdzenie potrzeby losowania nowych kropek
	{
		_onlyDots = _stereogramCreator.createDots(_backgroundColour, _dotColour);
		flags[0] = 1;
	}
	if (!flags[1])					//Sprawdzenie potrzeby stworzenia maski
	{
		delete[] _mask;
		int _maskSize = _stereogramCreator.getHeight() * _stereogramCreator.getWidth() / 2;
		_mask = new int[_maskSize];
		flags[1] = 1;			//Oznaczenie obecnosci maski

		if (flags[2])				//Sprawdzenie czy jest zaladowana bitmapa
		{
			_loadMask(m_threshold->GetValue(), _bitmap);	//Utworzenie do zmiennej _mask maski na podstawie bitmapy
		}
		else
		{
			for (int i = 0; i < _stereogramCreator.getWidth() / 2; i++)		//Ustawienie prostokata jako domyslny ksztalt
			{
				for (int j = 0; j < _stereogramCreator.getHeight(); j++)
				{
					_mask[j * _stereogramCreator.getWidth() / 2 + i] =
						i < _stereogramCreator.getHeight() / 2 ?
						i > _stereogramCreator.getHeight() / 3 ?
						j > _stereogramCreator.getWidth() / 3 ?
						j < _stereogramCreator.getWidth() / 2 ?
						1 : 0 : 0 : 0 : 0;
				}
			}
		}
	}
	_movedDots = _stereogramCreator.movePixels(_mask, _onlyDots, flags);		//Stworzenie obrazka
	_finalImage = _movedDots;
	if (flags[4])					//Sprawdzenie czy naniesc czerwone kropki
	{
		for (int height = 0; height < 9; height++)					//Nanoszenie 2 czerwonych kropek o wymiarach 9x9
		{
			for (int width = 0; width < 9; width++)
			{
				_finalImage.SetRGB(_pixelsWidth / 4 - 4 + width, _pixelsHeight / 2 - 4 + height, 255, 0, 0);
				_finalImage.SetRGB(3 * _pixelsWidth / 4 - 4 + width, _pixelsHeight / 2 - 4 + height, 255, 0, 0);
			}
		}
	}
	dc.DrawBitmap(_finalImage, 0, 0, false);
}

void Stereograms_Frame::Load_Bitmap(wxCommandEvent& event)
{
	wxFileDialog *dialog =						//Tworzenie okna dialogowego do wczytywania mapy
		new wxFileDialog(this, "Load file", "", "", wxT("Bitmap file (*.bmp)|*.bmp"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (dialog->ShowModal() == wxID_OK)			//Sprawdzanie czy pomyslnie otwarto okno
	{
		_bitmap = new wxBitmap(dialog->GetPath(), wxBITMAP_TYPE_ANY);	//Pobranie bitmapy do zmiennej
	}
	flags[2] = 1;					//Flaga obecnosci zaladowanej bitmapy
	flags[1] = 0;					//Oznaczenie potrzeby wykonania nowej maski
	Draw();							//Aktualizacja rysunku
}

void Stereograms_Frame::Save_File(wxCommandEvent& event)
{
	m_panel->Refresh();
	wxFileDialog save(this, "Save as", "", "", "Bitmap image (*.bmp)|*.bmp", wxFD_SAVE);
	wxClientDC dc(m_panel);

	wxBufferedDC dcB(&dc);
	PrepareDC(dcB);

	wxInitAllImageHandlers();

	if (save.ShowModal() == wxID_OK)
	{
		wxSize panelSize = m_panel->GetVirtualSize();
		wxBitmap bitmap_save(panelSize);

		wxMemoryDC memory;

		memory.SelectObject(bitmap_save);

		memory.Blit(0, 0, panelSize.GetX(), panelSize.GetY(), &dcB, 0, 0, wxCOPY, true);

		_finalImage.SaveFile(save.GetPath(), wxBITMAP_TYPE_BMP);
	}
	Draw();
}

void Stereograms_Frame::Display_resolution(wxCommandEvent& event)
{
	switch (m_dis_res->GetCurrentSelection())		//Pobranie nowych wymiarow z przycisku
	{
	case very_low:
		_pixelsWidth = 800;
		_pixelsHeight = 600;
		break;
	case low:
		_pixelsWidth = 1920;
		_pixelsHeight = 1080;
		break;
	case medium:
		_pixelsWidth = 1280;
		_pixelsHeight = 720;
		break;
	case high:
		_pixelsWidth = 640;
		_pixelsHeight = 480;
		break;
	default:
		_pixelsWidth = 800;
		_pixelsHeight = 600;
	}
	flags[0] = flags[1] = 0;					//Oznaczenie potrzeby wygenerowania nowych kropek i maski
	Draw();										//Aktualizacja rysunku
}

void Stereograms_Frame::Random_Dots(wxCommandEvent& event)
{
	flags[0] = 0;	//Oznaczenie flagi posiadania wylosowanych kropek - wymuszenie nowego losowania
	Draw();			//Aktualizacja rysunku
}

void Stereograms_Frame::Helpful_dot(wxCommandEvent& event)
{
	flags[4] = m_helpful_dot->IsChecked();		//Oznaczenie potrzeby dorysowania kropki
	Draw();										//Aktualizacja rysunku
}

void Stereograms_Frame::Make_brighter(wxCommandEvent& event)
{
	flags[3] = m_brighter->IsChecked();			//Oznaczenie potrzeby podswietlenia przesuniecia
	Draw();										//Aktualizacja rysunku
}

void Stereograms_Frame::OnScrollBar(wxScrollEvent& event)
{
	flags[1] = 0;								//Oznaczenie potrzeby stworzenia nowej maski
	Draw();										//Aktualizacja rysunku
}

void Stereograms_Frame::Background_color(wxColourPickerEvent& event)
{
	_backgroundColour = m_background_color->GetColour();		//Zapisanie koloru z palety
	flags[0] = 0;												//Oznaczenie potrzeby losowania nowych kropek
	Draw();														//Aktualizacja rysunku
}

void Stereograms_Frame::Dots_color(wxColourPickerEvent& event)
{
	_dotColour = m_dots_color->GetColour();						//Zapisanie koloru z palety
	flags[0] = 0;												//Oznaczenie potrzeby losowania nowych kropek
	Draw();														//Aktualizacja rysunku
}

void Stereograms_Frame::resize(wxSizeEvent& event)
{
	Draw();
}

void Stereograms_Frame::_loadMask(int threshold, wxBitmap* _bitmap)	// Ustawia maske na podstawie zaladowanej bitmapy
														// Dostosowuje rozmiar bitmapy do wymiarow stereogramu
														// Threshold: wartosc skali szarosci od ktorej obiekt odstaje (0-255)
{
	wxImage img = _bitmap->ConvertToImage();
	if (img.GetWidth() > _stereogramCreator.getWidth() / 2)
	{
		double aspect = (double)img.GetWidth() / (double)img.GetHeight();
		img.Rescale(_stereogramCreator.getWidth() / 2, _stereogramCreator.getWidth() / 2 / aspect);
	}

	int hGap = _stereogramCreator.getWidth() / 4 - 0.5 * img.GetWidth(),
		vGap = _stereogramCreator.getHeight() / 2 - 0.5 * img.GetHeight();

	for (int i = 0; i < _stereogramCreator.getHeight() * _stereogramCreator.getWidth() / 2; i++)
		_mask[i] = 0;

	for (int i = 0; i < img.GetWidth(); i++)
		for (int j = 0; j < img.GetHeight(); j++)
			if (img.GetData()[(j * img.GetWidth() + i) * 3] > threshold)
				_mask[(j + vGap) * _stereogramCreator.getWidth() / 2 + (i + hGap)] = 1;
}




