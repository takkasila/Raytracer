#include "Scene.h"

bool Scene::Intersect(Ray& ray, float& t)
{
	for (int f1 = 0; f1 < objs.size(); f1++)
	{
		if (objs[f1].Intersect(ray, t))
		{
			return true;
		}
	}

	return false;
}