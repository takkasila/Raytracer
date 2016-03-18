#include<stdio.h>
#include "glm\glm.hpp"
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

	Camera cam(vec3(0, 0, 0), vec3(0, 0, -1), vec2(5,4));
	
	Film film1(film_width, film_height);

	Scene scene;
	scene.objs.push_back(Sphere(vec3(0, 0, -1.7f), 1));
	scene.objs.push_back(Sphere(vec3(0, 1, -1.7f), .5));
	scene.objs.push_back(Sphere(vec3(0, -1, -1.7f), .5));
	scene.objs.push_back(Sphere(vec3(1, 0, -1.7f), .5));
	scene.objs.push_back(Sphere(vec3(-1, 0, -1.7f), .5));

	for (int f1 = 0; f1 < film_height; f1++)
	{
		for (int f2 = 0; f2 < film_width; f2++)
		{
			Ray ray(
				vec3((float)f2/film_width * cam.plane_res.x - cam.plane_res.x/2 
				,(float)f1/film_height * cam.plane_res.y - cam.plane_res.y/2 ,0) + cam.pos
				, vec3(0, 0, -1), 1);
			
			film1.SetColor(f2, f1, raytracer.trace(ray, scene));
		}
	}

	film1.SaveImage("Image 1.png");
	film1.~Film();

	return 0;
}