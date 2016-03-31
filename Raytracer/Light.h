#ifndef LIGHT_H
#define LIGHT_H

#include "glm\glm.hpp"

using namespace glm;
class DirectionalLight
{
public:
	DirectionalLight(vec3 dir = vec3(-1), float intensity = 1, vec3 color = vec3(1))
		:dir(normalize(dir)), intensity(intensity), color(color)
	{}
	vec3 dir;
	float intensity;
	vec3 color;
};
class PointLight
{
public:
	PointLight(vec3 pos = vec3(0, 5, 0), vec3 color = vec3(1), float intensity = 30)
		:pos(pos), color(color), intensity(intensity)
	{
	}

	float IntensAtPoint(vec3 point);

	vec3 pos;
	vec3 color;
	float intensity;
};

#endif