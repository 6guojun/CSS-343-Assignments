

#ifndef TRANSACTION_H
#define TRANSACTION_H


//--------------------------  class Transaction -------------------------------
// Transaction ADT: A collection of certain data including an action, id number
//                  type of media, and movie data.
// Implementation and assumptions:  
//   -- correctly formatted
//-----------------------------------------------------------------------------
#include <iostream>
#include <sstream>
using namespace std;
class Transaction {

public:
	friend ostream& operator<<(ostream& out, const Transaction& data) {
		return data.print(out);
	}
	virtual char getTransactionType() = 0;
private:
	virtual ostream& print(ostream&) const = 0;

};

#endif