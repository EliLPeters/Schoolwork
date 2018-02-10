#pragma once
#ifndef NEGATE_GREEN_IMAGE_EFFECT_H
#define NEGATE_GREEN_IMAGE_EFFECT_H

#include "ImageEffect.h"

// An Image Effect to negate all green in an image
class NegateGreenImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc.getPixel(i, j);
				p.setGreen(255 - p.getGreen());
			}
		}
	}
};

#endif // !NEGATE_GREEN_IMAGE_EFFECT_H
