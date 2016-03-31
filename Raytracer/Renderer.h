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
	Renderer(Scene scene, Camera cam, Sampler sampler, int maxDepth = 4)
		:scene(scene), cam(cam), sampler(sampler), maxDepth(maxDepth)
	{}

	void Render();

	Scene scene;
	Camera cam;
	Sampler sampler;
	int maxDepth;

private:
	vec3 EvaluatePointLight(int x, int y);
	vec3 Shading(Ray& ray, IntersectInfo info, int depth);

};

#endif