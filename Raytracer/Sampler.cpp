#include "Sampler.h"

void Sampler::SetSampler(int x, int y)
{
	ResetSampler();
	samplingPointX = x;
	samplingPointY = y;
}

Ray Sampler::GetSamplingRay()
{
	Ray ray = camera.GenerateRay(
		(samplingPointX + samplingX) / camera.film->width
		, (samplingPointY + samplingY) / camera.film->height);

	counterX++;
	if (counterX >= nSamplingX)
	{
		if (counterY < nSamplingY - 1)
			counterX = 0;
		else
			counterX = nSamplingX - 1;

		counterY++;
		if (counterY >= nSamplingY)
			counterY = nSamplingY - 1;
	}

	samplingX = 1 / (float) (2 * nSamplingX) + counterX * deltaX;
	samplingY = 1 / (float) (2 * nSamplingY) + counterY * deltaY;

	return ray;
}

void Sampler::ResetSampler()
{
	counterX = counterY = 0;
	samplingX = 1 / (float) (2 * nSamplingX);
	samplingY = 1 / (float) (2 * nSamplingY);
}

int Sampler::GetSamplingTimes()
{
	return nSamplingX * nSamplingY;
}