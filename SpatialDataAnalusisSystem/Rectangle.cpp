#include "Rectangle.h"
#include <fstream>
#include <algorithm>

Rect::Rect(const Rect &rect)
{
	setID(rect.getID());
	setDes(rect.getDes());
	lp = rect.getLp();
	rp = rect.getRp();
	area = rect.getArea();
	Rect::count++;
}

float Rect::Area()
{
	area = (rp.getX()-lp.getX())*(rp.getY()-lp.getY());
	return area;
}

void Rect::WriteToFile(ofstream & o)
{
	o << *this;
}

int Rect::setLp(const Point &point)
{
	lp = point;
	return 1;
}

const Point & Rect::getLp() const
{
	return lp;
}

int Rect::setRp(const Point &point)
{
	rp = point;
	return 1;
}

const Point & Rect::getRp() const
{
	return rp;
}

float Rect::Distance(const Rect &rect)
{
	//
	return 0.0f;
}

ostream & operator<<(ostream & os, const Rect & rect)
{
	os << rect.getID() << " ";
	Point point = rect.getLp();
	os << point.getX() << " " << point.getY() << " ";
	point = rect.getRp();
	os << point.getX() << " " << point.getY() << " ";
	os << rect.getArea();
	return os;
}

Rect operator+(const Rect &rect1, const Rect &rect2)
{
	Point lpoint, rpoint;
	lpoint.setX(min(rect1.lp.getX(), rect2.lp.getX()));
	lpoint.setY(min(rect1.lp.getY(), rect2.lp.getY()));
	rpoint.setX(max(rect1.rp.getX(), rect2.rp.getX()));
	rpoint.setY(max(rect1.rp.getY(), rect2.rp.getY()));
	Rect newRect(lpoint, rpoint);
	newRect.Area();
	newRect.setID(max(rect1.getID(), rect2.getID()) + 1);
	return newRect;
}

bool operator<(const Rect &rect1, const Rect &rect2)
{
	if (rect1.getArea() < rect2.getArea())
		return true;
	else
		return false;
}
