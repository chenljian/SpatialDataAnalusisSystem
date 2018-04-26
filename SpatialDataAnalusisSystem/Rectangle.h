#pragma once
#include "Point.h"
class Rect : public Shape {
	Point lp;	//Lower left corner
	Point rp;	//top right corner
	static int count;
public:
	Rect() : lp(0, 0), rp(0, 0) { count++; }
	Rect(Point plp, Point prp) :lp(plp), rp(prp) { count++; }
	Rect(const Rect&);
	~Rect() { count--; }

	virtual float Area(); //
	virtual void WriteToFile(ofstream& o);
	static int GetCount() { return count; }

	int setLp(const Point&);
	int setRp(const Point&);
	float Distance(const Rect&);

	friend ostream& operator<<(ostream&, const Rect&);
	friend Rect operator+(const Rect&, const Rect&);
	friend bool operator<(const Rect&, const Rect&);
};