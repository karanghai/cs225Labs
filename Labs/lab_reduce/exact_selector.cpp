/**
 * @file exact_selector.cpp
 * Implementation for the exact_selector function object.
 *
 * @author Chase Geigle
 * @date Spring 2012
 */

#include "exact_selector.h"

/**
 * Constructs an exact selector, using the given pixel reference as
 * the base for comparing other pixels in operator().
 *
 * @param pixel The pixel to do all comparisons against after
 *              construction.
 */
exact_selector::exact_selector( const RGBAPixel & pixel ) {
	_pixel = pixel;
}

/**
 * Selection function: determines if the parameterized pixel is
 * exactly equivalent to the pixel given on construction.
 *
 * @param pixel Pixel to compare against.
 * @return Whether pixel is exactly equivalent to the original
 *         pixel.
 */
bool exact_selector::operator()( const RGBAPixel & pixel ) {
	return _pixel == pixel;
}
