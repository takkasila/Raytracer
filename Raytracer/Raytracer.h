#ifndef RAYTRACER_H
#define RAYTRACER_H
#include "glm\glm.hpp"
#include "Ray.h"
#include "Shape.h"

using namespace glm;

class RayTracer
{
public:
	RayTracer();
	vec3 trace(Ray ray, Sphere sphere);
private:

};

#endif