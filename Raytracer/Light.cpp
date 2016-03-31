#include "Light.h"

float PointLight::IntensAtPoint(vec3 point)
{
	return intensity / pow(distance(point, pos), 2);
}