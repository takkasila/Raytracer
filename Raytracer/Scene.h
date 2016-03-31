#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "Primitive.h"
#include "Light.h"

using namespace std;

class Scene
{
public:
	Scene(vec3 bgColor = vec3((float) 224 / 255, (float) 230 / 255, (float) 237 / 255), vec3 ambientColor = vec3(1), float ambientIntense = 0)
		:bgColor(bgColor), ambientColor(ambientColor), ambientIntense(clamp(ambientIntense, 0.f, 1.f))
	{}
	bool Intersect(Ray& ray, double& t, IntersectInfo& info);

	vector<Primitive> objs;
	vector<PointLight> PointLights;
	DirectionalLight directionalLight;
	vec3 bgColor;
	vec3 ambientColor;
	float ambientIntense;
};

#endif