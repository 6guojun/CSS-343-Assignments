// ------------------- HashTable Header File ----------------------------------
// Purpose - The purpose of the Hashtable is to quickly store and retrieve
// information from array locations. This hashtable will be used for storing
// and acessing customers as needed.
// ----------------------------------------------------------------------------
// Implementation and assumptions:
//  only clients will be passed into the hashtable
// ----------------------------------------------------------------------------
#ifndef HASHTABLE
#define HASHTABLE
#include "client.h"
using namespace std;

class HashTable {
public:
	HashTable();
	~HashTable();
	HashTable(int);
	//void createTable();
	//bool isEmpty();
	void insert(Client*);
	bool findClient(Client*, Client*&);


protected:
	
	struct Node {            // the node in a linked list
		Client* data;              // pointer to actual data, operations in T
		Node* next;
	};
	struct ColumnNode {
		int id;
		Node* firstNode;
	};
	void makeEmptyHelper(Node * data);
	int hash(Client*);
	ColumnNode* arr;
	int size;
};
#endif