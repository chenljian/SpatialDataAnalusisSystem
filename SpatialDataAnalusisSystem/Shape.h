#pragma once
#include <iostream>
#include <String>
using namespace std;
class Shape {
	int obj_id;	//object identity
	string des;	//character
public:
	virtual float Area() = 0;
	virtual void WriteToFile(ofstream &o) = 0;
};
