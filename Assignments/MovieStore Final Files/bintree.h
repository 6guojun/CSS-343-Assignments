// ------------------- Polynomials Implementation File ------------------------
// Cameron Padua CSS343 C
// Jan 21, 2016
// Jan 26, 2016
// ----------------------------------------------------------------------------
// Purpose - The purpose of this program is to store and access Movies
// that contain a string of lower case letters. It has has a variety of
// utility functions that will allow the user to accomplish a variety of
// different task inside and to the tree.
// ----------------------------------------------------------------------------
// Specification: This program uses aa Structure similar to a BSTree that
// will sort lower items to the left and larger items to the right. The
// program also stores each Movie inside a Node that will be place in the
// tree.
// This program contains methods to insert, retrieve, print, construct,
// deconstruct, compare, destroy, and
//  Special Algorithms: This code uses an algorithm similar to a binary
// search in the BSTree to array
//  Assumptions: No bad lines of input will be inserted.
//  The program will be run on c++11
// ----------------------------------------------------------------------------
#ifndef ASS2_BINTREE_H
#define ASS2_BINTREE_H
#include <string>
#include <iostream>
#include <fstream>
#include "movie.h"
#include <algorithm> 
using namespace std;

class BinTree {                             //open class brace
public:
    //contructors
    BinTree();								// constructor
    BinTree(const BinTree &);				// copy constructor
    ~BinTree();								// destructor, calls makeEmpty
    //operators
    friend ostream& operator<< (ostream& out, const BinTree&); //Friend
                                                // operator to print a tree
    bool operator==(const BinTree &) const; //operator to check the equality
                                            // of two trees
    bool operator!=(const BinTree &) const; //operator to check if two trees
                                            // are not the same
    // Utility Methods
    bool isEmpty() const;					// Method to check if tree is empty
    void makeEmpty();						// make the tree empty so isEmpty
    //returns true
    bool insert(Movie*);                 //method used to insert a
                                            // Movie into the tree
    bool retrieve(const Movie&, Movie*&) const; //method to retrieve a
                                            // Movie from the tree
    int getHeight(const Movie&) const;   //method to get the height of a
                                            // Movie
    void bstreeToArray(Movie* []);       //Method to convert a tree into
                                            // an array
    void arrayToBSTree(Movie* []);       //method to convert an array to a
                                            // tree
    void displaySideways() const;			// display a tree sideways

private:
    //the Node for storing a Movie in the tree
    struct Node {                           //open struct brace
        Movie* data;						// pointer to data object
        Node* left;							// left subtree pointer
        Node* right;						// right subtree pointer
    };                                      //close struct brace
    Node* root;								// root of the tree
    //helper methods
    bool retrieveHelper(const Node*, const Movie&,
                        Movie* &) const; //helper to retrieve the Movie
    bool insertHelper(Node*&, Movie*);   //helper to insert a Movie
    int getHeightHelper(const Node*) const; //helper to get the height
    int getHeightNodeHelper(const Node*,
                            const Movie&) const; //helper to get the node
                                                    // for height
    void sideways(Node*, int) const;	    //helper for displaySideways()
    void clear(Node*& subtree);             //helper to clear a tree of nodes
    void inOrderWalk(Node* subtree) const;  //helper to print tree
    bool equalityOperatorHelper(Node*, Node*) const; //helper to check equality
    void arrayToBSTreeHelper(Movie* [], int, int); //helper to convert
                                                      // array to tree
    int bstreeToArrayHelper(Node* subtree, Movie* []); //helper to convert
                                                    // tree to an array
};                                          //close class brace
#endif //ASS2_BINTREE_H
