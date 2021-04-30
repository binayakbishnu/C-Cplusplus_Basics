//The area is the two-dimensional amount of space that an object occupies. Area is measured along the surface of an object and
// has dimensions of length squared; for example, square feet of material, or centimetres squared.
//The area of a rectangle is equal to the height h times the base b; A = h * b
//The equation for the area of a trapezoid is one half the sum of the top t and bottom b times the height h;
// A = h * [ t + b ] / 2
//The area of a circle is A = pi * r2, where pi = 3.14 and r = radius.
//Develop a program in C++ using function overloading for computing the area of a rectangle, a trapezoid and a circle
// by a common function name ComputeArea() with different signature. Assume pi = 3.14. 
// Print only two decimal places for all areas.

//Input Format:
//Read the base and height of a rectangle.
//Read the top, bottom and height of a trapezoid.
//Read the radius of a circle.

//Output Format:
//Display the area of a rectangle, trapezoid and circle each in one line
//Boundary Conditions:
//You can give any valid integer or float values for inputs.

#include <iostream>
#include <iomanip>

using namespace std;

void ComputeArea(float h,float b)
{
	cout<<"Area: "<<fixed<<setprecision(2)<<h*b;
}
void ComputeArea(float h,float b,float t)
{
	cout<<"Area: "<<fixed<<setprecision(2)<<h*(t+b)*0.5;
}
void ComputeArea(float r)
{
	cout<<"Area: "<<fixed<<setprecision(2)<<3.14*r;
}

int main()
{
	int choice=0;
	cout<<"1. Rectangle\n2. Trapezium\n3. Circle\n";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			int length, breath;
			cout<<"Enter values: ";
			cin>>length>>breath;
			ComputeArea(length,breath);
			break;
		case 2:
			int top,bottom,height;
			cout<<"Enter values: ";
			cin>>top>>bottom>>height;
			ComputeArea(height,bottom,top);
			break;
		case 3:
			int radius;
			cout<<"Enter value: ";
			cin>>radius;
			ComputeArea(radius);
	}
	
	return 0;
}
