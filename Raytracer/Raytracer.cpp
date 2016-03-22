#include "Raytracer.h"
#include <stdio.h>
RayTracer::RayTracer()
{
}

vec3 RayTracer::trace(Ray ray, Scene scene)
{
	IntersectInfo info;
	if (scene.Intersect(ray, ray.t, info))
	{
		float intese = 1 / (pow(ray.t, 1));
		return mix(info.diffuseMatColor, vec3(1), 1 - intese);
	}
	else
		return scene.bgColor;
}