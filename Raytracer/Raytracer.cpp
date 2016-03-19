#include "Raytracer.h"
#include <stdio.h>
RayTracer::RayTracer()
{
}

vec3 RayTracer::trace(Ray ray, Scene scene)
{
	float t;
	vec3 color((float) 0xcc / 255, (float) 0x70 / 255, (float) 0xa3 / 255);
	vec3 bg((float) 224 / 255, (float) 230 / 255, (float) 237 / 255);
	if (scene.Intersect(ray, t))
	{
		float intese = 1 / (pow(t,1));
		return mix(color, vec3(1, 1, 1), 1 - intese);
	}
	else
		return bg;
}