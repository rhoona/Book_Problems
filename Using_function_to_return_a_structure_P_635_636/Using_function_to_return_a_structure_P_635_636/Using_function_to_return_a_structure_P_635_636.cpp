
#include <iomanip>
#include <cmath>  //for pow function.
#include <iostream>
using namespace std;

const double PI = 3.14159;

struct Circle
{
	double radius;
	double diamter;
	double area;
};

Circle getInfo();

int main() {

	Circle c;
	c = getInfo();
	c.area = PI * pow(c.radius, 2.0);

	cout << "The radius and area of the cirlce are:\n";
	cout << fixed << setprecision(2);
	cout << "Radius: " << c.radius << endl;
	cout << "Area: " << c.area << endl;

	return 0;



}
Circle getInfo() {
	Circle tempCircle;
	cout << "Enter the diamter of a circle: ";
	cin >> tempCircle.diamter;
	tempCircle.radius = tempCircle.diamter / 2.0;
	
	return tempCircle;

}