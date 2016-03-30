#include "Renderer.h"
#include <stdio.h>

void Renderer::Render()
{
	for (int f1 = 0; f1 < cam.film->height; f1++)
	{
		for (int f2 = 0; f2 < cam.film->width; f2++)
		{
			cam.film->SetColor(f2, cam.film->height - f1 - 1, EvaluateLight(f2, f1));
		}

		// Checking progress
		if (f1 == (int) (cam.film->height / 4))
			printf("25%%\n");
		else if (f1 == (int) (cam.film->height / 2))
			printf("50%%\n");
		else if (f1 == (int) ((float) (2 * cam.film->height) / 3))
			printf("75%%\n");
	}
	printf("100%%\n");
	cam.film->SaveImage("Image 1.png");
	cam.film->~Film();
}


vec3 Renderer::EvaluateLight(int x, int y)
{
	vec3 totalColor(0);
	sampler.SetSampler(x, y);
	for (int i = 0; i < sampler.GetSamplingTimes(); i++)
	{
		Ray ray = sampler.GetSamplingRay();
		IntersectInfo info;
	
		if (scene.Intersect(ray, ray.t, info))
		{
			// Hit obj
			totalColor += Shading(ray, info);
		}
		else
		{
			// Not hit obj
			totalColor += scene.bgColor;
		}
	}

	return totalColor / (float)sampler.GetSamplingTimes();
}


vec3 Renderer::Shading(Ray& ray, IntersectInfo info)
{
	Ray rayToLight(info.surfacePoint + 0.01f*info.surfaceNormal);
	vec3 totalColor(0);
	for each (Light light in scene.lights)
	{
		rayToLight.dir = normalize(light.pos - rayToLight.point);
		IntersectInfo toLightInfo;
		if (!scene.Intersect(rayToLight, rayToLight.t, toLightInfo))
		{
			// Diffuse
			float dotProd = max(0.f, dot(info.surfaceNormal, rayToLight.dir));
			vec3 diffuseTerm = info.material.diffuse * light.IntensAtPoint(info.surfacePoint)* dotProd;
			totalColor += diffuseTerm * info.material.diffuseCoeff;

			// Specular
			vec3 pointToView = normalize(cam.pos - info.surfacePoint);
			vec3 halfVec = normalize(pointToView + rayToLight.dir);
			float specAngle = max(dot(halfVec, info.surfaceNormal), 0.f);

			totalColor += light.color * light.IntensAtPoint(info.surfacePoint)
				*info.material.specularCoeff * pow(specAngle, info.material.specularPowFactor);
		}
	}

	vec3 ambientTerm = scene.ambientColor * scene.ambientIntense * info.material.diffuse;
	totalColor += ambientTerm;
	return totalColor;
}