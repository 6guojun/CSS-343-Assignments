//--------------------------  class movieFactory ------------------------------
// movieFactory ADT: A class used to hide information from the user while
// build the correct movie based on the string pass in
//
// Implementation and assumptions:
//   -- correctly formatted
//-----------------------------------------------------------------------------
#ifndef MOVIESTORE_MOVIEFACTORY_H
#define MOVIESTORE_MOVIEFACTORY_H


#include "movie.h"

class movieFactory {
public:
    static Movie* buildMovie(string);
};


#endif
