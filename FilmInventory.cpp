#include "FilmInventory.h"
/*Karim Oumghar - Css 343 - Assignment 4 */
FilmInventory::FilmInventory()
{
    //ctor
}

FilmInventory::~FilmInventory()
{
    //dtor
}
void FilmInventory::displayFilms() const
{
    classicFilmBST.display();
    dramaFilmBST.display();
    funnyFilmBST.display();
}
//insertFilm, takes a movie ptr
//returns void
//first check if a film exists, if so
//update the entry
//otherwise insert into proper bst
void FilmInventory::insertFilm(Movie *film)
{
    char genre = film->getType();

    switch(genre)
    {
        case 'C':
            {
                //retrive film first...
                //no duplicates
                if(classicFilmBST.findMovie(*film))
                {
                    classicFilmBST.updateFilm(film, film->getStock());
                    return;
                }
                //else, a new film, insert accordingly
                classicFilmBST.insert(film);
                return;
            }
        case 'D':
            {
                if(dramaFilmBST.findMovie(*film))
                {
                    dramaFilmBST.updateFilm(film, film->getStock());
                    return;
                }
                dramaFilmBST.insert(film);
                return;
            }
        case 'F':
            {
                if(funnyFilmBST.findMovie(*film))
                {
                    funnyFilmBST.updateFilm(film, film->getStock());
                    return;
                }
                funnyFilmBST.insert(film);
                return;
            }
        default:
            {
                cout<<"Invalid movie genre"<<endl;
                return;
            }
    }
}
//transactionFilm, returns boolean sucessfull or no
//takes a movie ptr
bool FilmInventory::transactionFilm(Movie *film)
{
    //use this strictly for film transactions
    //NOT POPULATING THE INVENTORY!
    char type = film->getType();
    switch(type)
    {
    case 'C':
        {
            return classicFilmBST.movieTransaction(film);
        }
    case 'D':
        {
            return dramaFilmBST.movieTransaction(film);
        }
    case 'F':
        {
            return funnyFilmBST.movieTransaction(film);
        }
    default:
        {
            return false;
        }
    }
}
