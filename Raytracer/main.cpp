#include<stdio.h>
#include "glm\glm.hpp"
#include <stdio.h>

#include "Film.h"
#include "Camera.h"
#include "Scene.h"
#include "Shape.h"
#include "Renderer.h"

int main(int argc, char* argv []) {
	Film film(800, 640);

	Camera camera(vec3(0, 1.5, 6), 1.25f, 60, 0.3f, &film);
	camera.Rotate(vec3(0, 0, 0.5f));

	Scene scene;
	scene.ambientIntense = 0.2f;
	// Test objs
	scene.objs.push_back(Sphere(vec3(0.8, 1.5, 0), 1.5, vec3(210 / 255.f, 178 / 255.f, 158 / 255.f)));
	scene.objs.push_back(Sphere(vec3(-1.7, 0.5, 0), 0.5, vec3(83 / 255.f, 132 / 255.f, 162 / 255.f)));
	scene.objs.push_back(Sphere(vec3(0, -10000, 0), 10000, vec3(85 / 255.f, 62 / 255.f, 82 / 255.f)));
	// Test lights
	scene.lights.push_back(Light(vec3(3, 7, 3), vec3(1), 50));
	//scene.lights.push_back(Light(vec3(-3, 7, 3), vec3(1), 50));

	Renderer renderer(scene, camera);
	renderer.Render();

	return 0;
}