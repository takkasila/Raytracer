#ifndef FILM_H
#define FILM_H
#include "FreeImage.h"

class Film
{
public:
	Film(const int width, const int height);
	~Film();
	const int width, height;

	void SetColor(int x, int y, RGBQUAD color);
	void SetColor(int x, int y, BYTE R, BYTE G, BYTE B);
	void SaveImage(const char* imgName);

private:
	FIBITMAP* imagePlane;

};
#endif
