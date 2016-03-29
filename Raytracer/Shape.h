#ifndef SHAPE_H
#define SHAPE_H

#include "Ray.h"
class Sphere
{
public:
	/*Sphere(vec3 center = vec3(0, 0, 0), float radius = 1
		, vec3 diffuseMatColor = vec3((float) 0xcc / 255, (float) 0x70 / 255, (float) 0xa3 / 255)
		, float shininess = 16)*/
	Sphere(vec3 center = vec3(0, 0, 0), float radius = 1)
		:center(center), radius(radius)
	{}
	bool Intersect(Ray& ray, double& outT);

	vec3 center;
	float radius;
};

#endif