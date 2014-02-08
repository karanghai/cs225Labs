/**
 * @file min.cpp
 * Finds the minimum in a sequence using a parallel algorithm.
 *
 * @author Chase Geigle
 * @date Spring 2012
 */

#include <cstddef>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <omp.h>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::ifstream;

#include "findmin.h"

void print_usage_and_exit( char * name ) {
	cout << "Usage: " << name << " filename" << endl;
	cout << "\tFinds the minimum integer in a file." << endl;
	cout << "\tExample: " << name << " minfile" << endl;
	exit(1);
}

int main( int argc, char ** argv ) {
	if( argc == 1 )
		print_usage_and_exit(argv[0]);

	cout << "Reading " << argv[1] << "..." << endl;
	ifstream infile( argv[1] );
	vector<int> numbers;
	int num;
	while( infile >> num )
		numbers.push_back(num);
	cout << "Finished reading." << endl;
	cout << "Finding minimum..." << endl;
	double time = omp_get_wtime();
	int min = findmin::minimum<int>( numbers );
	cout << "Minimum is: " << min << endl;
	cout << "Minimum finding took: " << omp_get_wtime() - time << " seconds" << endl;
	return 0;
}
