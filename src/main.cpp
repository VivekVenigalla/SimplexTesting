#pragma once //include guardrails

#include "../include/simplex.hpp"
//#include "../include/pointCloud.hpp"
#include "../include/point.hpp"


int main() { //int argc, char* argv[] not used right now to circumvent warnings
	std::cout << "Running main" << std::endl;
	Simplex test(1);
	std::cout << test.returnOrder() << std::endl;

	/*PointCloud<3> temp; // intiialize a point cloud in R^3
	std::array<double, 3> tempPoint= {1.0, 2.0, 3.0};
	temp.addPoint(tempPoint);*/
	Point a(2);
	Point b(2);
	Point::printPoint(a);
	std::cout << "End of main" << std::endl;
}