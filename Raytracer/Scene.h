#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "Shape.h"

using namespace std;

class Scene
{
public:
	Scene()
	{
	}
	vector<Sphere> objs;
	bool Intersect(Ray& ray, float& t);

private:

};

#endif