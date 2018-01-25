#pragma once
#ifndef NEGATE_BLUE_IMAGE_EFFECT_H
#define NEGATE_BLUE_IMAGE_EFFECT_H

#include "ImageEffect.h"

// An Image Effect to negate all blue in an image
class NegateBlueImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc.getPixel(i, j);
				p.setBlue(255 - p.getBlue());
			}
		}
	}
};

#endif // !NEGATE_BLUE_IMAGE_EFFECT_H
