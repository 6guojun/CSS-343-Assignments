#ifndef INVER
#define INVER

#include <iostream>
#include <sstream>
#include "transaction.h"
using namespace std;
//---------------------------class Inventory-----------------------------------
// Inventory ADT: An abstract ADT that represents an action within a store
// Assumptions:
//   -- correctly formatted
//-----------------------------------------------------------------------------
class Inventory : public Transaction {
public:
	Inventory(string data);
	char getTransactionType();
private:
	ostream & print(ostream & output) const;
	char transactionType; // type of transaction
};
#endif