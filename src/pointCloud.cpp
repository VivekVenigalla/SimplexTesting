#include "../include/pointCloud.hpp"
#include <cmath> // for square root

void PointCloud::addPoint(const Point& pt) {
	allPoints.push_back(pt); //push back element in array
}

double hFunc(const Point& pt) {
	double* minDist = nullptr; //initialize to nullptr so we can check in initial if
	double dist;
	for(Point temp : points) {
		//calculate distance
		for(i = 0; i < temp.size(); i++) {
			// add the square of the component
			dist += point[i] * point[i];
		}
		//square root the distance
		dist = std::sqrt(dist);
		//check if the distance is the smallest or minDist is null
		if(minDist == nullptr || dist < minDist) {
			minDist = dist;
		}
		dist = 0; // set dist to 0
	}
	return *minDist; //access pointer value
}