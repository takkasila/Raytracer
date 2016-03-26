#ifndef LIGHT_H
#define LIGHT_H

class Light
{
public:
	Light(vec3 pos = vec3(0, 5, 0), vec3 color = vec3(1), float atten = 1)
		:pos(pos), color(color), atten(atten)
	{
	}

	vec3 pos;
	vec3 color;
	float atten;
};

#endif