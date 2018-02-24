#include "classics.h"
//------------------------------Classics---------------------------------------
// Takes in data in the form of a string to fill in private variables
//-----------------------------------------------------------------------------
Classics::Classics(string data) {
	istringstream ss(data);
	string token = "", placeholder = "";
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

	getline(ss, token, ' ');
	stringstream s(token);
	s >> majorActorFirstName;

	s >> majorActorLastName;

	s >> placeholder;
	releaseMonth = atoi(placeholder.c_str());

	s >> placeholder;
	yearOfRelease = atoi(placeholder.c_str());
}
//------------------------------Classics---------------------------------------
// Takes in data through parameters  to fill in private variables
//-----------------------------------------------------------------------------
Classics::Classics(int releaseMonth, int releaseYr, string lastName, string
	firstName)
{
	this->releaseMonth = releaseMonth;
	this->yearOfRelease = releaseYr;
	this->majorActorFirstName = firstName;
	this->majorActorLastName = lastName;

}
//------------------------------deconstructor----------------------------------
Classics::~Classics() {

}
string Classics::getMajorActor() const {
	return majorActorFirstName + " " + majorActorLastName;
}
int Classics::getReleaseYearClassics() const {
	return yearOfRelease;
}
int Classics::getReleaseMonth() const {
	return releaseMonth;
}
//------------------------------lessThanHelper --------------------------------
// This method is a helper method for the operator< in the parent method. It
// will compare the classics movies based on the year of release and the
// staring acto's first and last name combined
//-----------------------------------------------------------------------------
bool Classics::lessThanHelper(const Movie&other) {
	const Classics* rhs = dynamic_cast<const Classics*>(&other);
	if (yearOfRelease != rhs->yearOfRelease) {
		return yearOfRelease < rhs->yearOfRelease;
	}
	else {
		return majorActorLastName + majorActorFirstName <
			   rhs->majorActorLastName + rhs->majorActorFirstName;
	}
}
//------------------------------greaterThanHelper -----------------------------
// This method is a helper method for the operator> in the parent method. It
// will compare the classics movies based on the year of release and the
// staring acto's first and last name combined
//-----------------------------------------------------------------------------
bool Classics::greaterThanHelper(const Movie&other) {
	const Classics* rhs = dynamic_cast<const Classics*>(&other);
	if (yearOfRelease != rhs->yearOfRelease) {
		return yearOfRelease > rhs->yearOfRelease;
	}
	else {
		return majorActorLastName + majorActorFirstName >
			   rhs->majorActorLastName + rhs->majorActorFirstName;
	}
}
//------------------------------equalHelper -----------------------------------
// This method is a helper method for the operator== in the parent method. It
// will compare theclassics movies based on the year of release and the
// staring acto's first and last name combined and return true if they are
// the same. Else return false
//-----------------------------------------------------------------------------
bool Classics::equalHelper(const Movie &other) const {
	const Classics* classicsOther = dynamic_cast<const Classics*>(&other);
	return
		   (getReleaseYear() == classicsOther->getReleaseYear()) &&
		   (getReleaseMonth() == classicsOther->getReleaseMonth()) &&
		   (getReleaseYear() == classicsOther->getReleaseYear()) &&
		   (getMajorActor() == classicsOther->getMajorActor());
}
//------------------------------print -----------------------------------------
// This method is a helper method for the operator<< in the parent method.
// It will print the values stored in the classics movie in a single ostream
// with no next line character.
//-----------------------------------------------------------------------------
ostream& Classics::print(ostream & out) const {
	out << "C, " << stock << ", " << director << ", " << majorActorFirstName
		<< ", " << majorActorLastName << " " << title << " " << releaseMonth
		<< " " << yearOfRelease;
	return out;
}