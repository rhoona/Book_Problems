//Write a program that uses a structure to store the following data on a company division
//the program should use four variables of this structure. each variable should represent one of the following
//corporate divisons: EAST,WEST, NORTH and SOUTH. The user should be asked for the four quarter's sales
//figures for each division. Each division's total and average sales should be calculated and stored
// in the appropriate member of each structure variable. These figured should then be displayed on the screen.
//**Input validation: DO NOT ACCEPT NEATIVE NUMBERS FOR ANY SALES FIGURES

#include <iostream>
#include <iomanip>
using namespace std;

struct CompanyDivision
{
	enum DivisionName { East, West, North, South };
	double FirstQuarterSales;
	double SecondQuarterSales;
	double ThirdQuarterSales;
	double FourthQuarterSales;
	double TotalAnnualSales;
	double AverageQuarterlySales;
};

int main()
{
	CompanyDivision CD;
}

