#include "Raytracer.h"

RayTracer::RayTracer()
{
}

vec3 RayTracer::trace(Ray ray, Sphere sphere)
{
	float t;
	if (sphere.intersect(ray, t))
		return vec3(1, 0, 0);
	else
		return vec3(0, 0, 0);
}