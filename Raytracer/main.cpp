#include<stdio.h>
#include "glm\glm.hpp"
#include <stdio.h>

#include "Camera.h"
#include "Scene.h"
#include "Primitive.h"
#include "Renderer.h"

#include <random>
#include <chrono>
#include <iostream>
#include <fstream>

int main(int argc, char* argv []) {
	vec2 p0(1, 0), p1(0, 0);
	float x = length(p0-p1);

	Film film(800, 640);

	Camera camera(vec3(0, 6, 9), 1.25f, 60, 0.3f, &film);
	camera.Rotate(vec3(-40, 0, 0));
	
	Scene scene;
	scene.bgColor = vec3(0, 0, 0);
	scene.ambientIntense = 0;

	scene.objs.push_back(Primitive(
		Sphere(), Material()
		));
	
	// Test PointLights
	scene.PointLights.push_back(PointLight(vec3(3, 7, 3), vec3(1), 30));
	scene.directionalLight = DirectionalLight(vec3(-1), 1.2);

	Sampler sampler(camera, 2, 2);
	Renderer renderer(scene, camera, sampler, 5);
	renderer.Render();

	return 0;
}