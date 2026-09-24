#include "../include/simplex.hpp"
#include "../include/pointCloud.hpp"
#include "../include/point.hpp"


int main() { //int argc, char* argv[] not used right now to circumvent warnings
	std::cout << "Running main" << std::endl;
	
	/*PointCloud<3> temp; 
	// intiialize a point cloud in R^3
	std::array<double, 3> tempPoint= {1.0, 2.0, 3.0};
	temp.addPoint(tempPoint);*/

	Simplex triangle({2, 0, 1}); // triangle simplex
	std::cout << "Triangle Simplex " << std::endl;
	Simplex::printSimplex(triangle);
	std::cout << "Triangle Simplex Faces" << std::endl;
	for (const auto& face : triangle.getFaces()) {
		Simplex::printSimplex(face);
	}
	//std::cout << "Same simplex from different order : " << (triangle == Simplex({0, 1, 2})) << std::endl;

	Simplex tetrahedron({3, 1, 0, 2}); //create sample simplex
	std::cout << "Tetrahedron Simplex" << std::endl;
	Simplex::printSimplex(tetrahedron); // print the simplex
	std::cout << "Tetrahedron Simplex Faces" << std::endl;
	for (const auto& face : tetrahedron.getFaces()) {
		Simplex::printSimplex(face);
		for (const auto& edge : face.getFaces()) {
			Simplex::printSimplex(edge);
		}
	}

	// additional tests
	std::cout << "Additional tests: " << std::endl;
	Point a(2, {1.0, 2.0});
	Point b(2, {3.0, 4.0});
	Point sum = a + b;
	Point scaled = a * 3.0;
	Point::printPoint(sum);
	Point::printPoint(scaled);
	double distAB = a.getDist(b);
	std::cout << "Dist between a and b : " << distAB << std::endl;
	PointCloud newCloud(2);
	newCloud.addPoint(a);
	newCloud.addPoint(b);
	double minDist = newCloud.hFunc(Point{2, {5.0, 6.0}});
	std::cout << "hFunc of (5.0, 6.0) : " << minDist << std::endl;
	std::cout << "End of main" << std::endl;
}
