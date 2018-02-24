//
// Created by Cameron on 2/28/2017.
//

#include "movieFactory.h"
#include "classics.h"
#include "drama.h"
#include "comedy.h"
//-------------------------buildmovie()----------------------------------------
//Takes a string as a parameter and uses it to decide what type of movie to 
//make
//-----------------------------------------------------------------------------
Movie* movieFactory::buildMovie(string data) {
    switch (data[0]) {
        case 'D':
            return new Drama(data);
            break;
        case 'C':
            return new Classics(data);
            break;
        case 'F':
            return new Comedy(data);
            break;
    }
}