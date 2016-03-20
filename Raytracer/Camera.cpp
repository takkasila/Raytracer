#include "Camera.h"

void Camera::UpdateCamera(vec3 pos, float aspectRatio, float fovx, float nearZplane)
{
	vec2 planeSize;
	planeSize.x = 2*tan(fovx/2 * M_PI/180) * nearZplane;
	planeSize.y = planeSize.x / aspectRatio;

	vec3 planeLeft = planeSize.x/2 * normalize(cross(up, dir));
	vec3 planeUp = planeSize.y/2 * up;
	
	worldScreenSpace = dir * nearZplane + planeLeft + planeUp;

	horizonFactor = planeSize.x * normalize(-planeLeft);
	verticleFactor = planeSize.y * normalize(-up);
	int xx = 1;
}

Ray Camera::GenerateRay(float i, float j)
{
	return Ray(pos, normalize( worldScreenSpace + i*horizonFactor + j*verticleFactor ), 1);
}

void Camera::Rotate(vec3 rotation)
{
	//vec3 v1(1, 0, 0);
	//v1 = rotateY(v1,(float) M_PI/2);
	rotation *= M_PI / 180;
	dir = rotateX(dir, rotation.x);
	dir = rotateY(dir, rotation.y);
	dir = rotateZ(dir, rotation.z);

	up = rotateX(up, rotation.x);
	up = rotateY(up, rotation.y);
	up = rotateZ(up, rotation.z);

	UpdateCamera(pos, aspectRatio, fovx, nearZplane);
}