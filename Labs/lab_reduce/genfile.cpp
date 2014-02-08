/**
 * @file genfile.cpp
 * Generates a file of random integers for testing the min executable.
 *
 * @author Chase Geigle
 * @date Spring 2012
 */
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>

using std::ofstream;
using std::cout;
using std::endl;

void print_usage_and_exit( char * name ) {
	cout << "Usage: " << name << " filename amount" << endl;
	cout << "\tGenerates a file of random numbers at filename containing amount numbers." << endl;
	cout << "\tExample: " << name << " minfile 10000" << endl;
	exit(1);
}

int main( int argc, char ** argv ) {
	if( argc < 3 )
		print_usage_and_exit( argv[0] );
	srand( time(NULL) );
	ofstream outfile( argv[1] );
	for( int i = 0; i < atoi(argv[2]); ++i ) {
		outfile << rand() << "\n";
	}
}
