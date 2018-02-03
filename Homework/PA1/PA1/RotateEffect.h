#pragma once
#ifndef ROTATE_EFFECT_H
#define ROTATE_EFFECT_H

#include "ImageEffect.h"

// rotates the image 90 degrees
class RotateEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		PpmDocument clone = PpmDocument( "P3", doc.getWidth(), doc.getHeight(), 255);
		
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				clone.setPixel(i, j, doc.getPixel(i, j));
			}
		}

		doc.setHeight(clone.getWidth());
		doc.setWidth(clone.getHeight());

		for (int i = 0; i < clone.getHeight(); i++)
		{
			for (int j = 0; j < clone.getWidth(); j++)
			{
				int target_col = (doc.getWidth() - i - 1);

				doc.setPixel(j, target_col, clone.getPixel(i, j));
			}
		}
	}
};

#endif // !ROTATE_EFFECT_H
