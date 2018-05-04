#pragma once
#include "Point.h"
class Rect : public Shape {
	Point lp;	//Lower left corner
	Point rp;	//top right corner
	double area;
	static int count;
public:
	Rect() : lp(0, 0), rp(0, 0) { Rect::count++; }
	Rect(Point plp, Point prp) :lp(plp), rp(prp) { Rect::count++; }
	Rect(const Rect&);
	~Rect() { Rect::count--; }

	virtual float Area(); //
	virtual void WriteToFile(ofstream& o);
	static int GetCount() { return count; }

	int setLp(const Point&);
	const Point& getLp() const;
	int setRp(const Point&);
	const Point& getRp() const;
	void setArea(const float a) { area = a; }
	double getArea() const { return area; }
	float Distance(const Rect&);

	friend ostream& operator<<(ostream&, const Rect&);
	friend Rect operator+(const Rect&, const Rect&);
	friend bool operator<(const Rect&, const Rect&);
};