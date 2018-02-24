//---------------------------class Return--------------------------------------
// Return ADT: A collection of certain data, id number
//                  type of media, and movie data which represents an action.
// Implementation and assumptions:
//   -- correctly formatted
//-----------------------------------------------------------------------------
#ifndef RETURN
#define RETURN
#include <iostream>
#include <sstream>
#include "transaction.h"
#include "Interactions.h"
using namespace std;
class Return : public Interactions {

public:
	Return(string data);
	char getTransactionType();
	virtual int getClientID();
	char getMediaType();
	virtual char getMovieType();
	virtual string getMovieData();
private:
	ostream & print(ostream & output) const;
	char transactionType; // type of transaction
	int clientID; // id number of client
	char mediaType; // type of media
	char movieType; // type of movie
	int stock;
	string movieData;


};
#endif