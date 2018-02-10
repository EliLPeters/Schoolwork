#pragma once
#ifndef PIXELATE_EFFECT_H
#define PIXELATE_EFFECT_H

#include "ImageEffect.h"

// Image effect to pixilate
class PixelateEffect : public ImageEffect
{
	int pixel_size = 5;

	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; (i + pixel_size) <= doc.getHeight(); i += pixel_size)
		{
			for (int j = 0; (j + pixel_size) <= doc.getWidth(); j += pixel_size)
			{
				Pixel copied = doc.getPixel(i, j);
				// aaaaaaaaaahhhhh
				for (int k = 0; k < pixel_size; k++)
				{
					// this is an abomination against God and Man
					for (int l = 0; l < pixel_size; l++)
					{
						Pixel& p = doc.getPixel((i + k), (j + l));

						p.setRed(copied.getRed());
						p.setGreen(copied.getGreen());
						p.setBlue(copied.getBlue());
					}
				}
			}
		}
	}
};

#endif // !PIXELATE_EFFECT_H
