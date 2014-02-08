/**
 * @file tolerance_selector.cpp
 * Implementation of a tolerance selection function object.
 *
 * @author Chase Geigle
 * @date Spring 2012
 */
#include "tolerance_selector.h"

/**
 * Constructs a tolerance selector using the given pixel reference
 * as the base to compare other pixels in operator().
 *
 * @param pixel The pixel with which to do comparisons.
 * @param tolerance The squared distance within which other pixels
 *                  must exist to be selected.
 */
tolerance_selector::tolerance_selector( const RGBAPixel & pixel, unsigned tolerance ) {
	_pixel = pixel;
	_tolerance = tolerance;
}
/**
 * Selection function: determines if the given pixel is within
 * tolerance of the original pixel.
 *
 * @param pixel The pixel to compare with.
 * @return Whether or not the pixel is within tolerance.
 */
bool tolerance_selector::operator()( const RGBAPixel & pixel ) {
	unsigned distance = 
		(_pixel.red - pixel.red) * (_pixel.red - pixel.red) +
		(_pixel.green - pixel.green) * (_pixel.green - pixel.green) +
		(_pixel.blue - pixel.blue) * (_pixel.blue - pixel.blue);
	return distance <= _tolerance;
}
