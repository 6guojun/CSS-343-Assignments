#include "Borrow.h"
//------------------------------Constructor------------------------------------
// Takes in data in the form of a string to fill in private variables
//-----------------------------------------------------------------------------
Borrow::Borrow(string data) {
	istringstream ss(data);
	ss >> transactionType;
	ss >> clientID;
	ss >> mediaType;
	ss >> movieType;
	getline(ss,movieData);

}
Borrow::~Borrow(){
		movieData = "";
}


//------------------------------print()----------------------------------------
// Takes an ostream as a parameter and prints out info to the ostream
//-----------------------------------------------------------------------------
ostream& Borrow::print(ostream& output) const {
	output << transactionType << " " << clientID <<
		" " << mediaType << " " << movieType << " " << movieData << endl;
	return output;
}

//-------------------------getTransactionType()--------------------------------
char Borrow::getTransactionType() {
	return transactionType;
}
//-------------------------getClientID()---------------------------------------
int Borrow::getClientID() {
	return clientID;
}
//-------------------------getMediaType()--------------------------------------
char Borrow::getMediaType() {
	return mediaType;
}
//-------------------------getMovieType()--------------------------------------
char Borrow::getMovieType() {
	return movieType;
}
//-------------------------getMovieData()--------------------------------------
string Borrow::getMovieData() {
	return movieData;
}

