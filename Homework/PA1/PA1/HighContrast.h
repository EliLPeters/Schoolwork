#pragma once
#ifndef HIGH_CONTRAST_H
#define HIGH_CONTRAST_H

#include "ImageEffect.h"

class HighContrast : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc.getPixel(i, j);

				if (p.getRed() > 128)
				{
					p.setRed(255);
				}
				else
				{
					p.setRed(0);
				}

				if (p.getBlue() > 128)
				{
					p.setBlue(255);
				}
				else
				{
					p.setBlue(0);
				}

				if (p.getGreen() > 128)
				{
					p.setGreen(255);
				}
				else
				{
					p.setGreen(0);
				}

			}
		}
	}
};

#endif // !HIGH_CONTRAST_H
