#ifndef LIGHT_H
#define LIGHT_H

#include "glm\glm.hpp"

using namespace glm;

class Light
{
public:
	Light(vec3 pos = vec3(0, 5, 0), vec3 color = vec3(1), float Intensity = 30)
		:pos(pos), color(color), Intensity(Intensity)
	{
	}

	float IntensAtPoint(vec3 point);

	vec3 pos;
	vec3 color;
	float Intensity;
};

#endif