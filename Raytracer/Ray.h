#ifndef RAY_H
#define RAY_H
#include "glm\glm.hpp"

using namespace glm;

class Ray
{
public:
	Ray(vec3 point = vec3(0, 0, 0), vec3 dir = vec3(0, 0, -1), double t = 1)
		: point(point), dir(dir), t(t)
	{}
	vec3 point, dir;
	double t;
};

#endif