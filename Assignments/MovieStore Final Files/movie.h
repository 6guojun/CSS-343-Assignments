/* --------------------------- class Movie ------------------------------------
 * Movie ADT: A collection of data relevant to a Movie that include the
 * title, director, yearOfRelease, and stock. This class also provides a
 * skeleton methods that need to be implemented in the children of this
 * parent class.
 * Implementation: NONE
 * Assumptions:
 * --------------------------------------------------------------------------*/
#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>

using namespace std;

class Movie {

public:
	bool increaseStock();
	bool decreaseStock();
	int getStock() const;
	int getReleaseYear() const;
	string getTitle() const;
	string getDirector() const;
    bool operator>(const Movie& other);
    bool operator<(const Movie& other);
    virtual bool operator==(const Movie & other);
    friend ostream& operator<< (ostream& out, const Movie& data){
        return data.print(out);
    }

private:
    virtual ostream& print(ostream&) const = 0;
    virtual bool equalHelper(const Movie & other) const = 0;
    virtual bool lessThanHelper(const Movie&) = 0;
    virtual bool greaterThanHelper(const Movie&) = 0;
protected:
	string title;
	string director;
	int yearOfRelease;
	int stock;
};

#endif