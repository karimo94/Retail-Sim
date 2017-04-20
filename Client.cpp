#include "Client.h"
/*Karim Oumghar - Css 343 - Assignment 4 */
Client::Client()
{
    //ctor
}
Client::Client(string fname, string lname, int ID)
{
    firstName = fname;
    lastName = lname;
    id = ID;
}
Client::~Client()
{
    //dtor
}
//all getters and setter implemented
int Client::getID() const
{
    return id;
}
string Client::getFirstName() const
{
    return firstName;
}
string Client::getLastName() const
{
    return lastName;
}
//prints the history, first check if
//theres no history
void Client::getHistory() const
{
    if(llH.empty())
    {
        cout<<"No history for client: "<<
        lastName<<" "<< firstName<<""<<endl;
    }
    else
    {
        cout<<"*******************************************"<<endl;
        cout<<"History for client: "<<
        lastName<<" "<< firstName<<endl;
        llH.displayHistory();
    }
    return;
}
void Client::setID(int ID)
{
    id = ID;
}
void Client::setFirstName(string fname)
{
    firstName = fname;
}
void Client::setLastName(string lname)
{
    lastName = lname;
}
//inserts into the linked list
void Client::updateHistory(string command)
{
    llH.insert(command);
}
