#pragma once
#ifndef GRAYSCALE_EFFECT_H
#define GRAYSCALE_EFFECT_H

#include "ImageEffect.h"

class GrayscaleEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i; i < doc.getHeight(); i++)
		{
			for (int j; j < doc.getWidth(); j++)
			{
				Pixel& p = doc.getPixel(i, j);

				int average = ((p.getRed() + p.getBlue() + p.getGreen()) / 3);

				p.setRed(average);
				p.setBlue(average);
				p.setGreen(average);
			}
		}
	}
};

#endif // !GRAYSCALE_EFFECT_H
