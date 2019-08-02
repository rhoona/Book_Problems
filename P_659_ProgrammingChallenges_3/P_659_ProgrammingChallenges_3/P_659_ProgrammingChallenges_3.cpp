// P_659_ProgrammingChallenges_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

struct CompanyDivisions
{
	string DivisionName;
	double FirstQuarterSales = 0;
	double SecondQuarterSales = 0;
	double ThirdQuarterSales = 0;
	double FourthQuarterSales = 0;
	double TotalAnnualSales = 0;
	double AverageQuarterlySales = 0;
};

void FillInfo(const string[],CompanyDivisions[],const int);

int main()
{
	const int SIZE = 4; //Array size
	const string Names[SIZE] = { "East","West","North","South" }; //Names of each division to collect
	CompanyDivisions Divisions[SIZE];

	FillInfo(Names, Divisions, SIZE);
}

void FillInfo(const string Names[], CompanyDivisions Divisions[], const int SIZE) {

	for (int count = 0; count < SIZE;count++)
	{
		//Last second added, realized as no way to identify the data.
		Divisions[count].DivisionName = Names[count];
		//Will increment after each Quarter input and will be used to divide the total for the avg
		int AvgTracker = 0;
		//Limit the Results precision to just two points after the decimal
		cout << fixed << showpoint << setprecision(2);

		//The next 4 code blocks take in each Quarters revenue, then adds it to that divisions total annual sales, then 
		//it increments the Avgtracker to be used to find the Avg.
		cout << "Enter the First Quater Sales for Divison " << Names[count] << endl;
		cin >> Divisions[count].FirstQuarterSales;
		Divisions[count].TotalAnnualSales += Divisions[count].FirstQuarterSales;
		AvgTracker += 1;

		cout << "Enter the Second Quarter Sales for Divison " << Names[count] << endl;
		cin >> Divisions[count].SecondQuarterSales;
		Divisions[count].TotalAnnualSales += Divisions[count].SecondQuarterSales;
		AvgTracker += 1 ;

		cout << "Enter the Third Quarter Sales for Divison " << Names[count] << endl;
		cin >> Divisions[count].ThirdQuarterSales;
		Divisions[count].TotalAnnualSales += Divisions[count].ThirdQuarterSales;
		AvgTracker += 1;

		cout << "Enter the Fourth Quarter Sales for Divison " << Names[count] << endl;
		cin >> Divisions[count].FourthQuarterSales;
		Divisions[count].TotalAnnualSales += Divisions[count].FourthQuarterSales;
		AvgTracker += 1;

		//Get The Divisions Average sales by Dividing the accumulating Total by the AvgTracker, which incremented after each 
		//quarterly input.
		Divisions[count].AverageQuarterlySales = Divisions[count].TotalAnnualSales / AvgTracker;

		cout << "Division " << Names[count] << " Total Annual Sales are: $" << Divisions[count].TotalAnnualSales << endl;
		cout << "Divisions " << Names[count] << "Average sales were $" << Divisions[count].AverageQuarterlySales << endl;
	
		cout << "***************Next Division****************\n";
}
}

