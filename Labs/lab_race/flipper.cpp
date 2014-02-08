/**
 * @file flipper.cpp
 * This is where you will write the code to flip the image.
 */

#include "flipper.h"

/**
 * Flips an image around a horizontal axis in-place.
 * @param image - the image to flip
 */
void Flipper::flipSerial(PNG & image)
{
    RGBAPixel temp;
    int height = image.height(); 
    int width = image.width();
    
    for(int i = 0; i < width; ++i)
    {
        for(int j = 0; j < height / 2; ++j)
        {
            temp = *image(i, j);
            *image(i, j) = *image(i, height - 1 - j);
            *image(i, height - 1 - j) = temp;
        }
    }
}

/**
 * Flips an image around a horizontal axis in-place.
 * @param image - the image to flip
 */
void Flipper::flipParallel(PNG & image)
{
    int height = image.height(); 
    int width = image.width();
    
    #pragma omp parallel for
    for(int i = 0; i < width; ++i)
    {
        for(int j = 0; j < height / 2; ++j)
        {
            RGBAPixel temp;
		temp = *image(i, j);
            *image(i, j) = *image(i, height - 1 - j);
            *image(i, height - 1 - j) = temp;
        }
    }
}

/**
 * Makes sure that the flipped.png matches soln_flipped.png
 * @param image - the image to test
 * @return - whether it matches soln_flipped.png
 */
bool Flipper::checkCorrectness(const PNG & image)
{
    PNG solution;
    solution.readFromFile("soln_flipped.png");
    return solution == image;
}

