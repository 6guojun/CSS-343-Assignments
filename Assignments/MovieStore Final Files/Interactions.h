#ifndef INTER
#define INTER
#include <iostream>
#include <sstream>
#include "transaction.h"
using namespace std;
//---------------------------class Interactions--------------------------------
// Interactions ADT: An abstract ADT that represents interactions between 
// a store and its clients
// Assumptions:
//   -- correctly formatted
//-----------------------------------------------------------------------------
class Interactions : public Transaction {
	public:
	virtual int getClientID() = 0;
	virtual char getMovieType() = 0;
	virtual string getMovieData() = 0;
};
#endif