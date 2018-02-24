#include "client.h"
//--------------------------------constructor----------------------------------
Client::Client() {

}
//------------------------------Client-----------------------------------------
// Takes in data in the form of a string to fill in private variables
//-----------------------------------------------------------------------------
Client::Client(string data) {
	istringstream str(data);
	str >> clientId;
	str >> lastName;
	str >> firstName;
}
//------------------------------deconstructor----------------------------------
Client::~Client() {

}

void Client::displayLog() {
	cout << "Client " << clientId << "'s Transaction History" << endl;
    for(int current = 0; current < log.size(); current++){
		Transaction* action = log.front();
		log.pop();
		cout << *action;
		log.push(action);
	}
	cout << endl;
}
//------------------------------Client-----------------------------------------
// Takes in data through a parameter to fill in a private variable
//-----------------------------------------------------------------------------
Client::Client(int id) {
	clientId = id;
}
//------------------------------getId()----------------------------------------
int Client::getId() {
	return clientId;
}

//------------------------------operator==-------------------------------------
// Compares two Client objects to see if they are equal
//-----------------------------------------------------------------------------
bool Client::operator==(const Client & other) const {
	if (other.clientId == clientId) {
		return true;
	}
	else {
		return false;
	}
}
//-----------------------------insertIntoLog-----------------------------------
// pushes the transaction parameter into the queue of things to do
//-----------------------------------------------------------------------------
bool Client::insertIntoLog(Transaction* action) {
	log.push(action);
	return true;
}
//-----------------------------borrowItem()------------------------------------
// keeps a record of the movies the client has borrowed
//-----------------------------------------------------------------------------
void Client::borrowItem(Movie * item)
{
	Movie* borrowedItem = item;
	itemsBorrowed.push(borrowedItem);
}
//-----------------------------returnItem()------------------------------------
// checks that the client has the movie he wants to return
//-----------------------------------------------------------------------------
bool Client::returnItem(Movie *& item)
{
	for (int i = 0; i < itemsBorrowed.size(); i++) {
		Movie * temp = itemsBorrowed.front();
		if (temp->getTitle()==(item->getTitle())) {
		    itemsBorrowed.pop(); // unsure if the pointer gets destroyed at
            // the end of the method
			return true;
			break;
		}
		else {
			itemsBorrowed.pop();
			itemsBorrowed.push(temp);
		}
	}
	return false;
}
