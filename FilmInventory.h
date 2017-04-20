#ifndef FILMINVENTORY_H
#define FILMINVENTORY_H
#include "Movie.h"
#include <string>
#include <iostream>
using namespace std;
/*Karim Oumghar - Css 343 - Assignment 4 */

//FilmInventory class
//Description: this class ultimately handles storage of movies
//using binary search trees
//the binary search tree class is in itself a nested class
//with in this .h (for encapsulation purposes)
//As for the FilmInventory class, it has 4 methods
//one to display all the films in the inventory
//one to insert a film
//one to remove a film
//and one to update the inventory for a transaction (transaction film())

//Assumptions: because we're storing movies using binary search trees
//we need 3 instances (to store according to respective genre)
//so DramaMovies have a BST and so forth

class FilmInventory
{
    public:
        FilmInventory();
        ~FilmInventory();
        void displayFilms() const;
        void insertFilm(Movie *film);
        void removeFilm(Movie *&target);
        bool transactionFilm(Movie *film);
    protected:
    private:
        //************BST implementation begins here**************
        //Description: we make this nested class private inside
        //of FilmInventory.h so that no other classes can
        //see or modify it in an improper way
        //it has a node struct that contains a
        //pointer to a movie, and usual left & right ptrs

        struct node
        {
            Movie *f_data;
            node * left;
            node * right;
        };
        class FilmBST
        {

            node *root;
            public:
                FilmBST()
                {
                    root = NULL;//always set the root to null
                }
                ~FilmBST()
                {
                    //delete everything and set the root to null
                    deleteAll(root);
                    root = NULL;
                }
                //insert, returns void
                //takes a movie *film pointer
                //inserts accordingly
                void insert(Movie *film)
                {
                    node *nObj = new node;
                    nObj->f_data = film;
                    nObj->left = NULL;
                    nObj->right = NULL;
                    if(root == NULL)
                    {
                        root = nObj;
                        return;
                    }
                    else
                    {
                        node *current = root;
                        node *parent = NULL;
                        while(current != NULL)
                        {
                            parent = current;
                            if(*current->f_data > *nObj->f_data)
                            {
                                current = current->left;
                                if(current == NULL)
                                {
                                    parent->left = nObj;
                                }
                            }
                            else
                            {
                                current = current->right;
                                if(current == NULL)
                                {
                                    parent->right = nObj;
                                }
                            }
                        }
                    }
                }
                //display, returns void, uses a displayHelper (private)
                void display() const
                {
                    displayHelper(root);
                }
                //updateFilm, returns void
                //trakes a film reference, and stock (int)
                //searches for a film, and if found, update the stock
                //
                void updateFilm(Movie *&film, int stock)
                {
                    //retrieve the film
                    //if found, update the stock count

                    node *current = root;
                    bool isFound = false;
                    if(empty())
                    {
                        cout<<"No movies in the inventory"<<endl;
                        return;
                    }
                    while(current != NULL && !isFound)
                    {
                        if(*film == *current->f_data)
                        {
                            isFound = true;
                            int filmCount = current->f_data->getStock();
                            current->f_data->
                            setStock(filmCount + stock);
                        }
                        if(*current->f_data > *film)
                        {
                            current = current->left;
                        }
                        else
                        {
                            current = current->right;
                        }
                    }
                }
                //empty(), returns boolean true/false if root is null
                bool empty() const
                {
                    return(root == NULL);
                }
                //findMovie(), returns boolean
                //true if successfully found, false otherwise
                //takes a const Movie reference
                bool findMovie(const Movie &ref) const
                {
                    //find the film
                    //if it doesnt exist...
                    //return null
                    if(empty())
                    {
                        return false;
                    }
                    bool isFound = false;
                    node *current = root;
                    while(current != NULL && !isFound)
                    {
                        if(*current->f_data == ref)
                        {
                            isFound = true;
                        }
                        if(*current->f_data > ref)
                        {
                            current = current->left;
                        }
                        else
                        {
                            current = current->right;
                        }
                    }
                    return isFound;
                }
                //movieTransactions(), returns boolean
                //takes a Movie pointer
                //how it works is simple
                //because when we create a movie
                //from the transaction data provided
                //its not complete (as in, missing director, or...
                //only having a title and director, etc...)
                //so, I created private methods that modify the tree
                //according to what was passed in
                bool movieTransaction(Movie *film)//USE ONLY FOR TRANSACTIONS!
                {
                    if(empty())
                    {
                        return false;
                    }
                    switch(film->getType())
                    {
                    case 'C':
                        {
                            return transactionCHelper(film);
                        }
                    case 'D':
                        {
                            return transactionDHelper(film);
                        }
                    case 'F':
                        {
                            return transactionFHleper(film);
                        }
                    default:
                        {
                            return false;
                        }
                    }
                }
            private:
                //recursive deleteAll, returns void
                //takes a node pointer
                void deleteAll(node *current)
                {
                    if(current == NULL)
                    {
                        return;
                    }
                    if(current != NULL)
                    {
                        deleteAll(current->left);
                        deleteAll(current->right);
                        delete current;
                    }
                }
                //displayHelper, takes a node pointer, returns void
                void displayHelper(node *current) const
                {
                    if(current != NULL)
                    {
                        displayHelper(current->left);
                        cout<<"Stock: "<<current->f_data->getStock()<<" - ";
                        current->f_data->displayFilmInfo();
                        displayHelper(current->right);
                    }
                }
                //transactionCHelper, takes a movie pointer
                //returns a boolean (true, success, false, no success)
                //this method goes thru the tree using
                //classic film criteria to determine equality
                //based on the film passed on (whatever data is in there)
                //and updates stock of a film
                bool transactionCHelper(Movie *film)
                {
                    node *current = root;
                    bool success = false;
                    while(current != NULL)
                    {
                        if(equalClassics(current, film))
                        {
                            int filmCount = current->f_data->getStock();
                            //cannot withdraw if zero copies exist
                            if(filmCount < 1)
                            {
                                cout<<"No available copies of: ";
                                current->f_data->displayFilmInfo();
                            }
                            else
                            {
                                current->f_data->
                                setStock(filmCount + film->getStock());
                                success = true;
                            }
                            break;
                        }
                        if(*current->f_data > *film)
                        {
                            current = current->left;
                        }
                        else
                        {
                            current = current->right;
                        }
                    }
                    return success;
                }
                //transactionDHelper, takes a movie pointer
                //returns a boolean (true, success, false, no success)
                //this method goes thru the tree using
                //drama film criteria to determine equality
                //based on the film passed on (whatever data is in there)
                //and updates stock of a film
                bool transactionDHelper(Movie *film)
                {
                    node *current = root;
                    bool success = false;
                    while(current != NULL)
                    {
                        if(equalDramas(current, film))
                        {
                            int filmCount = current->f_data->getStock();
                            //cannot withdraw if zero copies exist
                            if(filmCount < 1)
                            {
                                cout<<"No available copies of: ";
                                current->f_data->displayFilmInfo();
                            }
                            else
                            {
                                current->f_data->
                                setStock(filmCount + film->getStock());
                                success = true;
                            }
                            break;
                        }
                        if(*current->f_data > *film)
                        {
                            current = current->left;
                        }
                        else
                        {
                            current = current->right;
                        }
                    }
                    return success;
                }
                //transactionFHelper, takes a movie pointer
                //returns a boolean (true, success, false, no success)
                //this method goes thru the tree using
                //funny film criteria to determine equality
                //based on the film passed on (whatever data is in there)
                //and updates stock of a film
                bool transactionFHleper(Movie *film)
                {
                    node *current = root;
                    bool success = false;
                    while(current != NULL)
                    {
                        if(equalFunnies(current, film))
                        {
                            int filmCount = current->f_data->getStock();
                            //cannot withdraw if zero copies exist
                            if(filmCount < 1)
                            {
                                cout<<"No available copies of: ";
                                current->f_data->displayFilmInfo();
                            }
                            else
                            {
                                current->f_data->
                                setStock(filmCount + film->getStock());
                                success = true;
                            }
                            break;
                        }
                        if(*current->f_data > *film)
                        {
                            current = current->left;
                        }
                        else
                        {
                            current = current->right;
                        }
                    }
                    return success;
                }
                //equalClassics, returns boolean
                //takes a node ptr and a film ptr
                //basically, a classic film in a transaction has
                //only a month(date), a year, and actor
                bool equalClassics(node *c, Movie *film)
                {
                    return((c->f_data->getDate() == film->getDate() &&
                           c->f_data->getYear() == film->getYear())
                           ||
                           (c->f_data->getDate() == film->getDate() &&
                            c->f_data->getYear() == film->getYear() &&
                            c->f_data->getActor() == film->getActor()));
                }
                //equalDramas, returns boolean
                //takes a node ptr and a film ptr
                //a drama film in a transaction has
                //only a director and a title
                bool equalDramas(node *c, Movie *film)
                {
                    return(c->f_data->getDirector() == film->getDirector() &&
                         c->f_data->getTitle() == film->getTitle());
                }
                //equalFunnies, returns bolean
                //takes a node ptr and a film ptr
                //a funny movie in a transaction has only
                //a title and year
                bool equalFunnies(node *c, Movie *film)
                {
                    return(c->f_data->getTitle() == film->getTitle() &&
                           c->f_data->getYear() == film->getYear());
                }
        };
        //3 bst's, to store films by respecitive genres
        FilmBST classicFilmBST;
        FilmBST dramaFilmBST;
        FilmBST funnyFilmBST;
};

#endif // FILMINVENTORY_H
