#pragma once
#ifndef REMOVE_BLUE_IMAGE_EFFECT_H
#define REMOVE_BLUE_IMAGE_EFFECT_H

#include "ImageEffect.h"

// Image Effect to remove all blue from a picture
class RemoveBlueImageEffect : public ImageEffect
{
	virtual void processImage(PpmDocument &doc)
	{
		for(int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc.getPixel(i, j);
				p.setBlue(0);
			}
		}
	}
};

#endif // !REMOVE_BLUE_IMAGE_EFFECT_H
