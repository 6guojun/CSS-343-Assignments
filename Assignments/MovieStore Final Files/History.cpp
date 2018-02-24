#include "History.h"
//------------------------------Constructor------------------------------------
// Takes in data in the form of a string to fill in private variables
//-----------------------------------------------------------------------------
History::History(string data) {
	istringstream ss(data);
	ss >> transactionType;
	ss >> clientID;
}
//------------------------------getTransactionType()---------------------------
char History::getTransactionType() {
	return transactionType;
}
//------------------------------getClientId()----------------------------------
int History::getClientID() {
	return clientID;
}
//void History::checkHistory(History * action)
//{
//	Store::displayCustomerHistory(action,action->getClientID);
//}


//------------------------------print()----------------------------------------
// Takes an ostream as a parameter and prints out info to the ostream
//-----------------------------------------------------------------------------
ostream& History::print(ostream& output) const {
	output << transactionType << " " << clientID  << endl;
	return output;
}


