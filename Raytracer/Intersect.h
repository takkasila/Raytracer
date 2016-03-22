#ifndef INTERSECT_H
#define INTERSECT_H

#include "Ray.h"

class Intersect
{
public:
	Intersect(vec3 point, vec3 normal, vec3 color = vec3(0,0,0))
		:point(point), normal(normal), color(color)
	{}
	
	vec3 point;
	vec3 normal;
	vec3 color;
	
};

#endif