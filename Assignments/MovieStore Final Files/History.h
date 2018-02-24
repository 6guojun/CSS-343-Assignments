#ifndef HISTORY
#define HISTORY

#include <iostream>
#include <sstream>
#include "transaction.h"
using namespace std;
//---------------------------class History-------------------------------------
// History ADT: A collection of certain data, which represents an action.
// Implementation and assumptions:  
//   -- correctly formatted
//-----------------------------------------------------------------------------
class History : public Transaction {
public:
	History(string data);
	char getTransactionType();
	int getClientID();
	static void checkHistory(History*);
private:
	ostream & print(ostream & output) const;
	char transactionType; // type of transaction
	int clientID;
    
};
#endif