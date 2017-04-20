#ifndef CLASSICMOVIE_H
#define CLASSICMOVIE_H
#include "Movie.h"
/*Karim Oumghar - Css 343 - Assignment 4 */

//ClassicMovie, inherits from abstract Movie
//implements and overrides all methods
//has a specific actor attribute
class ClassicMovie:public Movie
{
    public:
        ClassicMovie();
        ClassicMovie(string director, string title,
                     string actor, int date, int year);
        virtual ~ClassicMovie();

        char getType() const;

        string getDirector() const;
        void setDirector(string director);

        string getTitle() const;
        void setTitle(string title);

        string getActor() const;
        void setActor(string actor);

        int getDate() const;
        void setDate(int date);

        int getYear() const;
        void setYear(int year);

        int getStock() const;
        void setStock(int stock);

        void displayFilmInfo() const;

        bool operator==(const Movie &ref) const;
        bool operator!=(const Movie &ref) const;
        bool operator<(const Movie &ref) const;
        bool operator>(const Movie &ref) const;
    protected:
    private:
        string actor;
        int date;
};

#endif // CLASSICMOVIE_H
