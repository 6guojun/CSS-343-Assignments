/* --------------------------- class Drama ------------------------------
* Drama ADT: Classics is a movie and thus consists of the Drama's
* title, director, year of release, and stock. The stock can be increased or
* decreased as needed. Classics can also be compared to each other.
*
***
* Implementation:
* Inherits from the Movie class (public).
* There is an output operator overload to print out the classic's info.
* There are also greater than, less than, and equal to comparison operators
* along with the assignment operator.
***
* Assumptions:
* --------------------------------------------------------------------------
*/
#ifndef DRAMA
#define DRAMA

#include "movie.h"
class Drama : public Movie {
public:
	Drama(string data);
	Drama(string title, string director);
	~Drama();
private:
	virtual bool equalHelper(const Movie & other) const;
	virtual ostream& print(ostream&) const;
	virtual bool lessThanHelper(const Movie&);
	virtual bool greaterThanHelper(const Movie&);
};
#endif