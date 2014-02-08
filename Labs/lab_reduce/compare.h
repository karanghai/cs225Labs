/**
 * @file compare.h
 * Definition and implementation for a comparison functor based on a
 * map.
 *
 * @author Chase Geigle
 * @date Spring 2012
 */
#ifndef _COMPARE_H_
#define _COMPARE_H_

#include <map>

using std::map;

/**
 * Comparison functor for sorting based on a map.
 *
 * @author Chase Geigle
 * @date Spring 2012
 */
template <class K, class V>
class compare {
	public:
		compare( const map<K,V> & freq ) {
			_freq = freq;
		}

		bool operator()( const K & first, const K & second ) {
			return _freq[first] > _freq[second];
		}

	private:
		map<K,V> _freq;
};
#endif
