#ifndef SHAPE_H
#define SHAPE_H

#include "Ray.h"
#include "IntersectInfo.h"

class Shape
{
public:
	Shape(){}
	virtual bool Intersect(Ray& ray, double& outT, IntersectInfo& info)=0;
};

class Sphere : public Shape
{
public:
	Sphere(vec3 center = vec3(0, 0, 0), float radius = 1)
		:center(center), radius(radius)
	{}
	bool Intersect(Ray& ray, double& outT, IntersectInfo& info);
	
	vec3 center;
	float radius;
};


class Triangle : public Shape
{
public:
	Triangle(vec3 p1 = vec3(0, 0, 0), vec3 p2 = vec3(1, 0, 0), vec3 p3 = vec3(0, 1, 0))
		:p1(p1), p2(p2), p3(p3)
	{
		vec3 edge1 = p2 - p1;
		vec3 edge2 = p3 - p1;
		faceNormal = normalize(cross(edge1, edge2));
	}
	bool Intersect(Ray& ray, double& outT, IntersectInfo& info);

	vec3 p1, p2, p3;
	vec3 faceNormal;
};

class TriangleMesh : public Shape
{
public:
	bool Intersect(Ray& ray, double& outT, IntersectInfo& info);
};

#endif