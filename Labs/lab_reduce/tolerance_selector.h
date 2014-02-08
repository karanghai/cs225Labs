/**
 * @file tolerance_selector.h
 * Declaration of a tolerance selection function object.
 *
 * @author Chase Geigle
 * @date Spring 2012
 */
#ifndef _TOLERANCE_SELECTOR_H_
#define _TOLERANCE_SELECTOR_H_

#include "selector.h"

/**
 * Tolerance selector function object: selects a pixel if it is within a
 * given tolerance (which is given as squared euclidean distance) of the
 * pixel with which the selector was constructed.
 *
 * @author Chase Geigle
 * @date Spring 2012
 */
class tolerance_selector : public selector {
	public:
		/**
		 * Constructs a tolerance selector using the given pixel reference
		 * as the base to compare other pixels in operator().
		 *
		 * @param pixel The pixel with which to do comparisons.
		 * @param tolerance The squared distance within which other pixels
		 *                  must exist to be selected.
		 */
		tolerance_selector( const RGBAPixel & pixel, unsigned tolerance );

		/**
		 * Selection function: determines if the given pixel is within
		 * tolerance of the original pixel.
		 *
		 * @param pixel The pixel to compare with.
		 * @return Whether or not the pixel is within tolerance.
		 */
		bool operator()( const RGBAPixel & pixel );
	private:
		/**
		 * Reference pixel for comparison.
		 */
		RGBAPixel _pixel;
		/**
		 * Tolerance storage.
		 */
		unsigned _tolerance;
};
#endif
