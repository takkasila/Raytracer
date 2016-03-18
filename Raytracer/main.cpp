#include<stdio.h>
#include "glm\glm.hpp"
#include "Film.h"
#include "Raytracer.h"
#include "Ray.h"
#include "Shape.h"
#include "Camera.h"

int main(int argc, char* argv []) {
	const int film_width = 500;
	const int film_height = 500;

	RayTracer raytracer;

	Camera cam(vec3(0, 0, 0), vec3(0, 0, -1), vec2(3,3));
	
	Film film1(film_width, film_height);

	Sphere s1(vec3(0, 0, -5), 1);

	for (int f1 = 0; f1 < film_height; f1++)
	{
		for (int f2 = 0; f2 < film_width; f2++)
		{
			Ray ray(
				vec3((float)f2/film_width * cam.plane_res.x - cam.plane_res.x/2 
				,(float)f1/film_height * cam.plane_res.y - cam.plane_res.y/2 ,0) + cam.pos
				, vec3(0, 0, -1), 1);
			
			film1.SetColor(f2, f1, raytracer.trace(ray, s1));
		}
	}

	film1.SaveImage("Image 1.png");
	
	return 0;
}