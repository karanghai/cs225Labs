/**
 * @file findmin.h
 * Declaration of the findmin namespace.
 *
 * @author Chase Geigle
 * @date Spring 2012
 */
#ifndef _FINDMIN_H_
#define _FINDMIN_H_

#include <cstddef>
#include <vector>
using std::vector;

/**
 * Namespace for our minimum finding function (because using the global
 * namespace is overrated).
 *
 * @author Chase Geigle
 * @date Spring 2012
 */
namespace findmin {
	/**
	 * Finds the minimum element in a sequence of type T.
	 * Assumes a well defined operator< exists for the type T.
	 * If the parameter list is empty, it should return a default T.
	 *
	 * You will need to modify this function to use OpenMP to parallelize the
	 * search.
	 *
	 * @param list The list of type T to find the minimum element in.
	 * @return The minimum element in the sequence.
	 */
	template <class T>
	T minimum( const vector<T> & list );
}
#include "findmin.cpp"
#endif
