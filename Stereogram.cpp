#include "Stereogram.h"

Stereogram::Stereogram()
:_finalWidth(800),_finalHeight(600),_size(600*800*3)
{}

Stereogram::~Stereogram()
{}

wxImage Stereogram::createDots(wxColour bacgroundColour, wxColour dotsColour)
{
	_size = _finalHeight * _finalWidth * 3;						//Aktualizacja _size
	unsigned char* dots = new unsigned char[_size];				//Alokacja pamieci
	int dot = {};							//Zmienna pomocnicza do ktorej losujemy czy czarna kropka czy biala
	int index = {};							//Zmienna pomocnicza zawierajaca aktualne polozenie w tablicy
	srand(time(NULL));						//Uzaleznienie losowania od wewnetrznego zegara komputera
	for (int width = 0; width < _finalWidth / 2; width++)		//Iterujemy do polowy szerokosci wypelniajac jednoczesnie obie polowy
	{
		for (int height = 0; height < _finalHeight; height++)	//Iterujemy po calej wysokosci
		{
			dot = width == 1 ? 0 : rand() % 2;					//Losujemy 0/1 oznaczajace obecnosc kropki
			index = height * _finalWidth * 3 + width * 3;		//wyliczamy polozenie obecnego pixela

			/*
			*Przypisujemy do wartosci RGB pixela wartosci podane na paletach;
			*Jednoczesnie robimy dokladnie to samo z pixelem na drugiej polowie aby otrzymac kopie
			*/
			dots[index] = dots[index + _finalWidth * 3 / 2] = 
				dot == 1 ? dotsColour.Red() : bacgroundColour.Red();

			dots[index + 1] = dots[index + 1 + _finalWidth * 3 / 2] = 
				dot == 1 ? dotsColour.Green() : bacgroundColour.Green();

			dots[index + 2] = dots[index + 2 + _finalWidth * 3 / 2] = 
				dot == 1 ? dotsColour.Blue() : bacgroundColour.Blue();
		}
	}
	wxImage tmp;
	tmp.SetData(dots, _finalWidth, _finalHeight, false);
	return tmp;
}

wxImage Stereogram::movePixels(int * mask, wxImage rawDots, bool* flags)
{
	int index = {};												//Zmienna do przechowywania obecnego indexu
	int ifCpy = {};												//Zmienna do przechowywania pojedynczego pixela maski
	for (int width = 0; width < _finalWidth / 2; width++)		//Iterujemy do polowy szerokosci
	{
		for (int height = 0; height < _finalHeight; height++)	//Iterujemy po calej wysokosci
		{
			ifCpy = mask[height * _finalWidth / 2 + width];		//Sprawdzamy czy piksel nalezy przesunac
			if (ifCpy && width - 10 > 0)						//Przesuniecie piksela
			{
				rawDots.SetRGB(width - 10, height,						//ustawienie rgb na pixelu o wspolrzednych 10 pixeli w lewo
					rawDots.GetRed(width + _finalWidth / 2, height),	//r na to samo co odpowiadajacy pixel
					rawDots.GetGreen(width + _finalWidth / 2, height),	//g na to samo co odpowiadajacy pixel
					flags[3] == 1 ?										//sprawdzamy czy flaga podswietlenia w gorze
					(rawDots.GetBlue(width + _finalWidth / 2, height) + 128) % 255 :	//jesli tak to zmieniamy b o 128
					rawDots.GetBlue(width + _finalWidth / 2, height));					//jesli nie to b traktujemy jak r i g
			}
		}
	}
	return rawDots;
}

int Stereogram::getWidth()
{
	return _finalWidth;
}

int Stereogram::getHeight()
{
	return _finalHeight;
}

void Stereogram::setWidth(int newWidth)
{
	_finalWidth = newWidth;
}

void Stereogram::setHeight(int newHeight)
{
	_finalHeight = newHeight;
}
