/**
	 * @file binarytree.cpp
	 * Definitions of the binary tree functions you'll be writing for this lab.
	 * You'll need to modify this file.
	 */
	#include "TreeTraversals/InorderTraversal.h"
	#include <iostream>
	#include <stack>
    using namespace std;
	
	/**
	 * @return The height of the binary tree. Recall that the height of a binary
	 * tree is just the length of the longest path from the root to a leaf, and
	 * that the height of an empty tree is -1.
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
	int BinaryTree<T>::height(const Node* subRoot) const
	{
	 // Base case
	 if (subRoot == NULL)
	 return -1;
	
	 // Recursive definition
     int leftHeight = height(subRoot->left);
     int rightHeight = height(subRoot->right);
     return 1 + max(leftHeight, rightHeight);
	//  return 1 + max(height(subRoot->left), height(subRoot->right));
	}
	
	/**
	 * Prints out the values of the nodes of a binary tree in order.
	 * That is, everything to the left of a node will be printed out before that
	 * node itself, and everything to the right of a node will be printed out after
	 * that node.
	 */
	template <typename T>
	void BinaryTree<T>::printLeftToRight() const
	{
	 // Call recursive helper function on the root
	 printLeftToRight(root);
	
	 // Finish the line
	 std::cout << std::endl;
	}
	
	/**
	 * Private helper function for the public printLeftToRight function.
	 * @param subRoot
	 */
	template <typename T>
	void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
	{
	 // Base case - null node
	 if (subRoot == NULL)
	 return;
	
	 // Print left subtree
	 printLeftToRight(subRoot->left);
	
	 // Print this node
	 std::cout << subRoot->elem << ' ';
	
	 // Print right subtree
	 printLeftToRight(subRoot->right);
	}
	
	/**
	 * Flips the tree over a vertical axis, modifying the tree itself
	 * (not creating a flipped copy).
	 */
	template <typename T>
	void BinaryTree<T>::mirror() {
	 mirror(root);
	}
	
	template <typename T>
	void BinaryTree<T>::mirror( Node* subRoot ) {
		if (subRoot != NULL){
		
		mirror(subRoot->left);
		mirror(subRoot->right);


		Node * newLeft = subRoot->left;
		Node * newRight = subRoot->right;
	
		subRoot->right = newLeft;
		subRoot->left = newRight;
        }
	}
	
	
	/**
	 * isOrdered() function iterative version
	 * @return True if an in-order traversal of the tree would produce a
	 * nondecreasing list output values, and false otherwise. This is also the
	 * criterion for a binary tree to be a binary search tree.
	 */
	template <typename T>
	bool BinaryTree<T>::isOrderedIterative() const {

		Node * temp = NULL;
		InorderTraversal<T> in(this->getRoot());
		for(TreeTraversal<int>::Iterator it = in.begin(); it != in.end(); ++it){
            if(temp == NULL){
            temp = *it;
            }
            if(temp->elem > (*it)->elem){
            return false;
            }
            if(temp->elem < (*it)->elem || temp->elem == (*it)->elem){
            temp = *it;
            }
		}
		return true;
	}
	
	/**
	 * isOrdered() function recursive version
	 * @return True if an in-order traversal of the tree would produce a
	 * nondecreasing list output values, and false otherwise. This is also the
	 * criterion for a binary tree to be a binary search tree.
	 */
	template <typename T>
	bool BinaryTree<T>::isOrderedRecursive() const
	{
	 // your code here
		
        Node *before = NULL;
		return isOrderedRecursive (root, before);
	}
	
	template <typename T>
	bool BinaryTree<T>::isOrderedRecursive(Node* subRoot, Node *&previous) const
	{
		if(subRoot != NULL){

		    if(!isOrderedRecursive(subRoot->left, previous)){
		        return false;
		}
		    if(previous != NULL && subRoot->elem <= previous->elem){
		        return false;
		}
	
		previous = subRoot;
	
		return isOrderedRecursive(subRoot->right, previous);
	 }
	
		return true;
    }
