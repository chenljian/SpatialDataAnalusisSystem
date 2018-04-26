#include <vector>
#include <fstream>
#include "Point.h"
#include "Line.h"
#include "Rectangle.h"

int readPointFromFile(vector<Point>&, ifstream&);
int readLineFromFile(vector<Line>&, ifstream&);
int readRectFromFile(vector<Rect>&, ifstream&);
void WriteData(Shape*, ofstream&);

void main(int argc, char* argv[])
{
	vector<Point> pointVector;
	vector<Line> lineVector;
	vector<Rect> rectVector;
	//任务2，从三个文件里面读数据

	ifstream pointInFile("point.txt");
	readPointFromFile(pointVector, pointInFile);

	ifstream lineInFile("line.txt");
	readLineFromFile(lineVector, lineInFile);

	ifstream rectInFile("rect.txt");
	readRectFromFile(rectVector, rectInFile);

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

	auto maxLength = lineVector.begin();
	auto minLength = lineVector.begin();
	auto lineIterator = lineVector.begin();
	while (lineIterator != lineVector.end()) {
		if (lineIterator->Area() > maxLength->Area())
			maxLength = lineIterator;
		else if (lineIterator->Area < minArea->Area())
			minLength = lineIterator;
		lineIterator++;
	}
	ofstream minAndMaxLine("Line_data.txt");
	minAndMaxLine << *minLength;
	minAndMaxLine << *maxLength;

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





			
}

int readPointFromFile(vector<Point>& pointVec, ifstream& in_file) {}
int readLineFromFile(vector<Line>&, ifstream&) {}
int readRectFromFile(vector<Rect>&, ifstream&) {}
void WriteData(Shape* s, ofstream& out_file) {}
