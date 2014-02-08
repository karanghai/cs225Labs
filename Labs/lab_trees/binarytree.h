/**
 * @file binarytree.h
 * Declaraction of the BinaryTree class. You will probably need to modify this
 *  file to add helper functions.
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "random.h"

using namespace std;

/**
 * The BinaryTree class represents a templated linked-memory tree data structure.
 */
template <typename T>
class BinaryTree
{
    private:

        /**
         * Represents a tree node; that is, an element in a BinaryTree.
         * It has a data element and pointers to its left and right children.
         */
        struct Node
        {
            T elem;
            Node* left;
            Node* right;

            /**
             * Node element constructor; sets children to point to NULL.
             * @param element The templated data element that the constructed
             *  node will hold.
             */
            Node(const T & element):
                elem(element), left(NULL), right(NULL){ /* nothing */ }
        };
    
    public:

        /**
         * Constructor to create an empty tree.
         */
        BinaryTree();
        
        /**
         * Copy constructor.
         */
        BinaryTree(const BinaryTree & other);
        
        /**
         * Destructor; frees all nodes associated by this tree.
         */
        ~BinaryTree();
        
        /**
         * Assignment operator.
         * @param rhs The tree to make a copy of
         * @return A reference to the current tree
         */
        const BinaryTree & operator=(const BinaryTree & rhs);
        
        /**
         * Frees all nodes associated with this tree and sets it to be empty.
         */
        void clear();
        
        /**
         * Inserts into the BinaryTree.
         * @param elem The element to insert
         * @param sorted By default, this parameter is false. That means that the element
         *  takes a pseudo-random path to a leaf where it is inserted. If true, the insert
         *  function will act like it does in a BST.
         */
        void insert(const T & elem, bool sorted = false);
        
        /**
         * Prints the contents of the tree to stdout.
         */
        void print() const;

        /**
         * This lab deals with the following six helper functions:
         */

        /**
         * @return The height of the binary tree. Recall that the height of a binary tree
         *  is just the length of the longest path from the root to a leaf, and that the
         *  height of an empty tree is -1.
         */
        int height() const;

        /**
         * Prints out the values of the nodes of a binary tree in order.
         * That is, everything to the left of a node will be printed out before that node
         *  itself, and everything to the right of a node will be printed out after that node.
         */
        void printLeftToRight() const;
        
        /**
         * Flips the tree over a vertical axis, modifying the tree itself
         *  (not creating a flipped copy).
         */
        void mirror();
        
        /**
         * @return True if an in-order traversal of the tree would produce a nondecreasing list
         *  output values, and false otherwise. This is also the criterion for a binary tree to be
         *  a binary search tree.
         */
        bool isOrdered() const;
        
        /**
         * Prints out all the possible paths from the root of the tree to any leaf node.
         * That is, all sequences starting at the root node and continuing downwards, ending at a
         *  leaf node. Paths ending in a left node should be printed before paths ending in a node
         *  further to the right.
         */
        void printPaths() const;
        
        /**
         * Each node in a tree has a distance from the root node - the depth of that node,
         *  or the number of edges along the path from that node to the root. This function returns
         *  the sum of the distances of all nodes to the root node (the sum of the depths of all
         *  the nodes). Your solution should take O(n) time, where n is the number of nodes in the tree.
         * @return The sum of the distances of all nodes to the root
         */
        int sumDistances() const;
    
	
    private:

        Node* root;

        /**
         * Put your own private helper functions here.
         * Look at the private helpers for height and printLeftToRight
         *  as examples.
         */
	
        /**
         * Private helper function for the public height function.
         * @param subRoot The current node in the recursion
         * @return The height of the subtree
         */
        int height(const Node* subRoot) const;
        
        /**
         * Private helper function for the public printLeftToRight function.
         * @param subRoot The current node in the recursion
         */
        void printLeftToRight(const Node* subRoot) const;
        
        /**
         * Private helper function for the public insert function.
         * @param node The current node in the recursion
         * @param elem The element to insert
         * @param sorted By default, this parameter is false. That means that the element
         *  takes a pseudo-random path to a leaf where it is inserted. If true, the insert
         *  function will act like it does in a BST.
         */
        void insert(Node* & node, const T & elem, bool sorted);
        
        /**
         * Helper function for operator= and cctor.
         * @param subRoot The current node in the recursion
         */
        Node* copy(const Node* subRoot);

        /**
         * Private helper function for clear that clears beneath the parameter node.
         * @param subRoot The current node in the recursion
         */
        void clear(Node* subRoot);
	
	//made helper functions
	void mirror(Node* start)const;
	
	bool isOrdered(Node* start)const;

	void printPaths(Node* start, T array[], int arrayL) const;

	int sumDistances(Node* start, int sum)const;
};

#include "binarytree_given.cpp"
#include "binarytree.cpp"
#endif
