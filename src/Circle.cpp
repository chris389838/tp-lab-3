#include "Circle.h"
#include <cmath>


Circle::Circle(double radius) {
	this->radius = radius;
	this->ference = 2.0 * pi * radius;
	this->area = pi * radius * radius;
}


void Circle::setRadius(double radius) {
	this->radius = radius;
	this->ference = 2.0 * pi * radius;
	this->area = pi * radius * radius;
}

void Circle::setFerence(double ference) {
	this->ference = ference;
	this->radius = ference / (2.0 * pi);
	this->area = ference * radius * radius;
}

void Circle::setArea(double area) {
	this->area = area;
	this->radius = sqrt(area / pi);
	this->ference = area * 2.0 * radius;
}

double Circle::getRadius() {
	return radius;
}

double Circle::getFerence() {
	return ference;
}

double Circle::getArea() {
	return area;
}

