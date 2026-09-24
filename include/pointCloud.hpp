#include <vector>
#include <array>
#include "./point.hpp"

class PointCloud {
public:
	std::vector<Point> allPoints; //instance variable for allPoints
	int dimension;

	PointCloud(int d);

	void addPoint(const Point& pt);
	double hFunc(const Point& pt);


};