#include <iostream>
using namespace std;

struct Rectangle
{
	int width;
	int length;
	int area;
	int perimeter;
};

Rectangle getInfo();
int main() {
	Rectangle Shape1;

	Shape1 = getInfo();

	cout << "The width is: " << Shape1.width << endl;
	cout << "The length is: " << Shape1.length << endl;
	cout << "The area is: " << Shape1.area << endl;
	cout << "The perimeter is: " << Shape1.perimeter << endl;


}

Rectangle getInfo() {

	//temp item to get info and return to shape1 in main.
	Rectangle tempRec;

	cout << "Enter the Length: ";
	cin >> tempRec.length;
	cout << "Enter the Width: ";
	cin >> tempRec.width;

	tempRec.area = (tempRec.length * tempRec.width);
	tempRec.perimeter = 2 * (tempRec.length + tempRec.width);

	//filled a temp circle in this function now returning it to main.
	return tempRec;


}