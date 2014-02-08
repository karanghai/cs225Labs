/**
 * @file pnganalysis.h
 * Declaration for functions that perform analysis on PNG images.
 *
 * @author Chase Geigle
 * @date Spring 2012
 */
#ifndef _PNGANALYSIS_H_
#define _PNGANALYSIS_H_

#include <map>
#include <omp.h>
#include <algorithm>
#include <cassert>
#include <vector>

#include "compare.h"
#include "png.h"
#include "selector.h"

using std::map;
using std::vector;

/**
 * Namespace four our image analysis functions (because using the global
 * namespace is overrated).
 *
 * @author Chase Geigle
 * @date Spring 2012
 */
namespace pnganalysis {
	/**
	 * Finds the number of pixels in an image that satisfy a given
	 * selector's criteria.
	 * Graded! You will need to correctly parallelize this function to
	 * receive credit.
	 *
	 * @param image  PNG to find pixel coordinates in
	 * @param select Function object that takes in RGBAPixels and returns
	 *				 a bool that determines whether the pixel should be
	 *				 "selected" or not.
	 * @return The number of pixels in the image for which the selector
	 *         returns true.
	 */
	int num_selected( const PNG & image, selector & select );

	/**
	 * Helper function that builds an map of color to frequency.
	 * Graded! You need to modify this function such that it is correctly
	 * parallelized to receive credit.
	 *
	 * @param image PNG to build the color frequency map from.
	 * @return An map of colors to number of occurrences.
	 */
	map<RGBAPixel, int> frequency( const PNG & image );

	/**
	 * Builds a color histogram for a given frequency map.
	 * You do not have to modify this function!
	 *
	 * @param frequencies Map of pixels to their frequencies.
	 * @param max_colors Maximum number of colors to display in the image.
	 * @return A PNG representation of the histogram for the given image.
	 */
	PNG histogram( const map<RGBAPixel, int> & frequencies, size_t max_colors );

	/**
	 * Helper function that creates a vector of the most frequently used colors
	 * based off of a histogram.
	 * You do not have to modify this function!
	 *
	 * @param frequencies The map of color frequencies.
	 * @param limit Number of colors to output.
	 */
	vector<RGBAPixel> top_colors( const map<RGBAPixel, int> & frequencies, size_t limit );
		
	/**
	 * Constants for histogram generation.
	 */
	const static int bar_width = 15;
	const static int out_height = 480;
}
#endif
