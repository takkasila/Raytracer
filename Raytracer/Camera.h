#ifndef CAMERA_H
#define CAMERA_H
# define M_PI           3.14159265358979323846

#include "glm\glm.hpp"
#include "glm\gtx\rotate_vector.hpp"
#include "Ray.h"

using namespace glm;

class Camera
{
public:
	Camera(vec3 pos = vec3(0, 0, 0)
		, float aspectRatio = (float)5/4, float fovx = 60, float nearZplane = 0.3f)
		:pos(pos), dir(normalize(vec3(0, 0, -1))), up(vec3(0, 1, 0))
		, aspectRatio(aspectRatio), fovx(fovx), nearZplane(nearZplane)
	{
		UpdateCamera(pos, aspectRatio, fovx, nearZplane);
	}

	void UpdateCamera(vec3 pos, float aspectRatio, float fovx, float nearZplane);
	void Rotate(vec3 rotation);
	Ray GenerateRay(float i, float j);

	vec3 pos;
	float aspectRatio;
	float fovx;
	float nearZplane;

private:
	vec3 dir;
	vec3 up;
	vec3 worldScreenSpace;
	vec3 horizonFactor;
	vec3 verticleFactor;
};

#endif