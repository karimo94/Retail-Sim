#include "MovieStore.h"
/*Karim Oumghar - Css 343 - Assignment 4 */
MovieStore::MovieStore()
{
    //ctor
}
MovieStore::~MovieStore()
{
    //dtor
}
//readInClients------------------------------------
void MovieStore::ReadInClients(ifstream &stream)
{
    if(stream == NULL)
    {
        cout<<"No text file provided!"<<endl;
    }
    else
    {
        cdb.buildClientDatabase(stream);
    }
}
//readInMovies--------------------------------------
void MovieStore::ReadInMovies(ifstream &stream)
{
    if(stream == NULL)
    {
        cout<<"No text file provided!"<<endl;
    }
    else
    {
        while(!stream.eof())
        {
            Movie *film = FilmFactory::createMovie(stream);
            if(film == NULL)
            {
                continue;
            }
            else
            {
                fdi.insertFilm(film);
            }
        }
    }
}
//readInCommands-------------------------------------------
void MovieStore::ReadInCommands(ifstream &stream)
{
    if(stream == NULL)//handles data errors
    {
        cout<<"No text file provided!"<<endl;
        return;
    }
    else
    {
        bLog.LoadCommands(fdi, cdb, stream);//load from the text file
        return;
    }
}
