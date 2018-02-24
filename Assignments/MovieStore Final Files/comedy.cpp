#include "comedy.h"
using namespace std;
//------------------------------Constructor -----------------------------------
// This constructor takes in a string that contains all the information
// relevant to a Comedy movie. It will split and parse information to
// integers as needed.
//-----------------------------------------------------------------------------
Comedy::Comedy(string data) {
	istringstream ss(data);
	string token;
	getline(ss, token, ',');//get the type

	getline(ss, token, ',');//get the quantity
	stock = atoi(token.c_str());

	getline(ss, token, ',');//get the director
    director = token;
	director = director.substr(1,director.length());

	getline(ss, token, ',');//get the title
	title = token;
	title = title.substr(1,title.length());

	getline(ss, token, ',');//get the year of release
	yearOfRelease = atoi(token.c_str());

}
//------------------------------Constructor -----------------------------------
// This constructor takes in the title of the comedy and the year the movie
// was released. This constructor is used for the transaction when creating
// a temporary movie to be found in the trees.
//-----------------------------------------------------------------------------
Comedy::Comedy(string title, int yrReleased) {
	this->title = title;
	this->yearOfRelease = yrReleased;
}
//------------------------------deconstructor ---------------------------------
// There is nothing to deconstruct because not memory was allocated
// dynamically
//-----------------------------------------------------------------------------
Comedy::~Comedy() {

}
//------------------------------lessThanHelper --------------------------------
// This method is a helper method for the operator< in the parent method. It
// will compare the comedy movies based on the title and the year of the
// release.
//-----------------------------------------------------------------------------
bool Comedy::lessThanHelper(const Movie& other) {
	const Comedy* rhs = dynamic_cast<const Comedy*>(&other);
	if (title != rhs->title) {
		return title < rhs->title;
	}
	else {
		return yearOfRelease < rhs->yearOfRelease;
	}
}
//------------------------------greaterThanHelper -----------------------------
// This method is a helper method for the operator> in the parent method. It
// will compare the comedy movies based on the title and the year of the
// release.
//-----------------------------------------------------------------------------
bool Comedy::greaterThanHelper(const Movie& other) {
	const Comedy* rhs = dynamic_cast<const Comedy*>(&other);
	if (title != rhs->title) {
		return title > rhs->title;
	}
	else {
		return yearOfRelease > rhs->yearOfRelease;
	}
}
//------------------------------equalHelper -----------------------------------
// This method is a helper method for the operator== in the parent method. It
// will compare the comedy movies based on the title and the year of the
// release and return true if they are the same. Else return false
//-----------------------------------------------------------------------------
bool Comedy::equalHelper(const Movie &other) const {
    const Comedy* comedyOther = dynamic_cast<const Comedy*>(&other);
	return (getTitle() == comedyOther->getTitle()) &&
		   (getReleaseYear() == comedyOther->getReleaseYear());

}
//------------------------------print -----------------------------------------
// This method is a helper method for the operator<< in the parent method.
// It will print the values stored in the comedy movie in a single ostream
// with no next line character.
//-----------------------------------------------------------------------------
ostream& Comedy::print(ostream & out) const {
	out << "F, " << stock << ", " << director << ", " << title << ", "
		<< yearOfRelease;
    return out;
}