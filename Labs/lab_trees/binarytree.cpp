/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

/**
 * @return The height of the binary tree. Recall that the height of a binary tree
 *  is just the length of the longest path from the root to a leaf, and that the
 *  height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
	// Call recursive helper function on root
	return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node * subRoot) const
{
	// Base case
	if (subRoot == NULL)
        return -1;
	
	// Recursive definition
	return 1 + max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that node
 *  itself, and everything to the right of a node will be printed out after that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
	// Call recursive helper function on the root
	printLeftToRight(root);

	// Finish the line
	cout << endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node * subRoot) const
{
	// Base case - null node
	if (subRoot == NULL)
		return;

	// Print left subtree
	printLeftToRight(subRoot->left);

	// Print this node
	cout << subRoot->elem << ' ';

	// Print right subtree
	printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
template <typename T>
void BinaryTree<T>::mirror()
{
	// your code here
	mirror(root);
}

template <typename T>
void BinaryTree<T>::mirror(Node* start)const
{
	
	if(start==NULL)
	return;	
	
	Node * temp;
	mirror(start->left);
	mirror(start->right);
	temp=start->left;
	start->left=start->right;
	start->right=temp;

}

/**
 * @return True if an in-order traversal of the tree would produce a nondecreasing list
 *  output values, and false otherwise. This is also the criterion for a binary tree to be
 *  a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrdered() const
{
    // your code here
	return isOrdered(root);
}


template <typename T>
bool BinaryTree<T>::isOrdered(Node* start)const
{
	bool ordered;	
	if(start==NULL)
	return true;	
	
	if(start->left!=NULL)
	{
		if(start->elem<start->left->elem)
		return false;
		
		if(root->elem<start->left->elem)
		return false;
	}

	if(start->right!=NULL)
	{
		if(start->elem>start->right->elem)
		return false;
		
		if(root->elem>start->right->elem)
		return false;	
		
	}
		
	ordered=isOrdered(start->left);
	ordered=isOrdered(start->right);

	return ordered;
		
}
/**
 * Prints out all the possible paths from the root of the tree to any leaf node.
 * That is, all sequences starting at the root node and continuing downwards, ending at a
 *  leaf node. Paths ending in a left node should be printed before paths ending in a node
 *  further to the right.
 */
template <typename T>
void BinaryTree<T>::printPaths() const
{
	T array[height()];
	int arrayL=0;
	printPaths(root,array,arrayL);
}


template <typename T>
void BinaryTree<T>::printPaths(Node* start, T array[], int arrayL) const
{
    // your code here
	if(start==NULL)
	return;
	
	if(start!=NULL)
	{
		array[arrayL]=start->elem;
		arrayL++;
	}
	
	if(start->right==NULL && start->left==NULL)
	{
		cout<<"Path:";		
		for(int i=0;i<arrayL;i++)
		cout<<" "<<array[i];
		cout<<endl;
		arrayL=0;
	}

		

	printPaths(start->left,array,arrayL);
	printPaths(start->right,array,arrayL);
	
		
}
/**
 * Each node in a tree has a distance from the root node - the depth of that node,
 *  or the number of edges along the path from that node to the root. This function returns
 *  the sum of the distances of all nodes to the root node (the sum of the depths of all
 *  the nodes). Your solution should take O(n) time, where n is the number of nodes in the tree.
 * @return The sum of the distances of all nodes to the root
 */
template <typename T>
int BinaryTree<T>::sumDistances() const
{
    // your code here
	
    return 19;
}


template <typename T>
int BinaryTree<T>::sumDistances(Node* start, int sum)const
{

	return -1;
}



