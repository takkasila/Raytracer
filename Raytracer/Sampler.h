#ifndef SAMPLE_H
#define SAMPLE_H

#include "Camera.h"

class Sampler
{
public:
	Sampler(Camera camera, int nSamplingX = 1, int nSamplingY = 1)
		:camera(camera), nSamplingX(nSamplingX), nSamplingY(nSamplingY)
	{
		deltaX = 1 / (float) nSamplingX;
		deltaY = 1 / (float) nSamplingY;
	}
	
	void SetSampler(int x, int y);
	Ray GetSamplingRay();
	void ResetSampler();
	int GetSamplingTimes();

private:
	Camera camera;
	int nSamplingX;
	int nSamplingY;
	float deltaX;
	float deltaY;
	float samplingX;
	float samplingY;

	int samplingPointX;
	int samplingPointY;
	int counterX;
	int counterY;
};

#endif