/**
 * @file huffman_tree.cpp
 * Implementation of a Huffman Tree class.
 *
 * @author Chase Geigle
 * @date Summer 2012
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

#include "huffman_tree.h"

using namespace std;

HuffmanTree::HuffmanTree( vector<Frequency> frequencies ) {
	std::sort( frequencies.begin(), frequencies.end() );
	buildTree( frequencies );
	vector<bool> path;
	buildMap( root, path );
}

HuffmanTree::HuffmanTree( const HuffmanTree & other ) {
	copy( other );
}

HuffmanTree::HuffmanTree( BinaryFileReader & bfile ) {
	root = readTree( bfile );
	vector<bool> path;
	buildMap( root, path );
}

HuffmanTree::~HuffmanTree() {
	clear( root );
}

const HuffmanTree & HuffmanTree::operator=( const HuffmanTree & rhs ) {
	if( this != &rhs ) {
		clear( root );
		copy( rhs );
	}
	return *this;
}

void HuffmanTree::clear( TreeNode * current ) {
	if( current == NULL )
		return;
	clear( current->left );
	clear( current->right );
	delete current;
}

void HuffmanTree::copy( const HuffmanTree & rhs ) {
	root = copy( rhs.root );
}

HuffmanTree::TreeNode * HuffmanTree::copy( const TreeNode * current ) {
	if( current == NULL )
		return NULL;
	TreeNode * node = new TreeNode( current->freq );
	node->left = copy( current->left );
	node->right = copy( current->right );
	return node;
}


HuffmanTree::TreeNode * HuffmanTree::removeSmallest( 
		queue<TreeNode *> & singleQueue, queue<TreeNode *> & mergeQueue ) {

	/**
	 * @todo Your code here!
	 *
	 * Remove the smallest TreeNode * from the two queues given as
	 * parameters. The entries on the queues are in sorted order, so the
	 * smaller of the two queues heads is the smallest item in either of
	 * the queues. Return this item after removing it from its queue.
	 */
	TreeNode * smallest=NULL;	
	if(singleQueue.size()!=0 && mergeQueue.size()!=0)//CASE1 both queues are not empty
	{	
	
	if(singleQueue.front()->freq.getFrequency()>mergeQueue.front()->freq.getFrequency())
	{
	smallest = mergeQueue.front();
	mergeQueue.pop();	
	}	
	// your code!
	else 
	{
	smallest = singleQueue.front();
	singleQueue.pop();
	}	

	}
	
    else if(singleQueue.size()!=0 && mergeQueue.size()==0)//CASE2 only meregQueue is empty
    {
        smallest=singleQueue.front();
        singleQueue.pop();
    }
	
    else if(singleQueue.size()==0 && mergeQueue.size()!=0)// CASE3 only singleQueue is empty
    {
        smallest=mergeQueue.front();
        mergeQueue.pop();
    }
    
    return smallest;
	


}



void HuffmanTree::buildTree( const vector<Frequency> & frequencies ) {
	queue<TreeNode *> singleQueue; // Queue containing the leaf nodes
	queue<TreeNode *> mergeQueue;  // Queue containing the inner nodes

	/**
	 * @todo Your code here!
	 *
	 * First, place all of the leaf nodes into the singleQueue in
	 * increasing order of frequency. Note: frequencies is already sorted
	 * for you.
	 *
	 * Next, until there is only one node on the two queues (that is, one
	 * of the queues is empty and one has a single node), remove the two
	 * smallest entries from the two queues. Then, create a new internal
	 * node with these nodes as children, whose frequency is the sum of
	 * these two children's frequencies. Place the new internal node onto
	 * the back of the mergeQueue.
	 *
	 * Finally, when there is a single node left, it is the root. Assign it
	 * to the root and you're done!
	 */
	for(int i=0;i<frequencies.size();i++)
		singleQueue.push(new TreeNode(frequencies[i]));
	
	TreeNode *s1=NULL;
	TreeNode *s2=NULL;
	
	while(mergeQueue.size()+singleQueue.size()>1)
	{
	s1=removeSmallest(singleQueue,mergeQueue);
	s2=removeSmallest(singleQueue,mergeQueue);
	
	TreeNode * m= new TreeNode(s1->freq.getFrequency()+s2->freq.getFrequency());
	m->left=s1;
	m->right=s2;
	
	mergeQueue.push(m);
	}
	
	//if(mergeQueue.size()==1&& singleQueue.size()==0)
	    root=mergeQueue.front();
	
	//else if(mergeQueue.size()==0 && singleQueue.size()==1)
     	// root=singleQueue.front();

}

string HuffmanTree::decodeFile( BinaryFileReader & bfile ) {
	stringstream ss;
    decode( ss, bfile );
	return ss.str();
}

void HuffmanTree::decode( stringstream & ss, BinaryFileReader & bfile ) {
	TreeNode * temp = root;
	while( bfile.hasBits() ) {
		/**
		 * @todo Your code here!
		 *
		 * This code is reading in all of the bits in the binary file
		 * given. After reading a bit, we go left if the bit was a 0 (or
		 * false), and we go right if the bit was a 1 (or true).
		 *
		 * Special case: if we are at a leaf node, we should "print" its
		 * character to the stringstream (with operator<<, just like cout)
		 * and start traversing from the root node again.
		 */
		
		if(temp!=NULL)
		{
			   		
			
			
			 if(bfile.getNextBit())
		    	{
		    		if(temp->right!=NULL)
	    			temp=temp->right;
			}	
		    	else// if(!bfile.getNextBit()) 
		    	{		
	    			if(temp->left!=NULL)		
		    		temp=temp->left;
	    		}   
		
			 if(temp->left==NULL && temp->right==NULL)
			{
				ss<<temp->freq.getCharacter();         
				temp=root;
			}
		}
				
	}
}

void HuffmanTree::writeTree( BinaryFileWriter & bfile ) {
	writeTree( root, bfile );
}

void HuffmanTree::writeTree( TreeNode * current, BinaryFileWriter & bfile ) {
	/**
	 * @todo Your code here!
	 *
	 * This code is writing the current HuffmanTree in a compressed format
	 * to the given BinaryFileWriter. The strategy for doing so is as
	 * follows:
	 *		1. If we are a leaf node, write the bit "1" followed by the
	 *		   byte that is the character of this node.
	 *		2. If we are an internal node, writ the bit "0", and then
	 *		   encode the left and right subtree, recursively.
	 *
	 *	Note that we don't encode the frequencies in this compressed
	 *	version: this is fine, as the structure of the tree still reflects
	 *	what the relative frequencies were.
	 */
	if(current!=NULL)
	{
	if(current->left==NULL && current->right==NULL)
	{	
		bfile.writeBit(1);//write bit 1
		bfile.writeByte(current->freq.getCharacter());//followed by character of this node
	}
	else
	{
		bfile.writeBit(0);//write bit0		
		writeTree(current->left,bfile);
		writeTree(current->right,bfile);

	}

	}


}

HuffmanTree::TreeNode * HuffmanTree::readTree( BinaryFileReader & bfile ) {
	/**
	 * @todo Your code here!
	 *
	 * This code is reading a HuffanTree in from a file in the format that
	 * we wrote it above. The strategy, then, is as follows:
	 *		1. If the file has no more bits, we're done.
	 *		2. If we read a 1 bit, we are a leaf node: create a new
	 *		   TreeNode with the character that is the next byte in the
	 *		   file (its frequency should be 0, since we are ignoring
	 *		   frequency data now).
	 *		3. If we read a 0 bit, create a new internal node (with
	 *		   frequency 0, since we are ignoring them now, and set its left
	 *		   child and right children to be the subtrees built recursively.
	 *		4. Your function should return the TreeNode it creates, or NULL
	 *		   if it did not create one.
	 */
	if(!bfile.hasBits())
	return NULL;	
	
	else
	{
		if(bfile.getNextBit())
		{
			Frequency temp_freq(bfile.getNextByte(),0); 
			return new TreeNode(temp_freq);
		}
		
		else
		{
			//TreeNode * left_temp = readTree(bfile);
			//TreeNode * right_temp=	readTree(bfile);
			
					
			TreeNode * temp_node=	new TreeNode(0);
			temp_node->left=readTree(bfile);//left_temp;
			temp_node->right=readTree(bfile);//right_temp;
			
			return temp_node;	
		}

	}
		//return NULL; // replaceme!

}

void HuffmanTree::buildMap( TreeNode * current, vector<bool> & path ) {
	// Base case: leaf node.
	if( current->left == NULL && current->right == NULL ) {
		bitsMap[current->freq.getCharacter()] = path;
		return;
	}

	// Move left
	path.push_back( false );
	buildMap( current->left, path );
	path.pop_back();

	// Move right
	path.push_back( true );
	buildMap( current->right, path );
	path.pop_back();
}

void HuffmanTree::printInOrder() const {
	printInOrder( root );
	cout << endl;
}

void HuffmanTree::printInOrder( const TreeNode * current ) const {
	if( current == NULL )
		return;
	printInOrder( current->left );
	cout << current->freq.getCharacter() << ":" <<
		current->freq.getFrequency() << " ";
	printInOrder( current->right );
}

void HuffmanTree::writeToFile( const string & data, BinaryFileWriter & bfile ) {
	for( auto it = data.begin(); it != data.end(); ++it )
		writeToFile( *it, bfile );
}

void HuffmanTree::writeToFile( char c, BinaryFileWriter & bfile ) {
	vector<bool> bits = getBitsForChar( c );
	for( auto it = bits.begin(); it != bits.end(); ++it )
		bfile.writeBit( *it );
}

vector<bool> HuffmanTree::getBitsForChar( char c ) {
	return bitsMap[c];
}

// class for generic printing

template <typename TreeNode>
class HuffmanTreeNodeDescriptor:
    public GenericNodeDescriptor< HuffmanTreeNodeDescriptor<TreeNode> >
{
	public:

	HuffmanTreeNodeDescriptor(const TreeNode* root): subRoot(root) { /* nothing */ }

	string key() const
	{
		std::stringstream ss;
        char ch = subRoot->freq.getCharacter();
		int freq = subRoot->freq.getFrequency();

        // print the sum of the two child frequencies
        if(ch == '\0')
		    ss << freq;
        // print the leaf containing a character and its count
        else
        {
            if(ch == '\n')
                ss << "\\n";
            else
                ss << ch;
            ss << ":" << freq;
        }
		return ss.str();
	}

	bool isNull() const { return subRoot == NULL; }
	HuffmanTreeNodeDescriptor left() const { return HuffmanTreeNodeDescriptor(subRoot->left); }
	HuffmanTreeNodeDescriptor right() const { return HuffmanTreeNodeDescriptor(subRoot->right); }

	private:

    const TreeNode* subRoot;
};

int HuffmanTree::height(const TreeNode* subRoot) const
{
    if(subRoot == NULL)
        return -1;
    return 1 + std::max(height(subRoot->left), height(subRoot->right));
}

void HuffmanTree::print(std::ostream & out) const
{
    int h = height(root);
    if(h > _max_print_height)
    {
        out << "Tree is too big to print. Try with a small file (e.g. data/small.txt)" << endl;
        return;
    }

    printTree(HuffmanTreeNodeDescriptor<TreeNode>(root), out);
}
