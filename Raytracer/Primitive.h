#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "Shape.h"
#include "Material.h"
#include "IntersectInfo.h"

class Primitive
{
public:
	Primitive(Sphere sphere, Material material)
		:sphere(sphere), material(material)
	{}

	bool Intersect(Ray& ray, double& outT, IntersectInfo& info);
	Sphere sphere;
	Material material;
};
#endif