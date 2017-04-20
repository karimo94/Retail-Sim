#include "FunnyMovie.h"
FunnyMovie::FunnyMovie()
{
    //ctor
    this->type = 'F';
}
FunnyMovie::FunnyMovie(string director, string title, int year)
{
    this->director = director;
    this->title = title;
    this->year = year;
    this->type = 'F';
    this->stock = 0;
    this->date = 0;
}
FunnyMovie::~FunnyMovie()
{
    //dtor
}
//all getters and setters below, operator overloads too
char FunnyMovie::getType() const
{
    return type;
}
string FunnyMovie::getDirector() const
{
    return director;
}
void FunnyMovie::setDirector(string director)
{
    this->director = director;
}
string FunnyMovie::getTitle() const
{
    return title;
}
void FunnyMovie::setTitle(string title)
{
    this->title = title;
}
string FunnyMovie::getActor() const
{
    return "";
}
void FunnyMovie::setActor(string actor)
{
    actor="";
}
int FunnyMovie::getYear() const
{
    return year;
}
void FunnyMovie::setYear(int year)
{
    this->year = year;
}
int FunnyMovie::getDate() const
{
    return date;
}
void FunnyMovie::setDate(int date)
{
    this->date = date;
}
int FunnyMovie::getStock() const
{
    return stock;
}
void FunnyMovie::setStock(int stock)
{
    this->stock = stock;
}
void FunnyMovie::displayFilmInfo() const
{
    cout<<type<<" "<<director<<" "<<
    title<<" "<<year<<endl;
    return;
}
bool FunnyMovie::operator==(const Movie &ref) const
{
    return(this->type == ref.getType() &&
           year == ref.getYear() && title == ref.getTitle()
           && director == ref.getDirector());
}
bool FunnyMovie::operator!=(const Movie &ref) const
{
    return(this->type != ref.getType() ||
           year != ref.getYear() || title != ref.getTitle());
}
bool FunnyMovie::operator<(const Movie &ref) const
{
    bool lessThan = false;
    if(title < ref.getTitle())
    {
        if(year < ref.getYear())
        {
            lessThan = true;
        }
        lessThan = true;
    }
    if(title == ref.getTitle())
    {
        if(year < ref.getYear())
        {
            lessThan = true;
        }
        lessThan = true;
    }
    return lessThan;
}
bool FunnyMovie::operator>(const Movie &ref) const
{
    bool greaterThan = false;
    if(title > ref.getTitle())
    {
        if(year > ref.getYear())
        {
            greaterThan = true;
        }
        greaterThan = true;
    }
    if(title == ref.getTitle())
    {
        if(year > ref.getYear())
        {
            greaterThan = true;
        }
        greaterThan = true;
    }
    return greaterThan;
}
