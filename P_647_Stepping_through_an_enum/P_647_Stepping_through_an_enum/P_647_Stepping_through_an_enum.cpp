// P_647_Stepping_through_an_enum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

enum Day {MONDAY, TUESDAY, WEDNESDAY,THURSDAY,FRIDAY};
using namespace std;
int main()
{
	const int NUM_DAYS = 5;
	double sales[NUM_DAYS];
	double total = 0.0;
	Day workDay;

	for (workDay = MONDAY;workDay <= FRIDAY; workDay = static_cast<Day>(workDay + 1))
	{
		cout << "Enter the sales for day "
			<< workDay << ": ";
		cin >> sales[workDay];
}
	for (workDay = MONDAY; workDay <= FRIDAY; workDay = static_cast<Day>(workDay + 1))
		total += sales[workDay];

	cout << "The total sales are $" << setprecision(2) << fixed << total << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
