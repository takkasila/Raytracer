#ifndef MATERIAL_H
#define MATERIAL_H

#include "glm\glm.hpp"
using namespace glm;	
class Material
{
public:

	Material(vec3 diffuse = vec3(1, 1, 1), float diffuseFac = 1, float shininess = 1)
		:diffuse(diffuse), diffuseFac(diffuseFac), shininess(shininess)
	{}
	vec3 diffuse;
	float diffuseFac;
	float shininess;
};

#endif