#pragma once
#include "Shape.h"
#include "Point.h"
class Line : public Shape {
	Point p1;
	Point p2;
	double len;
	static int count;
public:
	Line() { count++; }
	Line(Point, Point);
	Line(Line&);
	~Line() { count--; }

	virtual float Area();
	virtual void WriteToFile(ofstream& o);
	static int GetCount() { return count; }

	void setP1(const Point&);
	void setP2(const Point&);

	friend ostream& operator<<(ostream&, const Line&);
	friend bool operator<(const Line&, const Line&);
};
