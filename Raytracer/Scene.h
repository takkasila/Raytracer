#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "Shape.h"
#include "IntersectInfo.h"
#include "Light.h"

using namespace std;

class Scene
{
public:
	Scene(vec3 bgColor = vec3((float) 224 / 255, (float) 230 / 255, (float) 237 / 255))
		:bgColor(bgColor)
	{}
	bool Intersect(Ray& ray, double& t, IntersectInfo& info);

	vector<Sphere> objs;
	vector<Light> lights;
	vec3 bgColor;
};

#endif