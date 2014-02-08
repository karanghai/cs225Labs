/**
 * @file flipper.h
 * This is a namespace for the image flipping code.
 * You should only have to edit flipper.cpp. 
 */

#ifndef _FLIPPER_H_
#define _FLIPPER_H_

#include <omp.h>
#include "png.h"

/**
 * Contains flipping and flipping correctness utilities.
 */
namespace Flipper
{
    /**
     * Flips an image around a horizontal axis in-place.
     * @param image - the image to flip
     */
    void flipSerial(PNG & image);

    /**
     * Flips an image around a horizontal axis in-place.
     * @param image - the image to flip
     */
    void flipParallel(PNG & image);

    /**
     * Makes sure that the flipped.png matches soln_flipped.png
     * @param image - the image to test
     * @return - whether it matches soln_flipped.png
     */
    bool checkCorrectness(const PNG & image);
}

#endif
