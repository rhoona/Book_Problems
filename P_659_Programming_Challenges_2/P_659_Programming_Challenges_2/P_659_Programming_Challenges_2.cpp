//Modify the program written for programming challenge 1, to include two additional members that hold
//the movie's production cost and first-year revenues. Modify the function that displays the movie data to
// display the title, director, release year, running time and first year's profit or loss

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct MovieData
{
	string Title;
	string Director;
	int Year;
	int RunTime;
	double ProductionCost;
	double FirstYearRevenue;
};
void showMovieData(MovieData*);

int main() {
	MovieData first = { "How to Train your Dragon","Some director",2018,60, 60.000, 140.000 };
	MovieData  second = { "Spider man into the spider verse","A good director",2019,120, 200.000, 80.000 };
	showMovieData(&first);
	showMovieData(&second);

}


//Added a static int to make counting output nicer
void showMovieData(MovieData* m) {
	static int count = 1;
	cout << "****** #" << count << " ******\n";
	count++;
	cout << fixed << showpoint << setprecision(2);
	cout <<"Title: "<< m->Title <<'\n'<<"Director: "<< m->Director << '\n' <<"Year: "<< m->Year <<'\n' <<"Run Time: "<<m->RunTime <<" Minutes"<< '\n';

	if (m->ProductionCost > m->FirstYearRevenue)
		cout << "The film was not profitable, Total loss: " << (m->ProductionCost - m->FirstYearRevenue);
	if (m->FirstYearRevenue > m->ProductionCost)
		cout << "The film WAS profitable, total Gain: " << (m->FirstYearRevenue - m->ProductionCost);

	cout << "\n\n";
}