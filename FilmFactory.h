#ifndef FILMFACTORY_H
#define FILMFACTORY_H
#include <string>
#include <iostream>
#include "Movie.h"
#include "ClassicMovie.h"
#include "FunnyMovie.h"
#include "DramaMovie.h"
#include <fstream>
#include <sstream>
using namespace std;
/*Karim Oumghar - Css 343 - Assignment 4 */

//FilmFactory class
//implements a static method called createMovie
//that returns a pointer to a movie
//takes an ifstream reference
//no constructors
//it is the main factory pattern class
class FilmFactory
{
    public:
        static Movie* createMovie(ifstream &stream);
    protected:
    private:
};

#endif // FILMFACTORY_H
