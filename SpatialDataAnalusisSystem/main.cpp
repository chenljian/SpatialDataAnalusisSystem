#include <vector>
#include <fstream>
#include "Point.h"
#include "Line.h"
#include "Rectangle.h"
#include <algorithm>

int readPointFromFile(vector<Point>&, ifstream&);
int readLineFromFile(vector<Line>&, ifstream&);
int readRectFromFile(vector<Rect>&, ifstream&);
void WriteData(Shape*, ofstream&);

int Point::count = 0;
int Line::count = 0;
int Rect::count = 0;

int main(int argc, char* argv[])
{
	vector<Point> pointVector;
	vector<Line> lineVector;
	vector<Rect> rectVector;
	//任务2，从三个文件里面读数据

	ifstream pointInFile("point.txt");
	readPointFromFile(pointVector, pointInFile);
	pointInFile.close();

	ifstream lineInFile("line.txt");
	readLineFromFile(lineVector, lineInFile);
	lineInFile.close();

	ifstream rectInFile("rect.txt");
	readRectFromFile(rectVector, rectInFile);
	rectInFile.close();

	//任务3， 遍历所有数据，找出最大最小
	auto maxArea = rectVector.begin();
	auto minArea = rectVector.begin();
	auto rectIterator = rectVector.begin();
	while (rectIterator != rectVector.end()) {
		if (rectIterator->Area() > maxArea->Area())
			maxArea = rectIterator;
		else if (rectIterator->Area() < minArea->Area())
			minArea = rectIterator;
		rectIterator++;
	}
	ofstream minAndMaxRect("Rect_data.txt");
	minAndMaxRect << *minArea;
	minAndMaxRect << *maxArea;
	minAndMaxRect.close();

	auto maxLength = lineVector.begin();
	auto minLength = lineVector.begin();
	auto lineIterator = lineVector.begin();
	while (lineIterator != lineVector.end()) {
		if (lineIterator->Area() > maxLength->Area())
			maxLength = lineIterator;
		else if (lineIterator->Area() < minArea->Area())
			minLength = lineIterator;
		lineIterator++;
	}
	ofstream minAndMaxLine("Line_data.txt");
	minAndMaxLine << *minLength;
	minAndMaxLine << *maxLength;
	minAndMaxLine.close();

	//任务四
	cout << endl << "********现在演示任务 4**********" << endl;
	Point point1 = pointVector[0];
	Point point2 = pointVector[1];
	cout << "Point1:(" << point1 << ")	Point2:(" << point2 <<")"<< endl;
	cout << "Point1 ";
	point1 < point2 ? cout << " < " : cout <<" !< ";
	cout << "Point2" << endl;
	cout << "Point1 + Point2 = (" << point1 + point2 << ")" <<endl;
	Rect rect1 = rectVector[0];
	Rect rect2 = rectVector[1];
	cout << "Rectangle1:(" << rect1 << ")	Rectangle2:(" << rect2 << ")" << endl;
	cout << "Rectangle1 + Rectangle2 = (" << rect1 + rect2 << ")" << endl;

	cout << endl << "********现在演示任务 5**********" << endl;
	Line line1 = lineVector[0];
	cout << "Point1	Point2	distance : " << point1.Distance(point2) << endl;
	cout << "Rect1	Rect2	distance : " << rect1.Distance(rect2) << endl;
	cout << "Point1	Rect1	distance : " << point1.Distance_R(rect1) << endl;
	cout << "Point1	line	distance : " << point1.Distance_L(line1) << endl;

	//排序并写入文件
	cout << endl << "********现在演示任务 6**********" << endl;
	for (auto it = pointVector.begin(); it != pointVector.end(); it++){
		it->lowerDes();
	}
	sort(pointVector.begin(), pointVector.end());
	ofstream pointOutFile("Point2.txt");
	for (unsigned i = 0; i < pointVector.size(); i++) {

		Shape* outShape = &pointVector[i];
		WriteData(outShape, pointOutFile);
		pointOutFile << endl;
	}
	pointOutFile.close();

	sort(rectVector.begin(), rectVector.end());
	ofstream rectOutFile("Rect2.txt");
	for (unsigned i = 0; i < rectVector.size(); i++) {

		Shape* outShape = &rectVector[i];
		WriteData(outShape, rectOutFile);
		rectOutFile << endl;
	}
	rectOutFile.close();

	sort(lineVector.begin(), lineVector.end());
	ofstream lineOutFile("Line2.txt");
	for (unsigned i = 0; i < lineVector.size(); i++) {
		Shape* outShape = &lineVector[i];
		WriteData(outShape, lineOutFile);
		lineOutFile << endl;
	}
	lineOutFile.close();
	system("pause");
	//end
}

int readPointFromFile(vector<Point>& pointVec, ifstream& in_file) {
	int id;
	float x, y, hole;
	string des;
	while (!in_file.fail())
	{
		in_file >> id >> x >> y >>hole >> des;
		if (in_file.fail())	break;
		Point pointObj(x, y);
		pointObj.setID(id);
		pointObj.setDes(des);
		pointVec.push_back(pointObj);
	}
	return 1;
}
int readLineFromFile(vector<Line>& lineVec, ifstream& in_file) {
	int id;
	float x, y, len;
	while (!in_file.fail()) {
		in_file >> id;
		in_file >> x >> y;
		Point point1(x, y);
		in_file >> x >> y;
		Point point2(x, y);
		Line lineObj(point1, point2);
		lineObj.setID(id);
		in_file >> len;
		lineObj.setLen(len);
		if (in_file.fail())	break;
		lineVec.push_back(lineObj);
	}
	return 1;
}
int readRectFromFile(vector<Rect>& rectVec, ifstream& in_file) {
	int id;
	float x, y, area;
	string hole;
	while (!in_file.fail()) {
		in_file >> id;
		in_file >> x >> y;
		Point point1(x, y);
		in_file >> x >> y;
		Point point2(x, y);
		in_file >> area >> hole;
		if (in_file.fail())	break;
		Rect rectObj(point1, point2);
		rectObj.setID(id);
		rectObj.setArea(area);
		rectVec.push_back(rectObj);
	}
	return 1;
}

void WriteData(Shape* s, ofstream& out_file) {
	s->WriteToFile(out_file);
}
