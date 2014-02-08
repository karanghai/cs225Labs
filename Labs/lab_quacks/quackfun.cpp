/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 *  stacks and queues portion of the lab.
 */

/**
 * Sums items in a stack.
 * @param s A stack holding values to sum.
 * @return The sum of all the elements in the stack, leaving the original
 *  stack in the same state (unchanged).
 *
 * @note You may modify the stack as long as you restore it to its original
 *  values.
 * @note You may use only two local variables of type T in your function.
 *  Note that this function is templatized on the stack's type, so stacks of
 *  objects overloading the + operator can be summed.
 * @note We are using the Standard Template Library (STL) stack in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint Think recursively!
 */
template <typename T>
T QuackFun::sum(stack<T> & s)
{
    // Your code here
    // stub return value (0 for primitive types). Change this!
                // Note: T() is the default value for objects, and 0 for
                // primitive types
if(s.size()==0)
return 0;

T temp=s.top();
s.pop();
T stack_sum= temp + sum(s);
s.push(temp);
return stack_sum;


}

/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 * @param q A queue of items to be scrambled
 *
 * @note Any "leftover" numbers should be handled as if their block was complete.
 * @note We are using the Standard Template Library (STL) queue in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint You'll want to make a local stack variable.
 */
template <typename T>
void QuackFun::scramble(queue<T> & q)
{
	stack<T> s;
	queue<T> q2;
	int temp1,temp2;
	temp1=0;
	
	while(!q.empty())
	{
		temp1++;
		if(temp1%2==1 )
		{
			for(temp2=0;temp2<temp1;temp2++)
			if(!q.empty())
			{
				T temp3=q.front();
				q.pop();
				q2.push(temp3);	
			}
		}

		else
		{
			for(temp2=0;temp2<temp1;temp2++)
			if(!q.empty())
			{
				T temp4 = q.front();
				q.pop();
				s.push(temp4);
	
			}
			while(!s.empty())
			{
				T temp5=s.top();
				s.pop();	
				q2.push(temp5);
		
			}
		
		}
		
		
	}		

	while(!q2.empty())
	{
		T temp6=q2.front();
		q2.pop();
		q.push(temp6);
	}

    // Your code here
}

/**
 * This function is NOT part of the standard lab grade, but is extra credit.
 * It was also a previous exam question, and something similar could show up again.
 * 
 * @return true if the parameter stack and queue contain only elements of exactly
 *  the same values in exactly the same order; false, otherwise.
 *
 * @note You may assume the stack and queue contain the same number of items!
 * @note There are restrictions for writing this function.
 * - Your function may not use any loops
 * - In your function you may only declare ONE local boolean variable to use in your return statement,
 *      and you may only declare TWO local variables of parametrized type T to use however you wish.
 *   No other local variables can be used.
 * - After execution of verifySame, the stack and queue must be unchanged. Be sure to comment your code VERY well.
 */
template <typename T>
bool QuackFun::verifySame(stack<T> & s, queue<T> & q)
{
   bool retval; // optional
    //T temp1; // rename me
    //T temp2; // rename :)
    
   	T temp=s.top();
	s.pop();		//popping the stack
	if(s.size()!=0)
	{
		retval=verifySame(s,q);
		s.push(temp);//pushing elements back into the stack
		if(!retval)// if retval is false at any point return retval/false
		return retval;	
		
	}
	
	T temp1=q.front();	
	if(temp!=temp1) //if q.front() and corresponding element in the stack are not equal
	return false;
	
	else 
	{	
		q.pop();
		return true;
	}
		
	return retval;
	
	q.push(temp1);//pushing back elemnets into the queue

}

