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

	Film film(800, 640);

	Camera camera(vec3(0, 6, 9), 1.25f, 60, 0.3f, &film);
	camera.Rotate(vec3(-40, 0, 0));
	
	Scene scene;
	scene.bgColor = vec3(156 / 255.f, 208 / 255.f, 232 / 255.f);
	scene.ambientIntense = 0;

	// Random spheres
	default_random_engine generator(717830554);
	uniform_real_distribution<float> disX(-8, 8);
	uniform_real_distribution<float> disY(0, 1);
	uniform_real_distribution<float> disZ(-8, 6);
	uniform_real_distribution<float> disR(0.5, 1);

	vec3 gold1(226 / 255.f, 183 / 255.f, 82 / 255.f);
	int nSphere = 21;

	vec3 tempRand(0);
	float rRand;
	for (int i = 0; i < nSphere; i++)
	{
		rRand = disR(generator);
		tempRand = vec3(disX(generator), rRand, disZ(generator));

		scene.objs.push_back(Primitive(
			Sphere(tempRand, rRand)
			, Material(gold1, 0.9, 500, 0.15)));
	}

	generator.seed(0);
	disX.reset();
	disY.reset();
	disZ.reset();
	disR.reset();

	int nGlass = 10;
	for (int i = 0; i < nGlass; i++)
	{
		rRand = disR(generator);
		tempRand = vec3(disX(generator), rRand, disZ(generator));

		scene.objs.push_back(Primitive(
			Sphere(tempRand, rRand)
			, Material(vec3(1), 0.1, 500, 0.95)));
	}

	scene.objs.push_back(Primitive(
		Sphere(vec3(0, -10000, 0), 10000)
		, Material(vec3(1, 1, 1), 1, 128,0.2)));

	// Test PointLights
	scene.PointLights.push_back(PointLight(vec3(3, 7, 3), vec3(1), 30));
	scene.directionalLight = DirectionalLight(vec3(-1), 1.2);

	Sampler sampler(camera, 4, 4);
	Renderer renderer(scene, camera, sampler, 8);
	renderer.Render();

	return 0;
}