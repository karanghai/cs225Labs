/**
 * @file counter.cpp
 * Counts the number of pixels in an image that match a certain selection
 * criteria using a parallel algorithm.
 *
 * @author Chase Geigle
 * @date Spring 2012
 */

#include <cstddef>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <omp.h>

using std::string;
using std::vector;
using std::cout;
using std::endl;

#include "pnganalysis.h"
#include "exact_selector.h"
#include "tolerance_selector.h"

void print_usage_and_exit( string program ) {
	cout << "Usage: " << endl;
	cout << "\t" << program << " exact red green blue filename" << endl;
	cout << "\t\tFinds the number of pixels that match exactly the given pixel in the file." << endl;
	cout << "\t" << program << " similar red green blue tolerance filename" << endl;
	cout << "\t\tFinds the number of pixels that match within tolerance of the given pixel in the file." << endl;
	exit(1);
}

RGBAPixel get_pixel( const vector<string> & args ) {
	RGBAPixel pixel;
	pixel.red = (unsigned char)atoi( args[2].c_str() );
	pixel.green = (unsigned char)atoi( args[3].c_str() );
	pixel.blue = (unsigned char)atoi( args[4].c_str() );
	return pixel;
}

void count( const PNG & image, selector & selector ) {
	cout << "Running selector..." << endl;
	double time = omp_get_wtime();
	int counted = pnganalysis::num_selected( image, selector );
	time = omp_get_wtime() - time;
	cout << "Number selected: " << counted << endl;
	cout << "Selection time: " << time << " seconds." << endl;
}

void count_exact( const vector<string> & args ) {
	RGBAPixel pixel = get_pixel( args );
	exact_selector exact( pixel );
	PNG image( args.back() );
	count( image, exact );
}

void count_similar( const vector<string> & args ) {
	RGBAPixel pixel = get_pixel( args );
	tolerance_selector similar( pixel, (unsigned)atoi( args[5].c_str() ) );
	PNG image( args.back() );
	count( image, similar );
}

int main( int argc, char ** argv ) {
	vector<string> args( argv, argv + argc );
	if( args.size() < 6 )
		print_usage_and_exit( args[0] );
	if( args[1] == "exact" )
		count_exact( args );
	else if( args[1] == "similar" )
		count_similar( args );
	else
		print_usage_and_exit( args[0] );
	return 0;
}
