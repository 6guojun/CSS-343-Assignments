
/* --------------------------- class Classics ------------------------------
* Classics ADT: Classics is a movie and thus consists of the classic's
* title, director, year of release, and stock. The stock can be increased or
* decreased as needed. Classics can also be compared to each other.
*
* Classics also define both the month of release and major actor's name.
***
* Implementation:
* Inherits from the Movie class (public).
* There is an output operator overload to print out the classic's info.
* There are also greater than, less than, and equal to comparison operators
* along with the assignment operator.
*
* Classics also contain two strings (for the actor's first and last names)
* and another int (for the month of release).
***
* Assumptions:
* --------------------------------------------------------------------------
*/

#ifndef CLASSIC
#define CLASSIC
#include "movie.h"
class Classics : public Movie {
public:
	Classics(string data);
	Classics(int releaseMonth, int releaseYr, string lastName, string
		firstName);
	~Classics();
	string getMajorActor() const;
	int getReleaseYearClassics() const;
	int getReleaseMonth() const;
private:
	string majorActorFirstName = "";
	string majorActorLastName = "";
	int releaseMonth = 0;
private:
	virtual bool equalHelper(const Movie & other) const;
	virtual ostream& print(ostream&) const;
	virtual bool lessThanHelper(const Movie&);
	virtual bool greaterThanHelper(const Movie&);
};
#endif