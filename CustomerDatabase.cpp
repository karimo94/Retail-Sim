#include "CustomerDatabase.h"
/*Karim Oumghar - Css 343 - Assignment 4 */
CustomerDatabase::CustomerDatabase()
{
    //ctor
}

CustomerDatabase::~CustomerDatabase()
{
    //dtor
}
//lookupClient, takes a int key, returns a ptr to the client
Client * CustomerDatabase::lookupClient(int key) const
{
    return clients.getData(key);
}
//displays a clients information, returns void, takes
//a key integer
void CustomerDatabase::displayClient(int key) const
{
    Client *temp = clients.getData(key);
    if(temp != NULL)
    {
        cout<<temp->getID()<<" "<<temp->getLastName()<<" "
        <<temp->getFirstName()<<endl;
    }
    else
    {
        cout<<"Client #"<<key<<" does not exist in the system"<<endl;
    }
    return;
}
//buildClientDatabase
//takes an ifstream reference, and goes thru each line
//taking client data and creating a new client
//and inserting into the hash table
//returns void
void CustomerDatabase::buildClientDatabase(ifstream &stream)
{
    string fName = "";
    string lName = "";
    string line;
    while(!stream.eof())
    {
        int id = 0;
        stream >> id >> lName >> fName;
        if(id == 0)//no bad data, like empty lines/spaces
        {
            getline(stream, line);//go to next line
        }
        else
        {
            clients.insert(id, new Client(fName, lName, id));
        }
    }
}
