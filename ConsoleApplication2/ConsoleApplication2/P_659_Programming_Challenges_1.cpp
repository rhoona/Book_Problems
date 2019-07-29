// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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