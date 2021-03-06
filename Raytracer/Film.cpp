#include "Film.h"

Film::Film(const int width, const int height) : width(width), height(height)
{
	FreeImage_Initialise();
	imagePlane = FreeImage_Allocate(width, height, 24);
}

void Film::SetColor(int x, int y, RGBQUAD color)
{
	FreeImage_SetPixelColor(imagePlane, x, y, &color);
}

void Film::SetColor(int x, int y, BYTE R, BYTE G, BYTE B)
{
	RGBQUAD color;
	color.rgbRed = R;
	color.rgbGreen = G;
	color.rgbBlue = B;
	FreeImage_SetPixelColor(imagePlane, x, y, &color);
}

void Film::SetColor(int x, int y, vec3 color)
{
	SetColor(x, y
		, clamp(color.r * 255, (float) 0, (float) 255)
		, clamp(color.g * 255, (float) 0, (float) 255)
		, clamp(color.b * 255, (float) 0, (float) 255));
}

void Film::SaveImage(const char* imgName)
{
	FreeImage_Save(FIF_PNG, imagePlane, imgName, 0);
}

Film::~Film()
{
	FreeImage_DeInitialise();
}