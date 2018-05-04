#pragma once
#include <iostream>
#include <string>
using namespace std;
class Shape {
	int obj_id;	//object identity
	string des;	//character
public:
	virtual float Area() = 0;
	virtual void WriteToFile(ofstream &o) = 0;

	void setDes(const string str) { des = str; }
	string getDes() const { return des; }

	void setID(const int id) { obj_id = id; }
	int getID() const { return obj_id; } 
};
