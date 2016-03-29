#include "Primitive.h"

bool Primitive::Intersect(Ray& ray, double& outT, IntersectInfo& info)
{
	if (sphere.Intersect(ray, outT))
	{
		info.surfacePoint = ray.point + ray.dir * (float) outT;
		info.surfaceNormal = normalize(info.surfacePoint - sphere.center);
		info.material = this->material;
		return true;
	}
	else
		return false;
}