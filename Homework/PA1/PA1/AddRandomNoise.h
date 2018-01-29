#pragma once
#ifndef ADD_RANDOM_NOISE_H
#define ADD_RANDOM_NOISE_H

#include <cstdlib>
#include "ImageEffect.h"

// This image effect will add random noise to an image
class AddRandomNoise : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				int noise = ((rand() % 21) - 10);
				
				Pixel& p = doc.getPixel(i, j);

				if ((p.getRed() + noise) > 255)
				{
					p.setRed(255);
				}
				else if ((p.getRed() + noise) < 0)
				{
					p.setRed(0);
				}
				else
				{
					p.setRed(p.getRed() + noise);
				}

				if ((p.getBlue() + noise) > 255)
				{
					p.setBlue(255);
				}
				else if ((p.getBlue() + noise) < 0)
				{
					p.setBlue(0);
				}
				else
				{
					p.setBlue(p.getBlue() + noise);
				}

				if ((p.getGreen() + noise) > 255)
				{
					p.setGreen(255);
				}
				else if ((p.getGreen() + noise) < 0)
				{
					p.setGreen(0);
				}
				else
				{
					p.setRed(p.getGreen() + noise);
				}
			}
		}
	}
};

#endif // !ADD_RANDOM_NOISE_H

