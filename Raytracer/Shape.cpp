#include "Shape.h"
#include <stdio.h>
bool Sphere::Intersect(Ray& ray, double& outT, IntersectInfo& info)
{
	vec3 centerToPoint = ray.point - center;
	double a = dot(ray.dir, ray.dir);
	double b = 2 * dot(ray.dir, centerToPoint);
	double c = dot(centerToPoint, centerToPoint) - (radius*radius);

	// Solve quadratic equation
	double det = b*b - 4 * a*c;
	if (det < 0)
		return false;

	double root1 = (-b + sqrt(det)) / (2 * a);
	double root2 = (-b - sqrt(det)) / (2 * a);

	// Check result
	if (root1 > 0 && root2 > 0)
		outT = min(root1, root2);
	else
		outT = max(root1, root2);

	if (outT < 0)
		return false;

	info.surfacePoint = ray.point + ray.dir * (float) outT;
	info.surfaceNormal = normalize(info.surfacePoint - center);

	return true;
}

bool Triangle::Intersect(Ray& ray, double& outT, IntersectInfo& info)
{
	vec3 pvec = cross(ray.dir, p1p3);
	float det = dot(p1p2, pvec);

	// Backface culling
	if (det <= 0)
		return false;

	float invDet = 1 / det;

	vec3 tvec = ray.point - p1;
	float u = dot(tvec, pvec) * invDet;
	if (u < 0 || u>1)
		return false;

	vec3 qvec = cross(tvec, p1p2);
	float v = dot(ray.dir, qvec) * invDet;
	if (v < 0 || v>1)
		return false;

	if (u + v > 1)
		return false;

	outT = dot(p1p3, qvec) *invDet;
	info.surfacePoint = ray.point + ray.dir *(float) outT;
	info.surfaceNormal = faceNormal;
	return true;
}