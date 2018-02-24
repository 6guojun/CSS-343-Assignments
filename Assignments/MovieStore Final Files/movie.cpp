#include "movie.h"
//------------------------------getDirector -----------------------------------
// Returns the director string stored in the current movie instance
//-----------------------------------------------------------------------------
string Movie::getDirector() const{
    return director;
}

//------------------------------getReleaseyear --------------------------------
// returns the release year of a movie instance in the form of a int
//-----------------------------------------------------------------------------
int Movie::getReleaseYear() const{
    return yearOfRelease;
}

//------------------------------getTitle-------------------------------------
// Returns a string of the title of a movie instance
//-----------------------------------------------------------------------------
string Movie::getTitle() const{
    return title;
}

//------------------------------ getStock -------------------------------------
// returns the current stock of a movie in the form of an int
//-----------------------------------------------------------------------------
int Movie::getStock() const{
    return stock;
}
//------------------------------operator> -------------------------------------
// this method is a facade for a private method in each of the derived
// children of the movie class. It will return the boolean returned from the
// private method in the derived children.
//-----------------------------------------------------------------------------
bool Movie::operator>(const Movie &other) {
    return this->greaterThanHelper(other);
}
//------------------------------operator< -------------------------------------
// this method is a facade for a private method in each of the derived
// children of the movie class. It will return the boolean returned from the
// private method in the derived children.
//-----------------------------------------------------------------------------
bool Movie::operator<(const Movie &other) {
    return this->lessThanHelper(other);
}
//------------------------------operator==-------------------------------------
// Compares two Movies objects to see if they are equal using the private
// method of the derived children.
//-----------------------------------------------------------------------------
bool Movie::operator==(const Movie &other) {
    return this->equalHelper(other);
}
//------------------------------increaseStock ---------------------------------
// increases the stock of the current movie instance
//-----------------------------------------------------------------------------
bool Movie::increaseStock() {
    stock++;
    return true;
}
//------------------------------decreaseStock ---------------------------------
// decreases the stock of the current movie instance. will not allow the
// movie stock to go below zero.
//-----------------------------------------------------------------------------
bool Movie::decreaseStock() {
    if(stock > 0){
        stock--;
        return true;
    }
    return false;
}

