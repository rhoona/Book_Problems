//Write a program that uses a structure named MovieData to store information about a movie 
//The program should create two MovieData variables, store values in their members
// and pass each one, in turn to a function that displays the information

#include <iostream>
#include <string>
using namespace std;

struct MovieData
{
	string Title;
	string Director;
	int Year;
	int RunTime;
};
void showMovieData(MovieData*);

int main() {
	MovieData first = { "How to Train your Dragon","Some director",2018,60 };
	MovieData  second = { "Spider man into the spider verse","A good director",2019,120 };
	showMovieData(&first);
	showMovieData(&second);

}

void showMovieData(MovieData* m) {
	cout << m->Title << "    " << m->Director << "    " << m->Year <<"    "<< m->RunTime << '\n';
}