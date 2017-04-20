#include "FilmFactory.h"
/*Karim Oumghar - Css 343 - Assignment 4 */

//createMovie, returns a movie ptr
//takes a ifstream reference
//splits a line and determines what kind of movie it is
Movie *FilmFactory::createMovie(ifstream &stream)
{
    char type = '\0';
    string actorName, director, actorFirst, actorLast, title, line;
    int year, date, stockCount;

    stream >> type;
    if(type == '\0')//no empty lines...check for empty lines
    {
        getline(stream, line);
        return NULL;
    }
    switch(type)
    {
        case 'C':
            {
                stream.get();
                stream >> stockCount;

                stream.get();
                stream.get();
                getline(stream, director, ',');

                stream.get();
                getline(stream, title, ',');

                stream.get();


                stream >> actorFirst >> actorLast >>date >> year;
                actorName = actorFirst + " " + actorLast;
                ClassicMovie *cm = new ClassicMovie(director, title,
                                                actorName, date, year);
                cm->setStock(stockCount);
                return cm;
            }

        case 'D':
            {
                stream.get();
                stream >> stockCount;

                stream.get();
                stream.get();
                getline(stream, director, ',');

                stream.get();
                getline(stream, title, ',');

                stream.get();
                stream >> year;

                DramaMovie *dm = new DramaMovie(director, title, year);
                dm->setStock(stockCount);

                return dm;
            }
        case 'F':
            {
                stream.get();
                stream >> stockCount;

                stream.get();
                stream.get();
                getline(stream, director, ',');

                stream.get();
                getline(stream, title, ',');

                stream.get();
                stream >> year;

                FunnyMovie *fm = new FunnyMovie(director, title, year);
                fm->setStock(stockCount);
                return fm;
            }
        default:
            {
                getline(stream, line);
                return NULL;
            }
    }

}
