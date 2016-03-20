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

	Camera camera(vec3(0, 0, 2),1.25f,60,0.3f);
	camera.Rotate(vec3(0, 0, 0));

	Ray ray = camera.GenerateRay( film_width/2.f, film_height/2.f);

	Film film1(film_width, film_height);

	Scene scene;

	float length = 3.2f;
	int n = 6;
	float delta = length / n;
	
	for (int f1 = 0; f1 < n; f1++)
	{
		for (int f2 = 0; f2 < n; f2++)
		{
			for (int f3 = 0; f3 < n+2; f3++)
			scene.objs.push_back(Sphere(vec3(-length/2 + f2*delta, -length/2 + f1*delta,-f3*delta),0.1f));
		}
	}

	for (int f1 = 0; f1 < film_height; f1++)
	{
		for (int f2 = 0; f2 < film_width; f2++)
		{
			Ray ray = camera.GenerateRay((f2+0.5f)/film_width, (f1+0.5f)/film_height);
			film1.SetColor(f2, f1, raytracer.trace(ray, scene));

		}
		if (f1 == (int) (film_height / 4))
			printf("25\%\n");
		else if (f1 == (int) (film_height / 2))
			printf("50\%\n");
		else if (f1 == (int) ((float)(2* film_height)/3 ))
			printf("75\%\n");
	}

	film1.SaveImage("Image 1.png");
	film1.~Film();

	return 0;
}