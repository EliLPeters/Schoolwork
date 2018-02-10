#pragma once
#ifndef FLIP_HORIZONTAL_IMAGE_EFFECT_H
#define FLIP_HORIZONTAL_IMAGE_EFFECT_H

#include "ImageEffect.h"

// An image effect to flip the pixels in an image horizontally
class FlipHorizontalImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		int midpoint = (doc.getWidth() / 2);

		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < midpoint; j++)
			{
				Pixel temp = doc.getPixel(i, j);
				int opposite = (doc.getWidth() - j - 1);

				doc.setPixel(i, j, doc.getPixel(i, opposite));
				doc.setPixel(i, opposite, temp);
			}
		}
	}
};

#endif // !FLIP_HORIZONTAL_IMAGE_EFFECT_H
