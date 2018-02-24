#include "Return.h"
//------------------------------Constructor------------------------------------
// Takes in data in the form of a string to fill in private variables
//-----------------------------------------------------------------------------
Return::Return(string data) {
	istringstream ss(data);
	ss >> transactionType;
	ss >> clientID;
	ss >> mediaType;
	ss >> movieType;
	getline(ss, movieData);
}


//------------------------------print()----------------------------------------
// Takes an ostream as a parameter and prints out info to the ostream
//-----------------------------------------------------------------------------
ostream& Return::print(ostream& output) const {
	output << transactionType << " " << clientID << " " << mediaType <<
		" " << movieType << " " << movieData << endl;
	return output;
}
//-------------------------getTransactionType()--------------------------------
char Return::getTransactionType() {
	return transactionType;
}
//-------------------------getClientID()---------------------------------------
int Return::getClientID() {
	return clientID;
}
//-------------------------getMediaType()--------------------------------------
char Return::getMediaType() {
	return mediaType;
}
//-------------------------getMovieType()--------------------------------------
char Return::getMovieType() {
	return movieType;
}
//-------------------------getMovieData()--------------------------------------
string Return::getMovieData() {
	return movieData;
}

