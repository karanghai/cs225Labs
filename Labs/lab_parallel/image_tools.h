/**
 * @file image_tools.h
 * Contains declarations for some simple image tools.
 */

#ifndef _IMAGE_TOOLS_H_
#define _IMAGE_TOOLS_H_

#include "png.h"

/**
 * A simple enumeration for colors.
 */
enum Color { RED, GREEN, BLUE };

/**
 * Contains various functions that can be performed on PNG objects.
 */
namespace ImageTools
{
    /**
     * Flips the source image into a new PNG.
     */
    PNG verticalFlip(const PNG & source);
    
    /**
     * Removes an RGB color component from the PNG.
     */
    PNG removeColor(const PNG & source, const Color & color);
}

#endif
