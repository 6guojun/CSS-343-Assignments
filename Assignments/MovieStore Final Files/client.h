//--------------------------  class Client ----------------------------------
// Client ADT: A collection of certain data including an id number,
//                  firstName,lastName.
// Implementation and assumptions:  
//   -- correctly formatted
//-----------------------------------------------------------------------------

#ifndef CLIENT_H
#define CLIENT_H
#include <queue>
#include "transaction.h"
#include <sstream>
#include "movie.h"
using namespace std;
class Client {
	//defiens a way to print clients
	friend ostream& operator<<(ostream& output, const Client &person);
public:
	Client();
	Client(int id);
	Client(string data); // default constructor
						 // constructor
						 //Client(int num);

						 // De-allocates all memory used
	~Client();
	void displayLog();

	bool operator==(const Client &) const;

	int getId();
	bool insertIntoLog(Transaction* action);
	void borrowItem(Movie*);
	bool returnItem(Movie*&);

private:
	queue<Movie*> itemsBorrowed;
	queue<Transaction*> log; // queue of transactions
	string firstName;
	string lastName;
	int clientId;
};
#endif