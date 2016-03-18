#include<stdio.h>
#include "Film.h"

using namespace std;

int main(int argc, char* argv []) {
	const int film_width = 500;
	const int film_height = 500;

	Film film1(film_width, film_height);

	for (int f1 = 0; f1 < film_height; f1++)
	{
		for (int f2 = 0; f2 < film_width; f2++)
		{
			film1.SetColor(f2, f1, f2%255 + f1%255, f1%125, f2%125);
		}
	}

	film1.SaveImage("Image 1.png");

	return 0;
}