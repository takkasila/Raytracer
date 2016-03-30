#ifndef MATERIAL_H
#define MATERIAL_H

#include "glm\glm.hpp"
using namespace glm;	
class Material
{
public:

	Material(vec3 diffuse = vec3(1, 1, 1), float diffuseCoeff = 0.85
		, float specularPowFactor = 128, float specularCoeff = 0.5)
		:diffuse(diffuse), diffuseCoeff(diffuseCoeff), specularPowFactor(specularPowFactor)
		, specularCoeff(specularCoeff)
	{}
	vec3 diffuse;
	float diffuseCoeff;
	float specularPowFactor; // pow fac range from 1 to infinite
	float specularCoeff; // range from 0 to 1
	
};

#endif