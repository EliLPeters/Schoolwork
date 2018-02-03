#pragma once
#ifndef FLIP_VERTICAL_IMAGE_EFFECT_H
#define FLIP_VERTICAL_IMAGE_EFFECT_H

#include "ImageEffect.h"

// An image effect to flip the pixels in an image vertically
class FlipVerticalImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		int midpoint = (doc.getHeight() / 2);

		for (int i = 0; i < doc.getWidth(); i++)
		{
			for (int j = 0; j < midpoint; j++)
			{
				Pixel temp = doc.getPixel(j, i);
				int opposite = (doc.getHeight() - 1 - j);

				doc.setPixel(j, i, doc.getPixel(opposite, i));
				doc.setPixel(opposite, i, temp);
			}
		}
	}
};

#endif // !FLIP_VERTICAL_IMAGE_EFFECT_H
