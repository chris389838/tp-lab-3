#pragma once

class Circle {
private:
	double radius; //радиус
	double ference; //длина окружности
	double area;//площадь круга
public:
	Circle(double radius);
	void setRadius(double);
	void setFerence(double);
	void setArea(double);
	double getRadius();
	double getFerence();
	double getArea();
};
const double pi = 3.1415;