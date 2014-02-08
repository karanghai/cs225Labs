/**
 * @file heap.cpp
 * Implementation of a heap class.
 */

template <class T, class Compare>
size_t heap<T, Compare>::root() const {
    /// @todo Update to return the index you are choosing to be your root.
    return 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::leftChild( size_t currentIdx ) const {
    /// @todo Update to return the index of the left child.
    return 2*currentIdx;
}

template <class T, class Compare>
size_t heap<T, Compare>::rightChild( size_t currentIdx ) const {
    /// @todo Update to return the index of the right child.
    return 2*currentIdx +1;
}

template <class T, class Compare>
size_t heap<T, Compare>::parent( size_t currentIdx ) const {
    /// @todo Update to return the index of the parent.
    return currentIdx/2;
}

template <class T, class Compare>
bool heap<T, Compare>::hasAChild( size_t currentIdx ) const {
    /// @todo Update to return whether the given node has a child
	if(_elems.size()-1>=2*currentIdx)   
	 return true;
	else 
	return false;
}
template <class T, class Compare>
size_t heap<T, Compare>::maxPriorityChild( size_t currentIdx ) const {
    /// @todo Update to return the index of the child with highest priority
    ///   as defined by higherPriority()
	if(2*currentIdx+1>=_elems.size()) 
	return 2*currentIdx;	
	
	if(higherPriority(_elems[2*currentIdx],_elems[2*currentIdx+1]))   
	return 2*currentIdx; 

	else 
	return 2*currentIdx+1;
}

template <class T, class Compare>
void heap<T, Compare>::heapifyDown( size_t currentIdx ) {
    /// @todo Implement the heapifyDown algorithm.
	if(hasAChild(currentIdx))
	{
	size_t minChildIndex=maxPriorityChild(currentIdx);
		if(!higherPriority(_elems[currentIdx],_elems[minChildIndex]))
		{
			std::swap(_elems[currentIdx],_elems[minChildIndex]);
			heapifyDown(minChildIndex);
		}
	}
}
template <class T, class Compare>
void heap<T, Compare>::heapifyUp( size_t currentIdx ) {
    if( currentIdx == root() )
        return;
    size_t parentIdx = parent( currentIdx );
    if( higherPriority( _elems[ currentIdx ], _elems[ parentIdx ] ) ) {
        std::swap( _elems[ currentIdx ], _elems[ parentIdx ] );
        heapifyUp( parentIdx );
    }
}

template <class T, class Compare>
heap<T, Compare>::heap() {
    /// @todo Depending on your implementation, this function may or may
    ///   not need modifying
	
	_elems.push_back(-1);
}

template <class T, class Compare>
heap<T, Compare>::heap( const std::vector<T> & elems ) {
    /// @todo Construct a heap using the buildHeap algorithm
	//_elems=elems;	
	/*_elems.push_back(T());
	for(int i=parent(_elems.size()-1);i>=1;i--)
		heapifyDown(i);*/
	//_elems.clear();
        _elems.push_back(T());
        for (int i=0;i<elems.size();i++) // copy elements
         _elems.push_back(elems[i]);
        
 
        for (int j=_elems.size()-1; j>=1; j--) // start and end and heapifyDown
         heapifyDown(j);
       
	

}


template <class T, class Compare>
T heap<T, Compare>::pop() {
    /// @todo Remove, and return, the element with highest priority
	/*T minval=_elems[1];  
	_elems[1]=_elems[_elems.size()-1];//size-1?
	_elems.pop_back();
	heapifyDown(1);
	return minval;
 // return T();*/
	T returnValue = _elems[1];
    std::swap( _elems[1], _elems[_elems.size()-1] );
        _elems.pop_back();
	      
	 heapifyDown(1);
    return returnValue;
}

template <class T, class Compare>
T heap<T, Compare>::peek() const {
    /// @todo Return, but do not remove, the element with highest priority
    return _elems[1];
}

template <class T, class Compare>
void heap<T, Compare>::push( const T & elem ) {
    /// @todo Add elem to the heap
	_elems.push_back(elem);
	heapifyUp(_elems.size()-1);//size-1?

}

template <class T, class Compare>
bool heap<T, Compare>::empty() const {
    /// @todo Determine if the heap is empty
  //  return _elems.empty();
	if (_elems.size()-1 <= 0)
            return true;
       return false;
}
