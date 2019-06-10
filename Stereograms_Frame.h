#ifndef __Stereograms_Frame__
#define __Stereograms_Frame__

#include "GUI.h"
#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/bitmap.h>
#include <wx/wxprec.h>
#include <wx/colordlg.h>
#include <wx/rawbmp.h>
#include <wx/print.h>
#include "Stereogram.h"

class Stereograms_Frame : public MyFrame
{
protected:
	/////////Obsluga przyciskow - opisy dzialania przy implementacji////////
	void Random_Dots(wxCommandEvent& event);		
	void Load_Bitmap(wxCommandEvent& event);
	void Save_File(wxCommandEvent& event);
	void resize(wxSizeEvent& event);
	void Make_brighter(wxCommandEvent& event);
	void Display_resolution(wxCommandEvent& event);
	void OnScrollBar(wxScrollEvent& event);
	void Background_color(wxColourPickerEvent& event);
	void Dots_color(wxColourPickerEvent& event);
	void Helpful_dot(wxCommandEvent& event);

	/////////Pozostale funkcje////////
	void Draw();					/*	£¹czy wszystkie Image zgodnie z wytycznymi flag i 
									*	zapisuje do finalImage, rysuje na ekran.
									*/
public:

	Stereograms_Frame(wxWindow* parent);
	~Stereograms_Frame();

private:
	////////Zmienne////////
	Stereogram _stereogramCreator;
	wxImage _finalImage;			//Trzyma koncowy obraz
	wxImage _movedDots;			//Trzyma przesuniete kropki z ewentualnym podswietleniem
	wxImage _onlyDots;			//Trzyma same kropki
	wxBitmap* _bitmap;			//Trzyma wczytany kszta³t
	wxColour _backgroundColour;	//Trzyma kolor t³a
	wxColour _dotColour;			//Trzyma kolor kropek
	enum resolution { very_low, low, medium, high };
	int* _mask;					//Maska do przesuniec
	int _pixelsWidth = 1280;	//Szerokosc calego obrazka
	int _pixelsHeight = 720;	//wysokosc calego obrazka
	bool flags[5] = {};
	/*
	*Flagi kolejno: czy wylosowano kropki, czy jest maska, czy jest bitmapa, czy uruchomic podswietlenie,
	*				czy naniesc czerwone kropki-pomocnikow
	*/

	////////Funkcje////////
	void _loadMask(int threshold,wxBitmap* bitmap);/*
												  *	Metoda konwertuje bitmape podana w argunecie
												  *	na maske do zmiennej mask
												  */
};

#endif // __Stereograms_Frame__

