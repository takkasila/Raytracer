#ifndef RENDERER_H
#define RENDERER_H

#include "glm\glm.hpp"

#include "Ray.h"
#include "Shape.h"
#include "Scene.h"
#include "Camera.h"
#include "Sampler.h"

using namespace glm;

class Renderer
{
public:
	Renderer(Scene scene, Camera cam, Sampler sampler)
		:scene(scene), cam(cam), sampler(sampler)
	{}

	void Render();

	Scene scene;
	Camera cam;
	Sampler sampler;

private:
	vec3 EvaluateLight(int x, int y);
	vec3 Shading(Ray& ray, IntersectInfo info);

};

#endif