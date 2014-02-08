/**
 * @file exact_selector.h
 * Definition of the exact_selector function object.
 *
 * @author Chase Geigle
 * @date Spring 2012
 */
#ifndef _EXACT_SELECTOR_H_
#define _EXACT_SELECTOR_H_

#include "selector.h"

/**
 * Exact selector function object: selects a pixel if and only if it is
 * exactly equal to the pixel with which the selector was constructed.
 *
 * @author Chase Geigle
 * @date Spring 2012
 */
class exact_selector : public selector {
	public:
		/**
		 * Constructs an exact selector, using the given pixel reference as
		 * the base for comparing other pixels in operator().
		 *
		 * @param pixel The pixel to do all comparisons against after
		 *              construction.
		 */
		exact_selector( const RGBAPixel & pixel );

		/**
		 * Selection function: determines if the parameterized pixel is
		 * exactly equivalent to the pixel given on construction.
		 *
		 * @param pixel Pixel to compare against.
		 * @return Whether pixel is exactly equivalent to the original
		 *         pixel.
		 */
		bool operator()( const RGBAPixel & pixel );
	private:
		/**
		 * Reference pixel to compare others against in operator().
		 */
		RGBAPixel _pixel;
};
#endif
