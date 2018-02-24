/* --------------------------- class Comedy ------------------------------
* Comedy ADT: Comedy is a movie and thus consists of the comedy's
* title, director, year of release, and stock. The stock can be increased or
* decreased as needed. Comedy can also be compared to each other.
*
***
* Implementation:
* Inherits from the Movie class (public).
* There is an output operator overload to print out the classic's info.
* There are also greater than, less than, and equal to comparison operators
* along with the assignment operator.
*
***
* Assumptions:
* --------------------------------------------------------------------------
*/
#ifndef COMEDY
#define COMEDY
#include "movie.h"
#include "movie.h"
class Comedy : public Movie {
public:
	Comedy(string data);
	Comedy(string title, int yrReleased);
    ~Comedy();
private:
	virtual bool equalHelper(const Movie & other) const;
    virtual ostream& print(ostream&) const;
    virtual bool lessThanHelper(const Movie&);
    virtual bool greaterThanHelper(const Movie&);
};
#endif
