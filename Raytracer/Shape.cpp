#include "Shape.h"

bool Sphere::Intersect(Ray& ray, double& outT, IntersectInfo& info)
{
	vec3 centerToPoint = ray.point - center;
	double a = dot(ray.dir, ray.dir);
	double b = 2 * dot(ray.dir, centerToPoint);
	double c = dot(centerToPoint, centerToPoint) - (radius*radius);

	// Solve quadratic equation
	double det = b*b - 4 * a*c;
	if (det < 0.0f)
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
	// Point in plane
	float tempT = (dot(p1, faceNormal) - dot(ray.point, faceNormal))/ dot(ray.dir, faceNormal);

	// Check point inside
	//dista

	return false;
}