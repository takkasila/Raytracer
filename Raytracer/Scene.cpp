#include "Scene.h"

bool Scene::Intersect(Ray& ray, float& t)
{
	float minT = t;
	bool isHit = false;
	for (int f1 = 0; f1 < objs.size(); f1++)
	{
		if (objs[f1].Intersect(ray, minT))
		{
			// First hit
			if (isHit == false)
			{
				isHit = true;
				t = minT;
			}

			if (t > minT)
				t = minT;
		}
	}
	return isHit;
}