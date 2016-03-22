#include<stdio.h>
#include "glm\glm.hpp"
#include <stdio.h>

#include "Film.h"
#include "Raytracer.h"
#include "Ray.h"
#include "Shape.h"
#include "Camera.h"
#include "Scene.h"

int main(int argc, char* argv []) {
	const int film_width = 800;
	const int film_height = 640;

	RayTracer raytracer;

	Camera camera(vec3(3, 3, 3),1.25f,60,0.3f);
	camera.Rotate(vec3(-30, 30, 0));

	Film film1(film_width, film_height);

	Scene scene;

	scene.objs.push_back(Sphere(vec3(0, 0, 0), 1, vec3(1, 0, 0)));
	scene.objs.push_back(Sphere(vec3(0, 0, -2), 1, vec3(1, 1, 0)));
	scene.objs.push_back(Sphere(vec3(0, 0, -4), 1, vec3(0, 1, 0)));
	scene.objs.push_back(Sphere(vec3(0, 0, -6), 1, vec3(0, 1, 1)));
	scene.objs.push_back(Sphere(vec3(0, 0, -8), 1, vec3(0, 0, 1)));
	scene.objs.push_back(Sphere(vec3(0, 0, -10), 1, vec3(1, 0, 1)));

	for (int f1 = 0; f1 < film_height; f1++)
	{
		for (int f2 = 0; f2 < film_width; f2++)
		{
			Ray ray = camera.GenerateRay((f2+0.5f)/film_width, (f1+0.5f)/film_height);
			film1.SetColor(f2, film_height - f1, raytracer.trace(ray, scene));
		}

		// Checking progress
		if (f1 == (int) (film_height / 4))
			printf("25%%\n");
		else if (f1 == (int) (film_height / 2))
			printf("50%%\n");
		else if (f1 == (int) ((float)(2* film_height)/3 ))
			printf("75%%\n");
	}

	film1.SaveImage("Image 1.png");
	film1.~Film();

	return 0;
}