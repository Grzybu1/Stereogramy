#pragma once
#include "GUI.h"
#include "stdlib.h"
#include "time.h"

class Stereogram
{
public:
	Stereogram();		//Ustawia domyslne wartosci wysokosci, szerokosci oraz _size
	~Stereogram();

	wxImage movePixels(int* mask, wxImage rawDots, bool* flags);
	/*
	*	Metoda kolejno:
	*	Dla kazdego pixela sprawdza na masce czy przesunac,
	*	jesli trzeba to przesuwa go o 10 w lewo na lewej stronie jesli jest gdzie przesunac oraz w przypadku
	*	podniesionej flagi bright zmienia skladnik B o 128 (uzywajac modulo 255). Na koniec zwraca zmieniony wxImage.
	*/

	wxImage createDots(wxColour bacgroundColour, wxColour dotsColour);
	/*
	*	Metoda kolejno:
	*	Uaktualnia rozmiar, alokuje pamiec pod kropki, dla kazdego pixela oraz odpowiadajacego mu po drugiej stronie
	*	losuje obecnosc kropki i ja uzupelnia, zapisuje do obiektu wxImage, zwalnia pamiec, zwraca obiekt.
	*/

	int getWidth();					//Getter szerokosci
	int getHeight();				//Getter wysokosci
	void setWidth(int newWidth);	//Setter szerokosci
	void setHeight(int newHeight);	//Setter wysokosci


private:
	int _finalWidth;
	int _finalHeight;
	int _size;
};