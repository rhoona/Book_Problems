
//PAGE 641, CHECKPOINT, QUESTION 11.11
//Write a function that accepts a Rectangle structure as its argument and displays the structure's contents on screen.
#include <iostream>
using namespace std;

//Rectangle struct
struct rectangle
{
	int width;
	int length;
	int area;
	int perimeter;
};

void getInfo(rectangle *);
void postInfo(rectangle *);

int main()
{
	rectangle userRectangle;

	getInfo(&userRectangle);
	postInfo(&userRectangle);

}

//UR for user rectangle.
void getInfo(rectangle *UR) {

	cout << "Enter the width of the rectangle: ";
	cin >> UR->width;
	cout << "\nEnter the Length of the rectangle: ";
	cin >> UR->length;

	UR->area = (UR->length * UR->width);
	UR->perimeter = 2*(UR->length + UR->width);
}

//URI = user rectangle information
void postInfo(rectangle* URI) {
	cout << "\nYour length is: " << URI->length << endl;
	cout << "Your width is: " << URI->width << endl;
	cout << "Your area is: " << URI->area << endl;
	cout << "Your perimeter is: " << URI->perimeter << endl;

}
