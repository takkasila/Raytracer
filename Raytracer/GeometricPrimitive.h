#ifndef GEOPRIM_H
#define GEOPRIM_H
#include "Ray.h"

class GeometricPrimitive
{
public:
	virtual bool intersect(Ray& ray, float& outT);


};

#endif