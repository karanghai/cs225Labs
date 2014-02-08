/**
 * @file image_tools.cpp
 * This file contains the implementation of the image tools; you
 *  will write your code in this file.
 */

#include "image_tools.h"

/**
 * Flips the source image into a new PNG.
 * THIS FUNCTION IS GRADED.
 * @todo - parallelize verticalFlip()
 * @param source - the original PNG
 * @return - a copy of the parameter that has been flipped
 *  over the vertical axis
 */
PNG ImageTools::verticalFlip(const PNG & source)
{
    int width = source.width();
    int height = source.height();
    PNG output(width, height);
#pragma omp parallel for
    for(int i = 0; i < width; ++i)
    {
        for(int j = 0; j < height; ++j)
        {
            // flip! 
		output(i,j)->red=source(width-i-1,j)->red;
		output(i,j)->green=source(width-i-1,j)->green;
		output(i,j)->blue=source(width-i-1,j)->blue;
		output(i,j)->alpha=source(width-i-1,j)->alpha;

        }
    }

    return output;
}

/**
 * Removes an RGB color component from the PNG.
 * THIS FUNCTION IS GRADED.
 * @todo - parallelize removeColor()
 * @param source - the original PNG
 * @param color - the color to remove
 * @return - a PNG object with an RGB component taken out
 *  of each pixel (if color parameter is valid)
 */
PNG ImageTools::removeColor(const PNG & source, const Color & color)
{
    int width = source.width();
    int height = source.height();
    PNG output(width, height);

#pragma omp parallel for
    for(int i = 0; i < width; ++i)
    {
        for(int j = 0; j < height; ++j)
        {
            *output(i, j) = *source(i, j);
            switch(color)
            {
                case RED:output(i,j)->red=0;
                    break;
                case GREEN:output(i,j)->green=0;
                    break;
                case BLUE:output(i,j)->blue=0;
                    break;
            }
        }
    }

    return output;
}
