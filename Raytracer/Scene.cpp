#include "Scene.h"

bool Scene::Intersect(Ray& ray, float& t, IntersectInfo& info)
{
	float minT = t;
	bool isHit = false;

	IntersectInfo tempInfo;
	for (int f1 = 0; f1 < objs.size(); f1++)
	{
		if (objs[f1].Intersect(ray, minT, tempInfo))
		{
			// First hit
			if (isHit == false)
			{
				isHit = true;
				t = minT;
				info = tempInfo;
			}

			if (t > minT)
			{
				t = minT;
				info = tempInfo;
			}
		}
	}
	return isHit;
}