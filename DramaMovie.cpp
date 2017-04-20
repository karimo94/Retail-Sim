#include "DramaMovie.h"

DramaMovie::DramaMovie()
{
    //ctor
    this->type = 'D';
}
DramaMovie::DramaMovie(string director, string title, int year)
{
    this->director = director;
    this->title = title;
    this->year = year;
    this->type = 'D';
    this->stock = 0;
    this->date = 0;
}
DramaMovie::~DramaMovie()
{
    //dtor
}
//all getters and setters below, operator overloads too
char DramaMovie::getType() const
{
    return type;
}
string DramaMovie::getDirector() const
{
    return director;
}
void DramaMovie::setDirector(string director)
{
    this->director = director;
}
string DramaMovie::getTitle() const
{
    return title;
}
void DramaMovie::setTitle(string title)
{
    this->title = title;
}
string DramaMovie::getActor() const
{
    return "";
}
void DramaMovie::setActor(string actor)
{
    actor = "";
}
int DramaMovie::getYear() const
{
    return year;
}
void DramaMovie::setYear(int year)
{
    this->year = year;
}
int DramaMovie::getDate() const
{
    return date;
}
void DramaMovie::setDate(int date)
{
    this->date = date;
}
int DramaMovie::getStock() const
{
    return stock;
}
void DramaMovie::setStock(int stock)
{
    this->stock = stock;
}
void DramaMovie::displayFilmInfo() const
{
    cout<<type<<" "<<director<<" "<<
    title<<" " <<year<<endl;
    return;
}
bool DramaMovie::operator==(const Movie &ref) const
{
    return(this->type == ref.getType() && director == ref.getDirector() &&
           title == ref.getTitle() && year == ref.getYear());
}
bool DramaMovie::operator!=(const Movie &ref) const
{
    return(this->type != ref.getType() || director != ref.getDirector() ||
           title != ref.getTitle());
}
bool DramaMovie::operator<(const Movie &ref) const
{
    bool lessThan = false;
    if(director < ref.getDirector())
    {
        if(title < ref.getTitle())
        {
            lessThan = true;
        }
        lessThan = true;
    }
    if(director == ref.getDirector())
    {
        if(title < ref.getTitle())
        {
            lessThan = true;
        }
        lessThan = true;
    }
    return lessThan;
}
bool DramaMovie::operator>(const Movie &ref) const
{
    bool greaterThan = false;
    if(director > ref.getDirector())
    {
        if(title > ref.getTitle())
        {
            greaterThan = true;
        }
        greaterThan = true;
    }
    if(director == ref.getDirector())
    {
        if(title > ref.getTitle())
        {
            greaterThan = true;
        }
        greaterThan = true;
    }
    return greaterThan;
}
