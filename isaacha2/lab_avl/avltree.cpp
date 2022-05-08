/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

#include <cmath>
using namespace std;



template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t) {
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here

    Node * tmpPtr = t->right;

    t->right = tmpPtr->left;
    tmpPtr->left = t;
    t->height = max(heightOrNeg1(t->right), heightOrNeg1(t->left)) + 1;

    tmpPtr->height = max(heightOrNeg1(tmpPtr->left), heightOrNeg1(tmpPtr->right)) + 1;
    t = tmpPtr;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here

    Node * tmpPtr = t->left;
    t->left = tmpPtr->right;
    tmpPtr->right = t;

    t->height = max(heightOrNeg1(t->left), heightOrNeg1(t->right)) + 1;

    tmpPtr->height = max(heightOrNeg1(tmpPtr->left), heightOrNeg1(tmpPtr->right)) + 1;

    t = tmpPtr;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
    if (subtree == NULL) {
        return;
    }
    int totalBalance = 0;
    int rightsideBalance = 0;
    int leftsideBalance = 0;

    int rHeight = heightOrNeg1(subtree->right);
    int lHeight = heightOrNeg1(subtree->left);
    int height = 0;
     
    height = heightOrNeg1(subtree);
    
    totalBalance = rHeight - lHeight;

    if (totalBalance == -2) {

        leftsideBalance = heightOrNeg1(subtree->left->right) - heightOrNeg1(subtree->left->left);
        if (leftsideBalance != -1) {
            rotateLeftRight(subtree);
        } else {
            rotateRight(subtree);
        }

    }

    if (totalBalance == 2) {
        rightsideBalance = heightOrNeg1(subtree->right->right) - heightOrNeg1(subtree->right->left);
            if (rightsideBalance != 1) {
                rotateRightLeft(subtree);
                } else {
                    rotateLeft(subtree);
        }

    }

    subtree->height = max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right)) + 1;
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if (!subtree) {
        subtree = new Node(key, value);
        return;
    }

    if (key < subtree->key) {
        insert(subtree->left, key, value);
        rebalance(subtree);

    } else if (key > subtree->key) {
        insert(subtree->right, key, value);
        rebalance(subtree);
    }
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        // your code here
        remove(subtree->left, key);
        rebalance(subtree);

    } else if (key > subtree->key) {
        // your code here
        remove(subtree->right, key);
        rebalance(subtree);

    } else {

        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            subtree = NULL;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            Node * tmpPtr = subtree->left;
            while (tmpPtr->right) {
                tmpPtr = tmpPtr->right;
            }

            swap(tmpPtr, subtree);

            remove(subtree->left, key);
            
            rebalance(subtree);

        } else {
            /* one-child remove */
            // your code here
            if (subtree->right) {
                Node * tmpPtr = subtree->right;
                subtree->right = subtree;
                subtree = tmpPtr;
                subtree->right = NULL;

            } else {
                Node * tmpPtr = subtree->left;
                subtree->left = subtree;
                subtree = tmpPtr;
                subtree->left = NULL;
            }
        }
        // your code here
    }
}