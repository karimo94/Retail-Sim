#ifndef MOVIESTORE_H
#define MOVIESTORE_H
#include "CustomerDatabase.h"
#include "FilmFactory.h"
#include "FilmInventory.h"
#include "BusinessLogic.h"
#include <string>
#include <iostream>
/*Karim Oumghar - Css 343 - Assignment 4 */
using namespace std;
//MovieStore class
//Description: this class will act as an interface
//between Main.cpp and working with clients,
//movie storage, and performing transactions
//Assumptions: this class will be kinda minimal
//it needs to handle if there exists some data file
//and if not, handle appropriately
//also....we need to be able to populate
//the customer database (aka hashtable)
//and the film inventory (aka where we store films)
//and be able to process transactions (business logic)
class MovieStore
{
    public:
        MovieStore();
        //3 main public methods
        //one to read in customer data
        //one to read in movie data
        //and one to read in transactions
        //simple!
        void ReadInClients(ifstream &ref);
        void ReadInMovies(ifstream &ref);
        void ReadInCommands(ifstream &ref);
        ~MovieStore();
    protected:
    private:
        CustomerDatabase cdb;
        FilmInventory fdi;
        BusinessLogic bLog;
};

#endif // MOVIESTORE_H
