#include "BusinessLogic.h"
/*Karim Oumghar - Css 343 - Assignment 4 */
BusinessLogic::BusinessLogic()
{

}
BusinessLogic::~BusinessLogic()
{
    //dtor
}
//LoadCommands
//think of this method as what determines what
//transaction needs to be done
//returns void
//takes a film inventory, customer database, and ifstream refernces
//splits a line, determines the transaction, determines genre
//and supporting movie info
//yes, its kinda long but whatevs...it works!!!
void BusinessLogic::LoadCommands(FilmInventory &f_ref,
                                 const CustomerDatabase &c_ref,
                                 ifstream &stream)
{
    char transaction;
    char genre, format;
    int id, date, year;
    string line, actor, director, title;
    while(!stream.eof())
    {
        transaction = '\0';
        stream >> transaction;
        if(transaction == '\0')//no blank lines
        {
            getline(stream,line);
            break;
        }
        switch(transaction)
        {
        case 'I':
            {
                PrintInventory(f_ref);
                break;
            }
        case 'H':
            {
                stream >> id;
                c_ref.lookupClient(id)->getHistory();
                break;
            }
        case 'B':
            {
                //get
                stream >> id >> format >> genre;
                switch(genre)
                {
                case 'C':
                    {
                        stream >> date >> year;
                        stream.get();
                        getline(stream, actor);
                        ClassicMovie *cm = new ClassicMovie();
                        cm->setActor(actor);
                        cm->setDate(date);
                        cm->setYear(year);
                        if(Borrow(f_ref, cm))
                        {
                            string task = "Borrowed C " + itos(date) +
                            " " + itos(year) + " " + actor;
                            if(c_ref.lookupClient(id) != NULL)
                            {
                                c_ref.lookupClient(id)->updateHistory(task);
                            }
                        }

                        break;
                    }
                case 'D':
                    {
                        stream.get();
                        getline(stream, director, ',');
                        stream.get();
                        getline(stream, title, ',');
                        stream.get();
                        DramaMovie *dm = new DramaMovie();
                        dm->setDirector(director);
                        dm->setTitle(title);
                        if(Borrow(f_ref, dm))
                        {
                            string task = "Borrowed D " + director +
                            " " + title;
                            if(c_ref.lookupClient(id) != NULL)
                            {
                                c_ref.lookupClient(id)->updateHistory(task);
                            }
                        }
                        break;
                    }
                case 'F':
                    {
                        stream.get();
                        getline(stream, title,',');
                        stream.get();
                        stream >> year;
                        FunnyMovie *fm = new FunnyMovie();
                        fm->setTitle(title);
                        fm->setYear(year);
                        if(Borrow(f_ref, fm))
                        {
                            string task = "Borrowed F " + title +
                            " " + itos(year);
                            if(c_ref.lookupClient(id) != NULL)
                            {
                                c_ref.lookupClient(id)->updateHistory(task);
                            }
                        }
                        break;
                    }
                default:
                    {
                        break;
                    }
                }
                break;
            }
        case 'R':
            {
                //get...
                stream >> id >> format >> genre;
                switch(genre)
                {
                case 'C':
                    {
                        stream >> date >> year;
                        stream.get();
                        getline(stream, actor);
                        ClassicMovie *cm = new ClassicMovie();
                        cm->setActor(actor);
                        cm->setDate(date);
                        cm->setYear(year);
                        if(Return(f_ref, cm))
                        {
                            string task = "Returned C " + itos(date) +
                            " " + itos(year) + " " + actor;
                            if(c_ref.lookupClient(id) != NULL)
                            {
                                c_ref.lookupClient(id)->updateHistory(task);
                            }
                        }
                        break;
                    }
                case 'D':
                    {
                        stream.get();
                        getline(stream, director, ',');
                        stream.get();
                        getline(stream, title, ',');
                        stream.get();
                        DramaMovie *dm = new DramaMovie();
                        dm->setDirector(director);
                        dm->setTitle(title);
                        if(Return(f_ref, dm))
                        {
                            string task = "Returned D " + director +
                            " " + title;
                            if(c_ref.lookupClient(id) != NULL)
                            {
                                c_ref.lookupClient(id)->updateHistory(task);
                            }
                        }
                        break;
                    }
                case 'F':
                    {
                        stream.get();
                        getline(stream, title,',');
                        stream.get();
                        stream >> year;
                        FunnyMovie *fm = new FunnyMovie();
                        fm->setTitle(title);
                        fm->setYear(year);
                        if(Return(f_ref, fm))
                        {
                            string task = "Returned F " + title +
                            " " + itos(year);
                            if(c_ref.lookupClient(id) != NULL)
                            {
                                c_ref.lookupClient(id)->updateHistory(task);
                            }
                        }
                        break;
                    }
                default:
                    {
                        break;
                    }
                }
                break;
            }
        default:
            {
                cout<<"Invalid transaction..."<<endl;
                getline(stream, line);
                break;
            }
        }
    }
}
//Borrow, returns boolean, takes a film inventory reference
//and Movie ptr
//self explanatory...
bool BusinessLogic::Borrow(FilmInventory &f_ref, Movie *film)
{
    film->setStock(-1);
    return f_ref.transactionFilm(film);
}
//Return, returns boolean, takes a film inventory reference
//and Movie ptr
//self explanatory...
bool BusinessLogic::Return(FilmInventory &f_ref, Movie *film)
{
    film->setStock(1);
    return f_ref.transactionFilm(film);
}
//History, returns void, takes a id number and customer database reference
void BusinessLogic::History(const CustomerDatabase &c_ref, int id) const
{
    if(c_ref.lookupClient(id) == NULL)
    {
        cout<<"Client #"<<id<<" does not exist in the system"<<endl;
    }
    else
    {
        c_ref.lookupClient(id)->getHistory();
    }
    return;
}
//Print inventory, takes a film inventory reference, returns void
void BusinessLogic::PrintInventory(const FilmInventory &f_ref) const
{
    f_ref.displayFilms();
    return;
}
//small helper method when storing history
//itos() converts a number to a string to append to
//a history string
//returns a string
string BusinessLogic::itos(int value)
{

    string result;          // string which will contain the result

    ostringstream convert;   // stream used for the conversion

    convert << value;      // insert the textual representation of 'Number' in the characters in the stream

    result = convert.str(); // set 'Result' to the contents of the stream
    return result;
}
