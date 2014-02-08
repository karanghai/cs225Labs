/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K & key) const
{
	return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node * subtree, const K & key) const
{
	if (subtree == NULL)
		return V();
	else if (key == subtree->key)
		return subtree->value;
	else
	{
		if (key < subtree->key)
			return find(subtree->left, key);
		else
			return find(subtree->right, key);
	}
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node * & t)
{
	*_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here

	Node * temp= t->right;
	t->right=temp->left;
	temp->left=t;
	t=temp;	
		
	t->height= max(heightOrNeg1(t->left),heightOrNeg1(t->right))+1;
	
	t->left->height=max(heightOrNeg1(t->left->left),heightOrNeg1(t->left->right))+1;
		
	
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node * & t)
{
	*_out << __func__ << endl; // Outputs the rotation name (don't remove this)
	// Implemented for you:
	rotateLeft(t->left);
	rotateRight(t);
	//t->height= max(heightOrNeg1(t->left),heightOrNeg1(t->right))+1;
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node * & t)
{
	*_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here

	
	Node* temp= t->left;
	t->left=temp->right;
	temp->right=t;
	t=temp;
	
	t->height= max(heightOrNeg1(t->left),heightOrNeg1(t->right))+1;
	t->right->height=max(heightOrNeg1(t->right->left),heightOrNeg1(t->right->right))+1;
	
		
	//temp->height= max(heightOrNeg1(temp->left),heightOrNeg1(temp->right))+1;	


}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node * & t)
{
	*_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here

	rotateRight(t->right);
	rotateLeft(t);
	t->height= max(heightOrNeg1(t->left),heightOrNeg1(t->right))+1;
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
	insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node* & subtree, const K & key, const V & value)
{
    // your code here

	if(subtree==NULL)
		subtree= new Node(key,value);

	else if(key<subtree->key)
	{
		insert(subtree->left,key,value);
		int balance=	heightOrNeg1(subtree->right)-heightOrNeg1(subtree->left);
		int balance_2= heightOrNeg1(subtree->left->right)-heightOrNeg1(subtree->left->left);
		if(balance==-2)
		{
			if(balance_2==-1)
				rotateRight(subtree);
			else
				rotateLeftRight(subtree);
		}
	}
	
	else if(key>subtree->key)
	{

		insert(subtree->right,key,value);
		int balance=heightOrNeg1(subtree->right)-heightOrNeg1(subtree->left);
		int balance_3=heightOrNeg1(subtree->right->right)-heightOrNeg1(subtree->right->left);
		if(balance==2)
		{
			if(balance_3==1)
				rotateLeft(subtree);
			else 
				rotateRightLeft(subtree);
		}	
	}

	subtree->height= max(heightOrNeg1(subtree->left),heightOrNeg1(subtree->right))+1;
				
}



