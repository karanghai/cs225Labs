/**
 * @file histogram.cpp
 * Generates a histogram of an image using a parallel algorithm.
 *
 * @author Chase Geigle
 * @date Spring 2012
 */

#include <cstddef>
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

#include "pnganalysis.h"

void print_usage_and_exit( char * name ) {
	cout << "Usage: " << name << " max_colors infile outfile" << endl;
	cout << "\tGenerates a histogram from the input file and saves it in the output file." << endl;
	cout << "\tExample: " << name << " 30 data/counter/09_600x400.png histogram.png" << endl;
	exit(1);
}

int main( int argc, char ** argv ) {
	if( argc < 4 )
		print_usage_and_exit( argv[0] );
	cout << "Reading " << argv[2] << "..." << endl;
	PNG input( argv[2] );
	size_t max_colors = (size_t)atoi( argv[1] );
	cout << "Generating frequency map..." << endl;
	double time = omp_get_wtime();
	map<RGBAPixel, int> frequencies = pnganalysis::frequency( input );
	cout << "Took: " << omp_get_wtime() - time << " seconds." << endl;
	cout << "Generating output histogram..." << endl;
	PNG output = pnganalysis::histogram( frequencies, max_colors );
	cout << "Writing output..." << endl;
	output.writeToFile( argv[3] );
	cout << "Done!" << endl;
}
