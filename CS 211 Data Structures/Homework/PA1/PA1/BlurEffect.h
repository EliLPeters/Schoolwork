#pragma once
#ifndef BLUR_EFFECT_H
#define BLUR_EFFECT_H

#include "ImageEffect.h"

// Effect to blur the image
class BlurEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		// Horizontal
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc.getPixel(i, j);

				if (j == 0)
				{
					Pixel right = doc.getPixel(i, (j + 1));

					p.setRed((p.getRed() + right.getRed()) / 2);
					p.setGreen((p.getGreen() + right.getGreen()) / 2);
					p.setBlue((p.getBlue() + right.getBlue()) / 2);
				}
				else if ((j > 0) && (j < (doc.getWidth() - 2)))
				{
					Pixel right = doc.getPixel(i, (j + 1));
					Pixel left = doc.getPixel(i, (j - 1));

					p.setRed((left.getRed() + p.getRed() + right.getRed()) / 3);
					p.setGreen((left.getGreen() + p.getGreen() + right.getGreen()) / 3);
					p.setBlue((left.getBlue() + p.getBlue() + right.getBlue()) / 3);
				}
				else
				{
					Pixel left = doc.getPixel(i, (j - 1));

					p.setRed((p.getRed() + left.getRed()) / 2);
					p.setGreen((p.getGreen() + left.getGreen()) / 2);
					p.setBlue((p.getBlue() + left.getBlue()) / 2);
				}
			}
		}

		// Vertical
		for (int i = 0; i < doc.getWidth(); i++)
		{
			for (int j = 0; j < doc.getHeight(); j++)
			{
				Pixel& p = doc.getPixel(j, i);

				if (j == 0)
				{
					Pixel down = doc.getPixel((j + 1), i);

					p.setRed((p.getRed() + down.getRed()) / 2);
					p.setGreen((p.getGreen() + down.getGreen()) / 2);
					p.setBlue((p.getBlue() + down.getBlue()) / 2);
				}
				else if ((j > 0) && (j < (doc.getHeight() - 2)))
				{
					Pixel down = doc.getPixel((j + 1), i);
					Pixel up = doc.getPixel((j - 1), i);

					p.setRed((up.getRed() + p.getRed() + down.getRed()) / 3);
					p.setGreen((up.getGreen() + p.getGreen() + down.getGreen()) / 3);
					p.setBlue((up.getBlue() + p.getBlue() + down.getBlue()) / 3);
				}
				else
				{
					Pixel up = doc.getPixel((j - 1), i);

					p.setRed((p.getRed() + up.getRed()) / 2);
					p.setGreen((p.getGreen() + up.getGreen()) / 2);
					p.setBlue((p.getBlue() + up.getBlue()) / 2);
				}
			}
		}
	}
};


#endif // !BLUR_EFFECT_H
