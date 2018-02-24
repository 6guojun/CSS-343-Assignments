#ifndef BORROW_
#define BORROW_

#include <iostream>
#include <sstream>
#include "transaction.h"
#include "Interactions.h"
//---------------------------class Borrow--------------------------------------
// Borrow ADT: A collection of certain data, id number
//                  type of media, and movie data which represents an action.
// Implementation and assumptions:  
//   -- correctly formatted
//-----------------------------------------------------------------------------
using namespace std;
class Borrow: public Interactions {
public:
	Borrow(string data);
	~Borrow();
	char getTransactionType();
	virtual int getClientID();
	char getMediaType();
	virtual char getMovieType();
	virtual string getMovieData();
private:
	ostream& print(ostream & output) const;
	char transactionType; // type of transaction
	int clientID; // id number of client
	char mediaType; // type of media
	char movieType; // type of movie
	bool returned;
	int stock;
	string movieData;
};
#endif
