#ifndef RENDERER_H
#define RENDERER_H

#include "glm\glm.hpp"

#include "Ray.h"
#include "Shape.h"
#include "Scene.h"
#include "Camera.h"

using namespace glm;

class Renderer
{
public:
	Renderer(Scene scene, Camera cam)
		:scene(scene), cam(cam)
	{
	}

	void Render();
	vec3 EvaluateLight(Ray ray, IntersectInfo info);

	Scene scene;
	Camera cam;
};

#endif