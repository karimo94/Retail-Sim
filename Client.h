#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include <iostream>

using namespace std;
/*Karim Oumghar - Css 343 - Assignment 4 */

//Client class
//Description: a representation of a single customer, the client
//shall have getters and setters of first and last names, and id
//also updating a clients transaction history
//I decided to use a linked list to store history
//simple data structure, and its a nested class within
//Client.h, for encapsulation purposes (no entity needs to know
//that its a linked list, only that we Client has public modifiers)

class Client
{
    public:
        //2 constructors, default and overloaded
        Client();
        Client(string fname, string lname, int id);
        ~Client();

        int getID() const;
        string getLastName() const;
        string getFirstName() const;
        void getHistory() const;

        void setLastName(string lname);
        void setFirstName(string fname);
        void setID(int ID);
        void updateHistory(string command);
    protected:
    private:
        string firstName, lastName;
        int id;
        //**********Linked List implementation begins************
        //I will use this linked list to store client history
        //its a simple linked list
        //a node struct containing string data
        //and a next node pointer
        struct node
        {
            string data;
            node *next;
        };
        //HistoryLinkedList class
        //Description: implements a singly linked list
        class HistoryLinkedList
        {
            node* head;
        public:
            //ctor
            HistoryLinkedList()
            {
                head = NULL;
            }
            //dtor
            ~HistoryLinkedList()
            {
                deleteAllHelper(head);
            }
            //insert, returns void, takes string parameter
            void insert(string data)
            {
                node *nObj = new node();
                nObj->data = data;
                nObj->next = NULL;
                if(empty())
                {
                    head = nObj;
                    head->next = NULL;
                    return;
                }
                else
                {
                    nObj->next = head;
                    head = nObj;
                    return;
                }
            }
            //empty(), returns true/false
            bool empty() const
            {
                return(head == NULL);
            }
            //displayHistory, returns void,
            //takes no parameters, displays
            //history
            void displayHistory() const
            {
                node *current = head;
                while(current != NULL)
                {
                    cout<<current->data<<endl;
                    current = current->next;
                }
                return;
            }
        private:
            //a private deleteAllHelper
            //uses recursion, this method is called
            //in the dtor
            void deleteAllHelper(node *current)
            {
                if(current == NULL)
                {
                    return;
                }
                if(current != NULL)
                {
                    deleteAllHelper(current->next);
                    delete current;
                }
            }
        };
        //a history linked list
        HistoryLinkedList llH;
};

#endif // CLIENT_H
