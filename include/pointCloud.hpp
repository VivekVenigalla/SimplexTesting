#include <vector>
#include <array>


template <size_t N>
class PointCloud {
public:
	using Point = std::array<double, N>;

	std::vector<Point> allPoints; //instance variable for allPoints

	void addPoint(const Point& pt);
	double hFunc(const Point& pt);


};