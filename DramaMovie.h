#ifndef DRAMAMOVIE_H
#define DRAMAMOVIE_H
#include "Movie.h"
/*Karim Oumghar - Css 343 - Assignment 4 */

//DramaMovie class, inherits from abstract Movie
//overrides and implements all methods
class DramaMovie:public Movie
{
    public:
        DramaMovie();
        DramaMovie(string director, string title, int year);
        virtual ~DramaMovie();

        char getType() const;

        string getDirector() const;
        void setDirector(string director);

        string getTitle() const;
        void setTitle(string title);

        string getActor() const;
        void setActor(string actor);

        int getYear() const;
        void setYear(int year);

        int getDate() const;
        void setDate(int date);

        int getStock() const;
        void setStock(int stock);

        void displayFilmInfo() const;

        bool operator==(const Movie &ref) const;
        bool operator!=(const Movie &ref) const;
        bool operator<(const Movie &ref) const;
        bool operator>(const Movie &ref) const;
    protected:
    private:
};

#endif // DRAMAMOVIE_H
