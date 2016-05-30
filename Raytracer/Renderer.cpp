#include "Renderer.h"
#include <stdio.h>

void Renderer::Render()
{
	float status;
	for (int f1 = 0; f1 < cam.film->height; f1++)
	{
		for (int f2 = 0; f2 < cam.film->width; f2++)
		{
			cam.film->SetColor(f2, cam.film->height - f1 - 1, EvaluatePointLight(f2, f1));
		}

		//// Checking progress
		status = ((f1 / (float) cam.film->height) * 10);
		if ( status == floorf(status))
			printf("%d%%\n", (int)(status*10));

	}
	printf("100%%\n");
	cam.film->SaveImage("Image 1.png");
	cam.film->~Film();
}


vec3 Renderer::EvaluatePointLight(int x, int y)
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
			totalColor += Shading(ray, info, maxDepth);
			// Ambient
			vec3 ambientTerm = scene.bgColor * scene.ambientIntense * info.material.diffuse;
			totalColor += ambientTerm;
		}
		else
		{
			// Not hit obj
			totalColor += scene.bgColor;
		}
	}

	return totalColor / (float)sampler.GetSamplingTimes();
}


vec3 Renderer::Shading(Ray& ray, IntersectInfo info, int depth)
{
	vec3 totalColor(0);
	Ray rayToPointLight(info.surfacePoint + info.surfaceNormal);
	vec3 pointToView = normalize(cam.pos - rayToPointLight.point);

	// Directional Light
	rayToPointLight.dir = -scene.directionalLight.dir;
	IntersectInfo dLightInfo;
	if (!scene.Intersect(rayToPointLight, rayToPointLight.t, dLightInfo))
	{
		// Diffuse
		float dotProd = max(0.f, dot(info.surfaceNormal, rayToPointLight.dir));
		vec3 diffuseTerm = info.material.diffuse * scene.directionalLight.intensity * dotProd;
		totalColor += diffuseTerm * info.material.diffuseCoeff;
	}

	for each (PointLight PointLight in scene.PointLights)
	{
		rayToPointLight.dir = normalize(PointLight.pos - rayToPointLight.point);
		IntersectInfo toPointLightInfo;
		bool isIntersect = scene.Intersect(rayToPointLight, rayToPointLight.t, toPointLightInfo);
		if (!isIntersect || rayToPointLight.t > abs( glm::distance(rayToPointLight.point, PointLight.pos)))
		{
			// Diffuse
			float dotProd = max(0.f, dot(info.surfaceNormal, rayToPointLight.dir));
			vec3 diffuseTerm = info.material.diffuse * PointLight.IntensAtPoint(info.surfacePoint)* dotProd;
			totalColor += diffuseTerm * info.material.diffuseCoeff;

			// Specular
			vec3 halfVec = normalize(pointToView + rayToPointLight.dir);
			float specAngle = max(dot(halfVec, info.surfaceNormal), 0.f);

			totalColor += PointLight.color * PointLight.IntensAtPoint(info.surfacePoint)
				*info.material.specularCoeff * pow(specAngle, info.material.specularPowFactor);
		}
	}

	if (--depth <= 0)
		return totalColor;

	// Recursive
	Ray recurRay(rayToPointLight.point, normalize(reflect(ray.dir, info.surfaceNormal)));
	IntersectInfo recursiveInfo;
	if (scene.Intersect(recurRay, recurRay.t, recursiveInfo))
	{
		// Hit obj
		totalColor += info.material.specularCoeff * Shading(recurRay, recursiveInfo, depth);
	}
	else
	{
		totalColor += info.material.specularCoeff * scene.bgColor;
	}
	return totalColor;
}