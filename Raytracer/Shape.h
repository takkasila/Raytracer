#ifndef SHAPE_H
#define SHAPE_H

#include "Ray.h"
#include "IntersectInfo.h"
class Shape
{
public:
	virtual bool intersect(Ray& ray, float& outT);

};

class Sphere
{
public:
	Sphere(vec3 center = vec3(0, 0, 0), float radius = 1
		, vec3 diffuseMatColor = vec3((float) 0xcc / 255, (float) 0x70 / 255, (float) 0xa3 / 255)
		, float specular = 0.5)
		:center(center), radius(radius), diffuseMatColor(diffuseMatColor), specular(specular)
	{}
	bool Intersect(Ray& ray, double& outT, IntersectInfo& info);

	vec3 center;
	float radius;
	vec3 diffuseMatColor;
	vec3 specularMatColor;
	float specular;
};

#endif