#include <string>
#include <iostream>
#include <vector>
#include "./include/pointCloud.hpp"
#include "./include/point.hpp"

class Simplex {
	public:
		Simplex(int order, PointCloud& ref);
		int returnOrder();
		void addIndices(std::vector<int> ind);
	private:
		int order;
		PointCloud& pcRef; // reference to point cloud of all points
		std::vector<int> indicesOfPoints; // indices of select points in point cloud as part of simplex
};