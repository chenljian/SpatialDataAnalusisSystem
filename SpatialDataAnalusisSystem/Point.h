#pragma once
#include "Shape.h"
using std::ostream;
class Line;
class Rect;
class Point : public Shape {
	float x, y;
	static int count;
public:
	Point() : x(0), y(0) { Point::count++; }
	Point(float fx, float fy) : x(fx), y(fy) { Point::count++; }
	Point(const Point&);
	~Point() { Point::count--; }

	virtual float Area() { return 0; }
	virtual void WriteToFile(ofstream &o);
	static int GetCount() { return count; }

	void setX(float fx) { x = fx; }
	float getX() const { return x; }
	void setY(float fy) { y = fy; }
	float getY() const { return y; } 
	float Distance(const Point&) const;
	float Distance_R(const Rect&) const;
	float Distance_L(const Line&) const;
	int lowerDes();

	friend ostream& operator<<(ostream& os, const Point& outputPoint);
	friend bool operator<(const Point&, const Point&);
	friend Point operator+(const Point&, const Point&);

	friend class Line;
};