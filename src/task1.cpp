#include "task1.h"
#include "Circle.h"


double calcDelta() {
	double radiusEarth = 6378100.0;
	Circle *Earth = new Circle(radiusEarth);
	Earth->setFerence(Earth->getFerence() + 1.0);
	double result = Earth->getRadius() - radiusEarth;
	delete Earth;
	return result;
}

double calcCost() {
	double costPokr = 1000.0;
	double costOgr = 2000.0;
	double radBig = 4.0;
	double radSmall = 3.0;
	Circle *bigCircle = new Circle(radBig);
	Circle *smallCircle = new Circle(radSmall);
	double result = (bigCircle->getArea() - smallCircle->getArea())*costPokr + bigCircle->getFerence()*costOgr;
	delete bigCircle;
	delete smallCircle;
	return result;
}