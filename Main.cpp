#include "MovieStore.h"
using namespace std;
/*Karim Oumghar - Css 343 - Assignment 4 */
//wanted to keep my main as small as possible...
int main()
{
    MovieStore ms;
    ifstream if1("data4customers.txt");
    ms.ReadInClients(if1);

    ifstream if2("data4movies.txt");
    ms.ReadInMovies(if2);

    ifstream if3("data4commands.txt");
    ms.ReadInCommands(if3);
    return 0;
}
