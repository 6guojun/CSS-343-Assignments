#include "drama.h"
//------------------------------Constructor -----------------------------------
// This constructor takes in a string that contains all the information
// relevant to a Comedy movie. It will split and parse information to
// integers as needed.
//-----------------------------------------------------------------------------
Drama::Drama(string data) {
	istringstream ss(data);
	string token;
	getline(ss, token, ',');//get the type

	getline(ss, token, ',');//get the quantity
	stock = atoi(token.c_str());

	getline(ss, token, ',');//get the director
	director = token;
	director = director.substr( 1,director.length());

	getline(ss, token, ',');//get the title
	title = token;
	title = title.substr( 1,title.length());

	getline(ss, token, ',');//get the year of release
	yearOfRelease = atoi(token.c_str());
}
//------------------------------Constructor -----------------------------------
// This constructor takes in the title of the drama and the director. This
// constructor is used for the transaction when creating temporary movie to
// be found in the trees.
//-----------------------------------------------------------------------------
Drama::Drama(string title, string director)
{
	this->title = title;
	this->director = director;
}
//------------------------------deconstructor ---------------------------------
// There is nothing to deconstruct because not memory was allocated
// dynamically
//-----------------------------------------------------------------------------
Drama::~Drama() {

}
//------------------------------lessThanHelper --------------------------------
// This method is a helper method for the operator< in the parent method. It
// will compare the drama movies based on the title and director
//-----------------------------------------------------------------------------
bool Drama::lessThanHelper(const Movie& other) {
	const Drama* rhs = dynamic_cast<const Drama*>(&other);
	if (director != rhs->director) {
		return director < rhs->director;
	}
	else {
		return title < rhs->title;
	}
}
//------------------------------greaterThanHelper -----------------------------
// This method is a helper method for the operator> in the parent method. It
// will compare the drama movies based on the title and the director
//-----------------------------------------------------------------------------
bool Drama::greaterThanHelper(const Movie& other) {
	const Drama* rhs = dynamic_cast<const Drama*>(&other);
	if (director != rhs->director) {
		return director > rhs->director;
	}
	else {
		return title > rhs->title;
	}
}
//------------------------------equalHelper -----------------------------------
// This method is a helper method for the operator== in the parent method. It
// will compare the drama movies based on the title and the director and
// return true if they are the same. Else return false
//-----------------------------------------------------------------------------
bool Drama::equalHelper(const Movie &other) const {
	const Drama* dramaOther = dynamic_cast<const Drama*>(&other);
	return (getTitle() == dramaOther->getTitle()) &&
		   (getReleaseYear() == dramaOther->getReleaseYear()) &&
		   (getDirector() == dramaOther->getDirector());
	return false;
}
//------------------------------print -----------------------------------------
// This method is a helper method for the operator<< in the parent method.
// It will print the values stored in the drama movie in a single ostream
// with no next line character.
//-----------------------------------------------------------------------------
ostream& Drama::print(ostream & out) const {
	out << "D, " << stock << ", " << director << ", " << title << ", "
		<< yearOfRelease;
	return out;
}