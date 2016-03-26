#include "Light.h"

float Light::IntensAtPoint(vec3 point)
{
	return Intensity/pow(distance(point, pos) ,2);
}