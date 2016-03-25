#include "Raytracer.h"
#include <stdio.h>
RayTracer::RayTracer()
{
}

vec3 RayTracer::trace(Ray ray, Scene scene)
{
	vec3 lightPos(0, 4, -2);
	vec3 white(1);
	vec3 black(0);
	vec3 yellow(1, 0, 1);

	IntersectInfo info;
	if (scene.Intersect(ray, ray.t, info))
	{
		Ray rayToLight(info.point + 0.01f*info.normal);
		rayToLight.dir = normalize(lightPos - rayToLight.point);

		IntersectInfo toLightInfo;
		if (!scene.Intersect(rayToLight, rayToLight.t, toLightInfo))
			return info.diffuseMatColor;
		else
			return black;

	}
	else
		return scene.bgColor;
}