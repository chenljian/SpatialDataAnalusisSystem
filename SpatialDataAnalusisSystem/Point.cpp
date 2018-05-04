#include "Point.h"
#include <fstream>
#include <algorithm>
#include "Rectangle.h"
#include "Line.h"
Point::Point(const Point &p)
{
	setID(p.getID());
	x = p.x;
	y = p.y;
	setDes(p.getDes());
	count++;
}
void Point::WriteToFile(ofstream & os)
{
//	os << this->getID() << " ";
//	os << this->x << " " << this->y << " ";
//	os << this->getDes();
	os << *this;
}

float Point::Distance(const Point &point) const
{
	return sqrt(pow(point.x - this->x, 2)+ pow(point.y - this->y, 2));
}

float Point::Distance_R(const Rect &rect) const
{
	//构造矩形的四条线段
	Point point1 = rect.getLp();
	Point point3 = rect.getRp();
	Point point2(point1.getX(), point3.getY());
	Point point4(point3.getX(), point1.getY());
	Line line1(point1, point2);
	Line line2(point2, point3);
	Line line3(point3, point4);
	Line line4(point4, point1);

	//判断点是否在矩形内部
	if (this->x >= point1.x && this->x <= point2.x
		&& this->y >= point1.y && this->y <= point2.y)
		return 0.0f;

	//分别求点到矩形四条边的距离
	float a = this->Distance_L(line1);
	float b = this->Distance_L(line2);
	float c = this->Distance_L(line3);
	float d = this->Distance_L(line4);

	return min(min(a,b),min(c,d));
}

float Point::Distance_L(const Line &line) const
{
	float a, b, c;
	a = this->Distance(line.getP1());
	if (a < 0.0001)
		return 0.0f;
	b = this->Distance(line.getP2());
	if (b < 0.0001)
		return 0.0f;
	c = line.getP1().Distance(line.getP2());
	if (c < 0.0001)
		return a;

	if (a*a >= b*b + c*c)
		return b;
	if (b*b >= a * a + c * c)
		return a;
	float l = (a + b + c) / 2;
	float s = sqrt(l*(l - a)*(l - b)*(l - c));
	return 2*s/c;
}

int Point::lowerDes()
{
	string shapDes = getDes();
	transform(shapDes.begin(), shapDes.end(), shapDes.begin(), ::tolower);
	setDes(shapDes);
	return 1;
}


ostream& operator<<(ostream& os, const Point& point)
{
	os << point.getID() << " ";
	os << point.x << " " << point.y << " ";
	os << point.getDes();
	return os;

}

bool operator<(const Point &point1, const Point &point2)
{
	if (point1.getDes() < point2.getDes())
		return true;
	else
		return false;
}

Point operator+(const Point &point1, const Point &point2)
{
	Point newPoint(point1.x + point2.x, point1.y + point2.y);
	newPoint.setID(max(point1.getID(), point2.getID()) + 1);
	return newPoint;
}
