#ifndef FILM_H
#define FILM_H
#include "FreeImage.h"
#include "glm\glm.hpp"

using namespace glm;
using namespace std;
class Film
{
public:
	Film(const int width, const int height);
	~Film();
	const int width, height;

	void SetColor(int x, int y, RGBQUAD color);
	void SetColor(int x, int y, BYTE R, BYTE G, BYTE B);
	void SetColor(int x, int y, vec3 color);
	void SaveImage(const char* imgName);

private:
	FIBITMAP* imagePlane;

};
#endif
