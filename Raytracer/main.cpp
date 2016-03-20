#include<stdio.h>
#include "glm\glm.hpp"
#include "glm\gtx\rotate_vector.hpp"

#include "Film.h"
#include "Raytracer.h"
#include "Ray.h"
#include "Shape.h"
#include "Camera.h"
#include "Scene.h"

int main(int argc, char* argv []) {
	const int film_width = 800;
	const int film_height = 640;

	//vec3 v1(1, 0, 0);
	//v1 = rotateY(v1,(float) M_PI/2);

	RayTracer raytracer;

	Camera camera(vec3(0,0,3),1.25f,60,0.3f);

	Ray ray = camera.GenerateRay( film_width/2.f, film_height/2.f);

	Film film1(film_width, film_height);

	Scene scene;
	scene.objs.push_back(Sphere(vec3(0, 0, -5), 1));
	for (int f1 = 0; f1 < 12; f1++)
	{
		scene.objs.push_back(Sphere(vec3(-1.5, -1.5, -3 - f1 * 3.5), 1));
		scene.objs.push_back(Sphere(vec3(1.5, 1.5, -3 - f1 * 3.5), 1));
	}

	for (int f1 = 0; f1 < film_height; f1++)
	{
		for (int f2 = 0; f2 < film_width; f2++)
		{
			Ray ray = camera.GenerateRay((f2+0.5f)/film_width, (f1+0.5f)/film_height);
			film1.SetColor(f2, f1, raytracer.trace(ray, scene));
		}
	}

	film1.SaveImage("Image 1.png");
	film1.~Film();

	return 0;
}