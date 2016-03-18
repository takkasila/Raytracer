#ifndef SHAPE_H
#define SHAPE_H

#include "Ray.h"
class Shape
{
public:
	virtual bool intersect(Ray& ray, float& outT);

};

class Sphere
{
public:
	Sphere(vec3 center, float radius)
	{
		this->center = center;
		this->radius = radius;
	}
	bool intersect(Ray& ray, float& outT)
	{
		vec3 centerToPoint = ray.point - center;
		float a = dot(ray.dir, ray.dir);
		float b = 2 * dot(ray.dir, centerToPoint);
		float c = dot(centerToPoint, centerToPoint) - (radius*radius);

		// Solve quadratic equation
		float det = b*b - 4 * a*c;
		if (det < 0)
			return false;

		float root1 = -b + sqrt(det) / (2 * a);
		float root2 = -b - sqrt(det) / (2 * a);

		// Check result
		if (root1 > 0 && root2 > 0)
			outT = min(root1, root2);
		else
			outT = max(root1, root2);

		return true;
	}
	vec3 center;
	float radius;

private:

};

#endif