#include "Stereogram.h"

Stereogram::Stereogram()
:_finalWidth(800),_finalHeight(600),_size(_finalHeight*_finalWidth*3)
{
	_dots = new unsigned char[_size];

}

Stereogram::~Stereogram()
{}

void Stereogram::createDots()
{
	_dots = new unsigned char[_size];
	int dot = {};							//Zmienna pomocnicza do ktorej losujemy czy czarna kropka czy biala
	int index = {};							//Zmienna pomocnicza zawierajaca aktualne polozenie w tablicy
	srand(time(NULL));
	for (int width = 0; width < _finalWidth / 2; width++)		//Iterujemy do polowy szerokosci wypelniajac jednoczesnie obie polowy
	{
		for (int height = 0; height < _finalHeight; height++)	//Iterujemy po calej wysokosci
		{
			dot = width == 1 ? 0 : rand() % 2;									//Losujemy 0/1 oznaczajace obecnosc kropki
			index = height * _finalWidth * 3 + width * 3;		//wyliczamy polozenie obecnego pixela

			/*
			*Przypisujemy do wartosci RGB pixela 0 lub 255 aby uzyskac calkowita czern lub biel;
			*Jednoczesnie robimy dokladnie to samo z pixelem na drugiej polowie aby otrzymac kopie
			*/
			_dots[index] = _dots[index + 1] = _dots[index + 2] =
			_dots[index + _finalWidth * 3 / 2] = _dots[index + 1 + _finalWidth * 3 / 2] = _dots[index + 2 + _finalWidth * 3 / 2] =
			dot == 1 ? 0 : 255;
		}
	}
}

void Stereogram::movePixels(int * mask, int step, int helper)
{
	int index = {};
	int ifCpy = {};
	for (int width = 0; width < _finalWidth / 2; width++)		//Iterujemy do polowy szerokosci
	{
		for (int height = 0; height < _finalHeight; height++)	//Iterujemy po calej wysokosci
		{
			ifCpy = mask[height * _finalWidth / 2 + width];			//Sprawdzamy czy piksel nalezy przesunac
			index = height * _finalWidth * 3 + width * 3;		//wyliczamy polozenie obecnego pixela
			if (ifCpy)											//Przesuniecie piksela.
			{
				_dots[index - 3 * step] = _dots[index - 3 * step + 1] = _dots[index - 3 * step + 2] =
				_dots[index + _finalWidth * 3 / 2];
				/*_dots[index - 3 * step] = 125;
				_dots[index - 3 * step + 1] = _dots[index - 3 * step + 2] =
				_dots[index + _finalWidth * 3 / 2];*/
			}
		}
	}

	index = _finalHeight / 2 * _finalWidth * 3 + _finalWidth / 4 * 3;
	index -= helper * _finalWidth * 3 + helper * 3;
	for (int i = 0; i < helper; i++)
	{
		for (int j = 0; j < helper; j++)
		{
			_dots[index + j * 3 + i * _finalWidth * 3] = 255;
			_dots[index + j * 3 + _finalWidth * 3/ 2 + i * _finalWidth * 3] = 255;
			_dots[index + j * 3 + i * _finalWidth * 3 + 1] = 0;
			_dots[index + j * 3 + _finalWidth * 3 / 2 + i * _finalWidth * 3 + 1] = 0;
			_dots[index + j * 3 + i * _finalWidth * 3 + 2] = 0;
			_dots[index + j * 3 + _finalWidth * 3 / 2 + i * _finalWidth * 3 + 2] = 0;
		}
	}
}

unsigned char * Stereogram::getDots()
{
	return _dots;
}

int Stereogram::getWidth()
{
	return _finalWidth;
}

int Stereogram::getHeight()
{
	return _finalHeight;
}
