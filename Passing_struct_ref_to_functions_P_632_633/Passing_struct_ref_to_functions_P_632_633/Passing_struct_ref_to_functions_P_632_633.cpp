#include <iomanip>
#include <string>
#include <iostream>

using namespace std;

struct student {
	string name;
	int idNum;
	int creditHours;
	double gpa;
};

void getData(student*);
int main()
{

	student freshman;

	cout << "Enter the following student data:\n";
	getData(&freshman);
	cout << "\n Here is the student data you entered:\n";

	cout << setprecision(3);
	cout << "Name:" << freshman.name << endl;
	cout << "ID Number: " << freshman.idNum << endl;
	cout << "Credit Hours: " << freshman.creditHours << endl;
	cout << "GPA: " << freshman.gpa << endl;

}

void getData(student* s) {
	cout << "Student name: ";
	getline(cin, s->name);

	cout << "Student ID Number: ";
	cin >> s->idNum;

	cout << "Credit hours enrolled: ";
	cin >> s->creditHours;

	cout << "Current GPA:";
	cin >> s->gpa;
}