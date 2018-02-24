#include "HashTable.h"

using namespace std;
//------------------------------ Default Constructor --------------------------
// This constructor will create a new array containing a list of linked list
// nodes and initialize each node to null first nodes. and the id of each
// node to their placement in the array.
//-----------------------------------------------------------------------------
HashTable::HashTable() {
	arr = new ColumnNode[991];
	size = 991;
	for (int i = 0; i < size; i++) {
		arr[i].id = i;
		arr[i].firstNode = NULL;
	}
}
//------------------------------ Constructor ----------------------------------
// This constructor takes in an int that represents the number of array
// locations in the hashtable. It will then initialize each array location
// to a empty node.
//-----------------------------------------------------------------------------
HashTable::HashTable(int columns) {
	arr = new ColumnNode[columns];
	size = columns;
	for (int i = 0; i < columns; i++) {
		arr[i].id = i;
		arr[i].firstNode = NULL;
	}
}
//------------------------------deconstructor ---------------------------------
// Deconstructs all the linked lists in each of the array locations using
// the makeEmptyHelper.
//-----------------------------------------------------------------------------
HashTable::~HashTable() {
	for (int i = 0; i < size; i++) {
		if (arr[i].firstNode != NULL) {
			makeEmptyHelper(arr[i].firstNode);
		}
	}
	delete[] arr;
}
//------------------------------makeEmptyHelper -------------------------------
// this method will walk a linked list. It will walk to the end of a list,
// then recurse back up deallocating  each node.
//-----------------------------------------------------------------------------
void HashTable::makeEmptyHelper(Node* dataContainer) {
	if (dataContainer != NULL) {
		makeEmptyHelper(dataContainer->next);
		delete dataContainer->data;
	    delete dataContainer;
	}
}
//------------------------------ hash -----------------------------------------
// This method will assign a array location to a value passed in. It uses
// the clients ID divided by 10 to find the array location and returns the
// array location
//-----------------------------------------------------------------------------
int HashTable::hash(Client* customer) {
	int key = customer->getId();
	while (key > 10) {
		key /= 10;
	}
	return key;
}
//------------------------------ insert ---------------------------------------
// This method will insert a customer into a linkedlist by creating a new
// node and making the head of the list be the new node. Insert the value
// and set the new nodes next to the original head
//-----------------------------------------------------------------------------
void HashTable::insert(Client* customer) {
	int key = hash(customer);
	Node* tmp = arr[key].firstNode;
	arr[key].firstNode = new Node();
	arr[key].firstNode->data = customer;
	arr[key].firstNode->next = tmp;
}
//------------------------------ findClient -----------------------------------
// This method will find a client inside the hashtable. if the client is
// found, it will set the parameter location for the client found and return
// true. If not found, retrieved will be set to nullptr and it will return
// false
//-----------------------------------------------------------------------------
bool HashTable::findClient(Client* target, Client *& retrieved){
	int arrayLocation = hash(target);
	Node* current = arr[arrayLocation].firstNode;
	if (current == NULL) {
		return false;
	} else {
		while (current != NULL) {
			if (*current->data == *target) {
				retrieved = current->data;
				return true;
			} else {
				current = current->next;
			}
		}
		retrieved = NULL;
		return false;
	}
}

