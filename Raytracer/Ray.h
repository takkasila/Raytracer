#ifndef RAY_H
#define RAY_H
#include "glm\glm.hpp"

using namespace glm;

class Ray
{
public:
	vec3 point, dir;
	float t;
	Ray(vec3 start_point, vec3 direction, float t)
	{
		point = start_point;
		dir = direction;
		this->t = t;
	}

private:
	
};

#endif