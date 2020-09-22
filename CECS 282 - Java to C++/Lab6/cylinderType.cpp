//Chaz Del Prato
//CECS 282 Lab 6
#include "cylinderType.h"

void cylinderType::print() const{
	
	circleType::print();
	
	cout << "Cylinder Height: " << height << endl;
	cout << "Cylinder Surface Area: " << getSurfaceArea() << endl;
	cout << "Cylinder Volume: " << getVolume() << endl;
}
	
void cylinderType::setHeight(double h){
	height = h;
}
void cylinderType::setBaseCenter(double x, double y){
	pointType(x,y);
}
void cylinderType::setCenterRadiusHeight(double x, double y, double r, double h){
	setPoint(x,y);
	setRadius(r);
	height = h;
}

double cylinderType::getHeight() const{
	return height;
}
double cylinderType::getVolume() const{
	return 3.1416 * radius * radius * height;
}
double cylinderType::getSurfaceArea() const{
	return (2 * 3.1416 * radius * height) + (2 * 3.1416 * radius * radius);
}

cylinderType::cylinderType(double x, double y, double r, double h): circleType(x,y,r){
	height = h;
}
