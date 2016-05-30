#ifndef INTERSECT_H
#define INTERSECT_H

#include "Material.h"
class Shape;

class IntersectInfo
{
public:
	IntersectInfo(){}
	IntersectInfo(vec3 surfacePoint, vec3 surfaceNormal, Material mat)
		:surfacePoint(surfacePoint), surfaceNormal(surfaceNormal), material(material)
	{}
	vec3 surfacePoint;
	vec3 surfaceNormal;
	Material material;
	const Shape* shape;
};
#endif