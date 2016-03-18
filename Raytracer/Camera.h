#ifndef CAMERA_H
#define CAMERA_H

#include "glm\glm.hpp"

using namespace glm;

class Camera
{
public:
	Camera(vec3 pos, vec3 dir, vec2 plane_res)
	{
		this->pos = pos;
		this->dir = dir;
		this->plane_res = plane_res;
	}
	vec3 pos;
	vec3 dir;
	vec2 plane_res;

private:

};

#endif