#include "Scene.h"

bool Scene::Intersect(Ray& ray, float& t)
{
	// Need fix soon
	t = 999999;
	float tempT = t;
	bool isHit = false;
	for (int f1 = 0; f1 < objs.size(); f1++)
	{
		if (objs[f1].Intersect(ray, tempT))
		{
			isHit = true;
			if (t > tempT)
				t = tempT;
		}
	}
	
	return isHit;
}