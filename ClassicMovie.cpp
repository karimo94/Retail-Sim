#include "ClassicMovie.h"
ClassicMovie::ClassicMovie()
{
    //ctor
    this->type = 'C';
}
ClassicMovie::ClassicMovie(string director, string title, string actor,
                           int date, int year)
{
    this->director = director;
    this->title = title;
    this->actor = actor;
    this->date = date;
    this->year = year;
    this->type = 'C';
    this->stock = 0;
}
ClassicMovie::~ClassicMovie()
{
    //dtor
}
//all getters and setters below, operator overloads too
char ClassicMovie::getType() const
{
    return type;
}
string ClassicMovie::getActor() const
{
    return actor;
}
void ClassicMovie::setActor(string actor)
{
    this->actor = actor;
}
string ClassicMovie::getDirector() const
{
    return director;
}
void ClassicMovie::setDirector(string director)
{
    this->director = director;
}
string ClassicMovie::getTitle() const
{
    return title;
}
void ClassicMovie::setTitle(string title)
{
    this->title = title;
}
int ClassicMovie::getYear() const
{
    return year;
}
void ClassicMovie::setYear(int year)
{
    this->year = year;
}
int ClassicMovie::getDate() const
{
    return date;
}
void ClassicMovie::setDate(int date)
{
    this->date = date;
}
int ClassicMovie::getStock() const
{
    return stock;
}
void ClassicMovie::setStock(int stock)
{
    this->stock = stock;
}
void ClassicMovie::displayFilmInfo() const
{
    cout<<type<<" "<<
    director<<" "<<title<<" "<< actor<<
    " "<<date<< " " <<year<<endl;
    return;
}
bool ClassicMovie::operator==(const Movie &ref) const
{
    return(this->type == ref.getType() && date == ref.getDate() &&
           year == ref.getYear() && director == ref.getDirector() &&
           title == ref.getTitle());
}
bool ClassicMovie::operator!=(const Movie &ref) const
{
    return(this->type != ref.getType() ||
           year != ref.getYear() || title != ref.getTitle());
}
bool ClassicMovie::operator<(const Movie &ref) const
{
    bool lessThan = false;
    if(year < ref.getYear())
    {
        if(date < ref.getDate())
        {
            if(actor < ref.getActor())
            {
                lessThan = true;
            }
        }
        lessThan = true;
    }
    if(year == ref.getYear())
    {
        if(date < ref.getDate())
        {
            if(actor < ref.getActor())
            {
                lessThan = true;
            }
        }
        if(date == ref.getDate())
        {
            lessThan = true;
        }
    }
    if(year == ref.getYear())
    {
        if(date == ref.getDate())
        {
            if(actor < ref.getActor())
            {
                lessThan = true;
            }
            lessThan = true;
        }
        lessThan = true;
    }
    return lessThan;
}
bool ClassicMovie::operator>(const Movie &ref) const
{
    bool greaterThan = false;
    if(year > ref.getYear())
    {
        if(date > ref.getDate())
        {
            if(actor > ref.getActor())
            {
                greaterThan = true;
            }
        }
        greaterThan = true;
    }
    if(year == ref.getYear())
    {
        if(date > ref.getDate())
        {
            if(actor > ref.getActor())
            {
                greaterThan = true;
            }
            greaterThan = true;
        }
        if(date == ref.getDate())
        {
            if(actor > ref.getActor())
            {
                greaterThan = true;
            }
        }
        greaterThan = true;
    }
    return greaterThan;
}
