#include "Renderer.h"
#include <stdio.h>

void Renderer::Render()
{
	for (int f1 = 0; f1 < cam.film->height; f1++)
	{
		for (int f2 = 0; f2 < cam.film->width; f2++)
		{
			Ray ray = cam.GenerateRay((f2 + 0.5f) / cam.film->width, (f1 + 0.5f) / cam.film->height);
			cam.film->SetColor(f2, cam.film->height - f1-1, trace(ray));
		}

		// Checking progress
		if (f1 == (int) (cam.film->height / 4))
			printf("25%%\n");
		else if (f1 == (int) (cam.film->height / 2))
			printf("50%%\n");
		else if (f1 == (int) ((float) (2 * cam.film->height) / 3))
			printf("75%%\n");
	}
	cam.film->SaveImage("Image 1.png");
	cam.film->~Film();
}

vec3 Renderer::trace(Ray ray)
{
	vec3 white(1);
	vec3 black(0);

	IntersectInfo info;
	if (scene.Intersect(ray, ray.t, info))
	{
		Ray rayToLight(info.point + 0.01f*info.normal);

		vec3 totalColor(0);
		for (int f1 = 0; f1 < scene.lights.size(); f1++)
		{
			rayToLight.dir = normalize(scene.lights[f1].pos - rayToLight.point);
			IntersectInfo toLightInfo;
			if (!scene.Intersect(rayToLight, rayToLight.t, toLightInfo))
				totalColor += info.diffuseMatColor;
		}
		return totalColor;
	}
	else
		return scene.bgColor;
}