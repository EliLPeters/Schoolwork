#pragma once
#ifndef NEGATE_RED_IMAGE_EFFECT_H
#define NEGATE_RED_IMAGE_EFFECT_H

#include "ImageEffect.h"

// An Image Effect to negate all red in an image
class NegateRedImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc.getPixel(i, j);
				p.setRed(255 - p.getRed());
			}
		}
	}
};

#endif // !NEGATE_RED_IMAGE_EFFECT_H
