#ifndef INTERSECT_H
#define INTERSECT_H

class IntersectInfo
{
public:
	IntersectInfo(){}
	IntersectInfo(vec3 point, vec3 normal, vec3 diffuseMatColor = vec3(0, 0, 0))
		:point(point), normal(normal), diffuseMatColor(diffuseMatColor)
	{}
	
	vec3 point;
	vec3 normal;
	vec3 diffuseMatColor;
	vec3 center;
};

#endif