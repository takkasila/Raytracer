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
	//if (abs(outT) < 0.0001)
	//return false;

	info.point = ray.point + ray.dir * (float) outT;
	info.diffuseMatColor = diffuseMatColor;
	info.normal = normalize(info.point - center);
	info.center = center;

	return true;
}