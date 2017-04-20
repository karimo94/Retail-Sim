#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <iostream>

using namespace std;
/*Karim Oumghar - Css 343 - Assignment 4 */

//Movie class
//this is an abstract base class that is the basis
//for all movies to inherit from
//it contains a virtual destructor
//and polymorphic getters and setters
class Movie
{
    public:
        Movie();
        virtual ~Movie();

        virtual char getType() const = 0;

        virtual string getTitle() const = 0;
        virtual void setTitle(string title) = 0;

        virtual string getActor() const = 0;
        virtual void setActor(string actor) = 0;

        virtual string getDirector() const = 0;
        virtual void setDirector(string director) = 0;

        virtual int getStock() const = 0;
        virtual void setStock(int stock) = 0;

        virtual int getYear() const = 0;
        virtual void setYear(int year) = 0;

        virtual int getDate() const = 0;
        virtual void setDate(int date) = 0;

        virtual void displayFilmInfo() const = 0;

        virtual bool operator==(const Movie &ref) const = 0;
        virtual bool operator>(const Movie &ref) const = 0;
        virtual bool operator<(const Movie &ref) const = 0;
        virtual bool operator!=(const Movie &ref) const  = 0;
    protected:
        char type;
        string director, title;
        int stock, year, date;
    private:
};

#endif // MOVIE_H
