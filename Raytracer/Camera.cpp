#include "Camera.h"

void Camera::UpdateCamera(vec3 pos, float aspectRatio, float fovx, float nearZplane)
{
	vec2 planeSize;
	planeSize.x = 2*tan(fovx/2 * M_PI/180) * nearZplane;
	planeSize.y = planeSize.x / aspectRatio;

	vec3 planeLeft = planeSize.x/2 * normalize(cross(up, dir));
	vec3 planeUp = planeSize.y/2 * up;
	
	worldScreenSpace = pos + dir * nearZplane + planeLeft + planeUp;

	horizonFactor = planeSize.x * normalize(-planeLeft);
	verticleFactor = planeSize.y * normalize(-up);

	int xx = 1;
}

Ray Camera::GenerateRay(float i, float j)
{
	return Ray(pos, worldScreenSpace + i*horizonFactor + j*verticleFactor, 1);
}