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
#include "bintree.h"

const int ARRAYSIZE = 100;  //constant size for any array converted to tree 
                            // or vis-versa
// ---------------------- Default Constructor ---------------------------------
// Description: This is the default constructor for the BinTree class. This 
// constructor will set the root pointer of the BinTree to nullptr.
// Preconditions: NONE
// Postconditions: Bintree root is set to nullptr
// ----------------------------------------------------------------------------
BinTree::BinTree() {        
    root = nullptr;         //set the root pointer to nullptr
}
// ------------------------- Copy Constructor ---------------------------------
// Description: This is the copy constructor for the Bintree class. This 
// constructor will make a deep copy of the Bintree passed in and set this 
// tree to the copied tree
// Preconditions: A constant Bintree address
// Postconditions: This Bintree is set to a deep copy of another Bintree
// ----------------------------------------------------------------------------
BinTree::BinTree(const BinTree& copyTree) {
    root = nullptr;         //set this tree to a nullptr
    *this = copyTree;       //use the assignment operator to make a deep copy
}

// ---------------------------- Deconstructor ---------------------------------
// Description: This is the class deconstructor. This deconstructor will free
// and memory being used by the tree and set the root to a nullptr. It calls
// the makeEmpty method
// Preconditions: a instance of a tree
// Postconditions: Bintree memory deallocated and root set to nullptr
// ----------------------------------------------------------------------------
BinTree::~BinTree() {
    makeEmpty();        //clear the memory of the tree
    root = nullptr;     //set class root to nullptr
}

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: bintree remains unchanged.
void BinTree::displaySideways() const {
    sideways(root, 0);
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: bintree remains unchanged.
void BinTree::sideways(Node* current, int level) const {
    if (current != nullptr) {
        level++;
        sideways(current->right, level);

        // indent for readability, 4 spaces per depth level
        for (int i = level; i >= 0; i--) {
            cout << "    ";
        }

        cout << *current->data << endl;        // display information of object
        sideways(current->left, level);
    }
}
// ------------------------- MakeEmpty ----------------------------------------
// Description: This method will check if the tree is empty, if not it will
// deallocate any memory being used by the tree and deconstruct any nodes.
// This method calls the clear method
// Preconditions: an instance of a bintree
// Postconditions: bintree is destroyed and tree is deallocated
// ----------------------------------------------------------------------------
void BinTree::makeEmpty() {
    if(!isEmpty())
        clear(root);
}
// ------------------------------------ clear ---------------------------------
// Description: This method will destroy all nodes inside the tree and
// deallocate the memory. It uses a postorder method to go the the children
// of a node before the parent and delete them after data has been deleted
// Preconditions: An instance of a bintree
// Postconditions: Bintree is destroyed and memory deallocated
// ----------------------------------------------------------------------------
void BinTree::clear(Node*& subtree) {
    if(subtree != nullptr){             //if the node is not null
            clear(subtree->left);       //recurse to the left node
            clear(subtree->right);      //recurse to the right node
        if(subtree->data != nullptr){   //check if the data is null
            delete subtree->data;       //destroy the node data
            subtree->data = nullptr;    //set the data pointer to null
        }
        delete subtree;                 //delete the current node
        subtree = nullptr;              //set the current node to nullptr
    }
}
// ------------------------- IsEmpty -----------------------------------------
// Description: This method checks if the root of the tree is pointing to null
// Preconditions: An instance of a bintree
// Postconditions: bintree is not changed
// ----------------------------------------------------------------------------
bool BinTree::isEmpty() const {
    return root == nullptr;     //checks if the root is pointing to null
}
// ------------------------- retrieve ---------------------------------
// Description: This method will retrieve a Movie from a node inside the
// tree. It uses a constant Movie to find the Movie inside the tree. It
// calls a helper method to find the Node
// Preconditions: none
// Postconditions: tree is not changed. returns a boolean if Nodedata was found
// ----------------------------------------------------------------------------
bool BinTree::retrieve(const Movie& target, Movie*& retrieved) const {
    return retrieveHelper(root, target, retrieved); //calls helper method
                                                    // with tree root, target,
                                                    // and storage Movie
}
// ------------------------- retrieveHelpet ---------------------------------
// Description: This method recursively iterates through the tree to find a
// Nodedata stored inside a Node. This method does not assume that this is a
// BSTree and searches all nodes until found.
// Preconditions: none
// Postconditions: bintree is not changed and nodedata is retrieved from tree.
// ----------------------------------------------------------------------------
bool BinTree::retrieveHelper(const Node *subtree, const Movie& target,
                             Movie* &retrieved) const {
    if(subtree == nullptr) {            //case: node is null
        retrieved = nullptr;            //set retrieved to nullptr
        return false;                   //return false, target was not found
    }else if(*subtree->data == target){ //case: node's data is the target
        retrieved = subtree->data;      //set the retrieved to the node's data
        return true;                    //return true, it found the data
    }else{                              //case: keep looking
        return retrieveHelper(subtree->left, target, retrieved) ||
                 retrieveHelper(subtree->right, target, retrieved); // check
        // the left nodes and right nodes for the data, if either have data,
        // return true.
    }
}
// ------------------------- insert ---------------------------------
// Description: This method will insert a Movie into the tree. It uses a
// helper method to recurse through nodes
// Preconditions: non
// Postconditions: a new node in the bintree
// ----------------------------------------------------------------------------
bool BinTree::insert(Movie* inserted) {
   return insertHelper(root, inserted); //call the insertHelper with root and
                                        // data to be inserted
}
// ------------------------- insertHelper ---------------------------------
// Description: This method recurse through the tree assuming it is a BSTree
// structure. It will create a new node for the data to be inserted into and
// stored in the tree.
// Preconditions: a tree and a data to insert
// Postconditions: a new node inside the tree
// ----------------------------------------------------------------------------
bool BinTree::insertHelper(Node*& subtree, Movie* inserted) {
    if(subtree == nullptr ||
            subtree->data == nullptr) { //case: node or nodedata is null
        subtree = new Node;             //create a new node
        subtree->data = inserted;       //set new node's data
        subtree->left = nullptr;        //set the left pointer to null
        subtree->right = nullptr;       //set the right pointer to null
        return true;                    //return true, data was inserted
    }else if(*subtree->data > *inserted){   //case: current node data is
                                            // larger, need to go to the left
        return insertHelper(subtree->left, inserted);   //recurse left
    }else if(*subtree->data < *inserted){   //case: current node data is
                                            // smaller, recurse right
        return insertHelper(subtree->right, inserted);  //recurse right
    }else {                                 //case: nodedata exists in tree
        return false;                       //data was not inserted
    }
}
// ------------------------- getHeight ---------------------------------
// Description: This method will find a Movie inside the tree and return
// its relative height including itself. If the Movie if the leaf, it will
// return one, if it is the parent to a leaf, it will return 2 and so on. If
// the Movie is not in the tree, it will return 0. This method calls two
// helper methods, one is called from here and the other in the helper. One
// helper is to find the node, and the other is to find the actual height.
// Preconditions: a instance of a bintree and a Movie
// Postconditions: Tree remains unchanged and returns an int of height
// ----------------------------------------------------------------------------
int BinTree::getHeight(const Movie& data) const {
    return getHeightNodeHelper(root, data); //call the getHeight method

}
// ------------------------- getHeightNodeHelper ------------------------------
// Description: This helper method will find a Movie inside the tree and
// call the second helper method to get the height of that node. If the
// Movie does not exist in the tree, it will return 0 from here. This
// method recurse through the nodes assuming this is not a BSTree.
// Preconditions: a root/subtree. and a target Movie
// Postconditions: Tree is unchanged, returns an int of ehight
// ----------------------------------------------------------------------------
int BinTree::getHeightNodeHelper(const Node* subtree,
                                 const Movie& target) const {
    if (subtree == nullptr) {        //case: node is null
        return 0;                    //data is not here, return zero
    } else if (*subtree->data == target) { //case: the node contains the data
        return getHeightHelper(subtree);// call the second helper method with
                                        // node
    } else {                         //case: data not found, check other nodes
        return max(getHeightNodeHelper(subtree->left, target),
                   getHeightNodeHelper(subtree->right, target));//this will
                            // find the node with the largest height, by
                            // comparing recursive elements

    }
}
// ------------------------- getHeightHelper ---------------------------------
// Description: This helper method returns the height of the node from the
// lowest leaf in the branch. It does this by recursing through the node,
// adding one and find the largest number between its children.
// Preconditions: A node of target
// Postconditions: tree remains unchanged. Int returned
// ----------------------------------------------------------------------------
int BinTree::getHeightHelper(const Node* subtree) const{
    if(subtree == nullptr){     //case: node is empty/does not exist
        return 0;               //return 0;
    }else{                      //case: need to find the largest child branch
        return 1 + max(getHeightHelper(subtree->left),
                       getHeightHelper(subtree->right)); //add 1 and find the
                                                        // larger child branch
    }
}
// ------------------------- operator<< ---------------------------------------
// Description: This method will print out a tree in a single line in an
// inorder walk over the tree. It uses one helper method to recurse through
// tree and print each left child before the parent node.
// Preconditions: an bintree instance, and a out steam
// Postconditions: tree remains unchanged. outstream produced
// ----------------------------------------------------------------------------
ostream& operator<<(ostream& out, const BinTree& tree) {
    tree.inOrderWalk(tree.root);    //call helper method to print
    out << endl;                    //add a endl afet line
    return out;                     //return outstream
}
// ------------------------- inOrderHelper ------------------------------------
// Description: This helper method prints the tree inorder by recursing
// through each node. It will go to the left most node, print, then to
// parent, then print, then right and repeat cycle.
// Preconditions: a node of the current subtree
// Postconditions: tree remains unchanged
// ----------------------------------------------------------------------------
void BinTree::inOrderWalk(Node *subtree) const {
    if (subtree != nullptr) {           //case: node is not null
        inOrderWalk(subtree->left);     //go to the left most node
        cout << *subtree->data << endl;  //then print current data
        inOrderWalk(subtree->right);    //then right child
    }
}

// ------------------------- operator== ---------------------------------
// Description: This method compares two bintrees and returns true if they
// have the same contents. It will return false otherwise. This method uses a
// helper method to recurse through the tree and check each data item inside.
// Preconditions: A bintree instance and other bintree
// Postconditions: tree remains unchanged. returns a boolean
// ----------------------------------------------------------------------------
bool BinTree::operator==(const BinTree& otherTree) const {
    if(isEmpty() && otherTree.isEmpty()){   //case: trees are empty
        return true;                        //return that they are the same
    }else{                                  //case: check the nodes
        return equalityOperatorHelper(root, otherTree.root); //call helper
    }
}
// ------------------------- equalityOperatorHelper ---------------------------
// Description: This helper method will check each location of a two trees to
// make sure they are the same data. It uses a preorder walkthrough to check
// parents then children for their data. If at any time the data is not the
// same, return false
// Preconditions: two nodes correponding to the same location in a tree
// Postconditions: tree remains unchanged. boolean returned
// ----------------------------------------------------------------------------
bool BinTree::equalityOperatorHelper(Node* subtree, Node* otherSubtree) const{
        if(subtree == nullptr && otherSubtree == nullptr){//case: both at
                                                            // null node
            return true;                                    //branches are
                                                            // the same
        }
        if(subtree == nullptr || otherSubtree == nullptr){//case: one or the
                                                // other is pointing to a null
            return false;                       //branches are different
        }
    if (*subtree->data == *otherSubtree->data
        && subtree->left == nullptr && otherSubtree->left == nullptr
        && subtree->right == nullptr && otherSubtree->right == nullptr) {
        //case: data is the same, and both pointers are pointing to null for
        // both trees
        return true;
    }
    //left or right is not null, continue to check left and right pointers,
    // recursive interation
    return (*subtree->data == *otherSubtree->data
            && equalityOperatorHelper(subtree->left, otherSubtree->left)
            && equalityOperatorHelper(subtree->right, otherSubtree->right));
}
// ------------------------- operator!= ---------------------------------
// Description: This method will return if two trees are not the same. True
// if they are not, false otherwise. It uses the operator== method to get if
// they are the same, then negate it.
// Preconditions: two bintrees
// Postconditions: tree remains unchanged. boolean returned
// ----------------------------------------------------------------------------
bool BinTree::operator!=(const BinTree& otherTree) const {
    return !(*this == otherTree);   //negate the equality operator
}
// ------------------------- arrayToBSTree ---------------------------------
// Description: This method will convert an array of Movie to a BinTree.
// It has a recursive method helper to insert the data. This method will
// count how many items are in the array before calling the helper method.
// Preconditions: an array of Movie
// Postconditions: new bintree has been built and has elements inside
// ----------------------------------------------------------------------------
void BinTree::arrayToBSTree(Movie* array[]) {
    int maxSize = 0;        //number of elements in the array
    for(int current = 0; current < 100; current++){ //loop through array
        if(array[current] != nullptr){  //until an element in the array is null
            maxSize++;                  //if not, increase size by one
        }else {                         //case: elemet is null
            break;                      //break out of loop
        }
    }
    if(maxSize!=0) {        //case: not an empty array
        arrayToBSTreeHelper(array, 0, maxSize - 1); //call helper method
    }else{                  //case: array is empty, set root to nullptr
        root = nullptr;
    }
}
// ------------------------- arrayToBSTreeHelper  -------------------------
// Description: This helper method is similar to the binarysearch, except it
// will insert data at every iteration. It will find the mid, insert the mid
// value of the array, then recurse to left and right half beside the mid in
// the array.
// Preconditions: an array of Movie, a low, and a high
// Postconditions: new bintree has been built and has elements inside
// ----------------------------------------------------------------------------
void BinTree::arrayToBSTreeHelper(Movie* array[],int low, int high){
    if(low>high){                   //case: time to end the recursion
        return;                     //break recursion
    }else{                          //case: low is not greater than high
        int mid = (low + high) / 2; //get mid value
        Movie* temp = array[mid];//create a pointer to value in array
        array[mid] = nullptr;       //set array location to nullptr
        insert(temp);               //insert temp value
        arrayToBSTreeHelper(array,low, mid -1); //recurse for left half
        arrayToBSTreeHelper(array, mid+1, high);//recurse for right half
    }
}
// ------------------------- BSTreeToArray ---------------------------------
// Description: This mehtod will break down a BSTree to an array inorder of
// their location meaning that it will be the left most child first, then
// their parent, etc. It has a helper method to do the inorder walk and
// clears the tree after.
// Preconditions: an array to store values inside, empty
// Postconditions: tree destroyed, array has elements
// ----------------------------------------------------------------------------
void BinTree::bstreeToArray(Movie * array[]) {
    bstreeToArrayHelper(root, array);       //call helper method
    this->makeEmpty();                      //destroy tree
}
// ------------------------- bstreeToArrayHelper ------------------------------
// Description: This method recurses through a tree setting elements of the
// array to data items in the tree. It will go to the left most child and
// then begin the interations back up. The left most child will be the
// element 0 and the right most will be last element.
// Preconditions: an empty array, and a root to a tree
// Postconditions: tree remains unchanged, array has elements
// ----------------------------------------------------------------------------
int BinTree::bstreeToArrayHelper(Node *subtree, Movie * array[]) {
    if(subtree == nullptr){     //case: node is null, go back up to add element
        return 0;
    }
        int left = bstreeToArrayHelper(
                subtree->left, array);//keep a count of what location of the
                            // array the value should be added to the array
        Movie* temp = subtree->data; //create a temp Movie to the tree
                                        // data
        *(array + left) = temp;         //set the location in the array to
                                        // the temp Node Data
        subtree->data = nullptr;        //set the tree node data to null
        temp = nullptr;                 //set temp nodedata to null
        int right = bstreeToArrayHelper(
                subtree->right, array + left + 1); //recurse through right
                                                    // nodes
    return left + right + 1;           //add left and right + 1 for the next
                                        // array location
}


