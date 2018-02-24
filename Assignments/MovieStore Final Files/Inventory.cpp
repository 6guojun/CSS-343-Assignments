#include "Inventory.h"
//------------------------------Constructor------------------------------------
// Takes in data in the form of a string to fill in private variables
//-----------------------------------------------------------------------------
Inventory::Inventory(string data) {
	transactionType = data[0];
	//cout << getTransactionType() << endl;
}
//------------------------------print()----------------------------------------
// Takes an ostream as a parameter and prints out info to the ostream
//-----------------------------------------------------------------------------
ostream& Inventory::print(ostream& output) const {
	output << transactionType << endl;
	return output;
}
//-------------------------getTransactionType()--------------------------------
char Inventory::getTransactionType() {
	return transactionType;
}

