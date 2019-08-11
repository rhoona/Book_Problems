// P_660_ProgrammingChallenges_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;
bool GetName(char[],  int);
int main() {
	const int SIZE = 10;
	char Name[SIZE];

	GetName(Name, SIZE);



}

bool GetName(char arr[], int SIZE) {
	//int sLength = strlen(arr);
	cout << "Enter your name: ";
	cin.getline(arr, SIZE);

	for (int counter = 0; counter < SIZE;counter++)
	{
		if (isspace(arr[counter]))
		{
			cout << "wtf man";
		}
	}
	return true;
}





