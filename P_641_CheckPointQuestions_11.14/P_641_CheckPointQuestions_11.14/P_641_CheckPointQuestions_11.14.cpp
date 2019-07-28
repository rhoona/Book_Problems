// P_641_CheckPointQuestions_11.14
//Write the definition of a pointer to a Rectangle structure;
#include <iostream>
using namespace std;

struct Rectangle
{
	int width;
	int length;
	int area;
	int perimeter;
};

int main() {
	//Rectangle structure created
	Rectangle Shape1;
	//Pointer to a rectangle stucture created, initialized to point to another Rectangle structure
	Rectangle* ShapePtr = &Shape1;

	//using the pointer to give values to the original structure variables
	ShapePtr->length = 5;
	ShapePtr->width = 5;

	//now printing the original structure varibles that were filled by the pointer
	cout << "Shape1 length is: " << Shape1.length << endl;
	cout << "Shape2 Width is: " << Shape1.width << endl;
}
