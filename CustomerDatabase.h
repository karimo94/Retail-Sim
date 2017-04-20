#ifndef CUSTOMERDATABASE_H
#define CUSTOMERDATABASE_H
#include "Client.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
/*Karim Oumghar - Css 343 - Assignment 4 */

//CustomerDatabase
//acts as the class that works with the main hashtable
//that stores clients
//has 3 public methods, one to lookup a client
//one to display a client
//one to build the client database(hashtable)
class CustomerDatabase
{
    public:
        CustomerDatabase();
        ~CustomerDatabase();

        Client* lookupClient(int key) const;
        void displayClient(int key) const;
        void buildClientDatabase(ifstream &stream);

    protected:
    private:
        /*--------Hash Table implementation begins here-------*/
        //a struct HashEntry
        //contains a key, and a Client pointer to data
        //the key I used was the clients ID number
        struct HashEntry
        {
            int key;
            Client *data;
        };
        //HashTable
        //made its size a reasonable 100
        //contains really only 2 methods of use
        //insert and getClient()
        class HashTable
        {
            static const int maxSize = 100;
            public:
                //initialize the hashtable
                HashTable()
                {
                    table = new HashEntry*[maxSize];
                    for(int i = 0; i < maxSize; i++)
                    {
                        table[i] = NULL;
                    }
                }
                //dtor, delete the hashtable
                ~HashTable()
                {
                    for(int i = 0; i < maxSize; i++)
                    {
                        if(table[i] != NULL)
                        {
                            delete table[i];
                        }
                    }
                    delete [] table;
                }
                //getData, returns a pointer to client
                //takes a integer key parameter
                //retrieves a client based on the key
                Client *getData(int key) const
                {
                    int hash = (key % maxSize);
                    while(table[hash] != NULL && table[hash]->key != key)
                    {
                        hash = (hash + 1) % maxSize;
                    }
                    if(table[hash] == NULL)
                    {
                        return NULL;
                    }
                    else
                    {
                        return table[hash]->data;
                    }
                }
                //inserts into the hashtable
                //using linear probing
                //takes a integer key and a client ptr
                //parameters, returns void
                void insert(int key, Client *data)
                {
                    int hash = (key % maxSize);
                    while(table[hash] != NULL && table[hash]->key != key)
                    {
                        hash = (hash + 1) % maxSize;
                    }
                    if(table[hash] != NULL)
                    {
                        delete table[hash];
                    }
                    table[hash] = new HashEntry();
                    table[hash]->data = data;
                    table[hash]->key = key;
                }
            private:
                HashEntry **table;

        };
        //a hashtabe called clients...
        HashTable clients;
};

#endif // CUSTOMERDATABASE_H
