#include "Renderer.h"
#include <stdio.h>

void Renderer::Render()
{
	for (int f1 = 0; f1 < cam.film->height; f1++)
	{
		for (int f2 = 0; f2 < cam.film->width; f2++)
		{
			Ray ray = cam.GenerateRay((f2 + 0.5f) / cam.film->width, (f1 + 0.5f) / cam.film->height);

			IntersectInfo info;
			if (scene.Intersect(ray, ray.t, info))
			{
				// Hit obj
				cam.film->SetColor(f2, cam.film->height - f1 - 1, EvaluateLight(ray, info));
			}
			else
			{
				// Not hit obj
				cam.film->SetColor(f2, cam.film->height - f1-1, scene.bgColor);
			}

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


vec3 Renderer::EvaluateLight(Ray ray, IntersectInfo info)
{

	Ray rayToLight(info.point + 0.01f*info.normal);
	vec3 totalColor(0);
	for (int f1 = 0; f1 < scene.lights.size(); f1++)
	{
		rayToLight.dir = normalize(scene.lights[f1].pos - rayToLight.point);
		IntersectInfo toLightInfo;
		if (!scene.Intersect(rayToLight, rayToLight.t, toLightInfo))
		{
			// Diffuse
			float dotProd = max(0.f, dot(info.normal, rayToLight.dir));
			vec3 diffuseTerm = info.diffuseMatColor * scene.lights[f1].IntensAtPoint(info.point)* dotProd;
			totalColor += diffuseTerm;
		}
	}
	vec3 ambientTerm = scene.ambientColor * scene.ambientIntense * info.diffuseMatColor;
	totalColor += ambientTerm;
	return totalColor;
}