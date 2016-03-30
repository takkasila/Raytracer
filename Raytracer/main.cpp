#include<stdio.h>
#include "glm\glm.hpp"
#include <stdio.h>

#include "Camera.h"
#include "Scene.h"
#include "Primitive.h"
#include "Renderer.h"

int main(int argc, char* argv []) {
	Film film(800, 640);

	Camera camera(vec3(0, -.2f, 8), 1.25f, 60, 0.3f, &film);

	Scene scene;
	scene.bgColor = vec3(0.7f);
	scene.ambientIntense = 0;
	// Test objs
	int n = 1000, width = 3;
	// Right
	scene.objs.push_back(Primitive(
		Sphere(vec3(n + width, 0, 0), n)
		, Material(vec3(.75, .25, .25), 0.85, 32, 0.15)));
	// Left
	scene.objs.push_back(Primitive(
		Sphere(vec3(-n - width, 0, 0), n)
		, Material(vec3(.25, .25, .75), 0.85, 32, 0.15)));
	// Down
	scene.objs.push_back(Primitive(
		Sphere(vec3(0, -n - width, 0), n)
		, Material(vec3(.75, .75, .75), 0.85, 32, 0.9)));
	// Behind
	scene.objs.push_back(Primitive(
		Sphere(vec3(0, 0, -n - width), n)
		, Material(vec3(.75, .75, .75), 0.85, 32, 0.15)));


	scene.objs.push_back(Primitive(
		Sphere(vec3(0, -width+1.5, 0), 1.5)
		, Material(vec3(.95, .95, .95), 0.9, 64, 0.9)));

	// Test lights
	scene.lights.push_back(Light(vec3(width - 1, 2*width - 1, width), vec3(1), 32));

	Sampler sampler(camera, 4, 4);
	Renderer renderer(scene, camera, sampler, 0);
	renderer.Render();

	return 0;
}