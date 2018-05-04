#include "Line.h"
//#include <string>
#include <fstream>
//#include <fstream>
using namespace std;

Line::Line(Point &point1, Point &point2):p1(point1),p2(point2)
{
	count++;
}

Line::Line(Line &line)
{
	p1 = line.p1;
	p2 = line.p2;
	len = line.len;
	count++;
}

float Line::Area()
{
	len = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	return len;
}

void Line::WriteToFile(ofstream & o)
{
	//o << this->getID() << " ";
	//Point point = this->getP1();
	//o << point.getX() << " " << point.getY() << " ";
	//point = this->getP2();
	//o << point.getX() << " " << point.getY() << " ";
	//o << this->len;
	o << this;
}

void Line::setP1(const Point &point)
{
	p1 = point;
}

const Point& Line::getP1() const
{
	return p1;
}

void Line::setP2(const Point &point)
{
	p2 = point;
}

const Point& Line::getP2() const
{
	return p2;
}

double Line::getLen() const
{
	return len;
}

ostream & operator<<(ostream &o, const Line &line)
{
	// TODO: 在此处插入 return 语句
	o << line.getID << " ";
	Point point = line.getP1();
	o << point.getX() <<" "<< point.getY() << " ";
	point = line.getP2();
	o << point.getX() <<" "<< point.getY() << " ";
	o << line.len;
}

bool operator<(const Line &line1, const Line &line2)
{
	if (line1.getLen() < line2.getLen())
		return true;
	else
		return false;
}
