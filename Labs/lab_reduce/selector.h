/**
 * @file selector.h
 * Definition of an abstract selection function object.
 *
 * @author Chase Geigle
 * @date Spring 2012
 */
#ifndef _SELECTOR_H_
#define _SELECTOR_H_

#include "png.h"

/**
 * Abstract selector function object class.
 *
 * @author Chase Geigle
 * @date Spring 2012
 */
class selector {
	public:
		/**
		 * Selection function: determines if a given pixel meets the
		 * selection criteria or not.
		 */
		virtual bool operator()( const RGBAPixel & pixel ) = 0;
		virtual ~selector() { /* nothing to do */ }
};
#endif
