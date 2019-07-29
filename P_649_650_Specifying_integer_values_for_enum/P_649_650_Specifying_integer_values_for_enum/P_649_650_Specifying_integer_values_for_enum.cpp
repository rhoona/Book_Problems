// P_649_650_Specifying_integer_values_for_enum.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	enum Water { FREEZING = 32, BOILING = 212 };
	int waterTemp;

	cout << "Enter the current water temperature: ";
	cin >> waterTemp;

	if (waterTemp <= FREEZING)
		cout << "The water is frozen.\n";
	else if (waterTemp >= BOILING)
		cout << "The water is boiling.\n";
	else
		cout << "The water is not frozen or boiling.\n";
}

