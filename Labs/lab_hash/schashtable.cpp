/**
 * @file schashtable.cpp
 * Implementation of the SCHashTable class.
 *
 * @author Chase Geigle
 * @date Spring 2011
 * @date Summer 2012
 */

#include "schashtable.h"

using hashes::hash;
using std::list;
using std::pair;

template <class K, class V>
SCHashTable<K,V>::SCHashTable( int tsize ) {//
    if( tsize <= 0 )
        tsize = 17;
    size = findPrime( tsize );
    table = new list< pair<K,V> >[size];
    elems = 0;
}

template <class K, class V>
SCHashTable<K,V>::~SCHashTable() {
    delete [] table;
}

template <class K, class V>
SCHashTable<K,V> const & SCHashTable<K,V>::operator=( SCHashTable<K,V> const & rhs ) {
    if( this != &rhs ) {
        delete [] table;
        table = new list< pair<K,V> >[rhs.size];
        for( int i = 0; i < rhs.size; i++ )
            table[i] = rhs.table[i];
        size = rhs.size;
        elems = rhs.elems;
    }
    return *this;
}

template <class K, class V>
SCHashTable<K,V>::SCHashTable( SCHashTable<K,V> const & other ) {
    table = new list< pair<K,V> >[other.size];
    for( int i = 0; i < other.size; i++ )
        table[i] = other.table[i];
    size = other.size;
    elems = other.elems;
}

template <class K, class V>
void SCHashTable<K,V>::insert( K const & key, V const & value ) {
    ++elems;
    if( shouldResize() )
        resizeTable();
    pair<K,V> p( key, value );
    int idx = hash( key, size );
    table[idx].push_front( p );
}

template <class K, class V>
void SCHashTable<K,V>::remove( K const & key ) {
    typename list< pair<K,V> >::iterator it;
    /**
     * @todo Implement this function.
     *
     * Please read the note in the lab spec about list iterators and the
     * erase() function on std::list!
     */
	int idx =hash(key,size);

	for(it =table[idx].begin();it!= table[idx].end();it++) 
	{
		if(it->first ==key)
		 {
			table[idx].erase(it);
			elems--;
			break;
		}
	}	
	
}

template <class K, class V>
V SCHashTable<K,V>::find( K const & key ) const {
    int idx = hash( key, size );
    typename list< pair<K,V> >::iterator it;
    for( it = table[idx].begin(); it != table[idx].end(); it++ ) {
        if( it->first == key )
            return it->second;
    }
    return V();
}

template <class K, class V>
V & SCHashTable<K,V>::operator[]( K const & key ) {
    int idx = hash( key, size );
    typename list< pair<K,V> >::iterator it;
    for( it = table[idx].begin(); it != table[idx].end(); it++ ) {
        if( it->first == key )
            return it->second;
    }

    ++elems;
    if( shouldResize() )
        resizeTable();
 
    idx = hash( key, size );
    pair<K,V> p( key, V() );
    table[idx].push_front( p );
    return table[idx].front().second;
}

template <class K, class V>
bool SCHashTable<K,V>::keyExists( K const & key ) const {
    int idx = hash( key, size );
    typename list< pair<K,V> >::iterator it;
    for( it = table[idx].begin(); it != table[idx].end(); it++ ) {
        if( it->first == key )
            return true;
    }
    return false;
}

template <class K, class V>
void SCHashTable<K,V>::clear() {
    delete [] table;
    table = new list< pair<K,V> >[17];
    size = 17;
    elems = 0;
}

template <class K, class V>
void SCHashTable<K,V>::resizeTable() {
  //  typename list< pair<K,V> >::iterator it;
    /**
     * @todo Implement this function.
     *
     * Please read the note in the spec about list iterators!
     * The size of the table should be the closest prime to size * 2.
     *
     * @hint Use findPrime()!
     */
	
	//std::list< std::pair<K, V> > * temp = new list< pair<K,V> >[size * 2];

	/*size_t newSize = findPrime( size * 2);
	
	SCHashTable newTable(newSize);
    	for(int idx = 0; idx < size; idx++)
    	{
     	   if( table[idx].empty())return;
	  else
           {
           	 typename list< pair<K,V> >::iterator it;
           	 for( it = table[idx].begin() ; it != table[idx].end(); it++)
           	 {
           		     newTable.insert(it->first, it->second);
           	 }
        }
    }
	
    *this = newTable;*/
	int origSize = size;
        size = findPrime(size*2);
        list< pair<K,V> > * orig = table;
        table = new list< pair<K,V> >[size];
        elems = 0;
 
   	 typename list< pair<K,V> >::iterator it;
        for(int i = 0; i < origSize; i++) 
            for(it = orig[i].begin(); it != orig[i].end(); it++) 
		insert(it->first, it->second);
            
	 delete[] orig;

}
