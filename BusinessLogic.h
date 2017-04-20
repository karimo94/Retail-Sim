#ifndef BUSINESSLOGIC_H
#define BUSINESSLOGIC_H
#include "CustomerDatabase.h"
#include "FilmInventory.h"
#include "ClassicMovie.h"
#include "DramaMovie.h"
#include "FunnyMovie.h"
#include <string>
#include <iostream>
#include <sstream>
/*Karim Oumghar - Css 343 - Assignment 4 */

//BusinessLogic class
//Description: business logic is the main class that performs
//and handles the reading in of transactions/commands
//it has essentially one public method, LoadCommands
//that takes in the stream of data, splits line(s) of
//text, creates a Movie *film and interprets what
//form of action to take based on the data read in
//The rest of the methods are private (like Borrow, History, etc)

//Assumptions: to handle transaction errors, we need to know whether
//or not a transaction was successful, so boolean methods
//are essentially logical, they can even be tested properly
//for example, if some movie wasnt found in the film inventory
//false would be returned and so we would not include it
//in a customers history, extraneous errors such as
//bad transactions or bad genres would be handled with an
//error message
class BusinessLogic
{
    public:
        BusinessLogic();
        ~BusinessLogic();
        void LoadCommands(FilmInventory &f_ref,
                          const CustomerDatabase &c_ref,
                          ifstream &stream);

    protected:
    private:
        bool Borrow(FilmInventory &f_ref, Movie *film);
        bool Return(FilmInventory &f_ref, Movie *film);
        void History(const CustomerDatabase &c_ref, int id) const;
        void PrintInventory(const FilmInventory &f_ref) const;
        string itos(int value);
};

#endif // BUSINESSLOGIC_H
