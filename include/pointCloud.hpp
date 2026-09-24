#include <vector>
#include <array>
#include "./point.hpp"

template <size_t N>
class PointCloud {
public:
	std::vector<Point> allPoints; //instance variable for allPoints

	void addPoint(const Point& pt);
	double hFunc(const Point& pt);


};