#pragma once
#include "GUI.h"
#include "stdlib.h"
#include "time.h"

class Stereogram
{
public:
	Stereogram();
	~Stereogram();
	void movePixels(int* mask, int step = 2, int helper = 8);
	unsigned char* getDots();
	int getWidth();
	int getHeight();
	void setWidth(int newWidth);
	void setHeight(int newHeight);

private:
	void createDots();
	int _finalWidth;
	int _finalHeight;
	unsigned char* _dots;
	int _size;
};