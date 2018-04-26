#include "Point.h"

void Point::WriteToFile(ofstream & o)
{
}

float Point::Distance(const Point &) const
{
	return 0.0f;
}

float Point::Distance_R(const Rect &) const
{
	return 0.0f;
}

float Point::Distance_L(const Line &) const
{
	return 0.0f;
}


ostream& operator<<(ostream& os, const Point& outputPoint)
{}

bool operator<(const Point &, const Point &)
{
	return false;
}

Point operator+(const Point &, const Point &)
{
	return Point();
}
