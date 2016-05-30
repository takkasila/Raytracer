#include "Primitive.h"

bool Primitive::Intersect(Ray& ray, double& outT, IntersectInfo& info)
{
	if (shape.Intersect(ray, outT, info))
	{
		info.material = this->material;
		return true;
	}
	else
		return false;
}