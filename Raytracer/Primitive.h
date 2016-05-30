#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "Shape.h"
#include "Material.h"
#include "IntersectInfo.h"

class Primitive
{
public:
	Primitive(Shape& shape, Material material)
		:shape(shape), material(material)
	{}

	bool Intersect(Ray& ray, double& outT, IntersectInfo& info);
	Shape& shape;
	Material material;

};
#endif