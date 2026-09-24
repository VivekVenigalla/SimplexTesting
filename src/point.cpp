#include "../include/point.hpp"
#include <cmath>

Point::Point(int d, std::vector<double> in) : dimension(d), p(in){

}
Point::Point(int d) : dimension(d){

}

int Point::getDim() const {
	return dimension;
}

void Point::addElement(double in) {
	if ((int)p.size() == dimension) {
		std::cout << "Vector already full";
	} else {
		p.push_back(in);
	}
}

Point Point::operator+(const Point& other) const {
	if (other.getDim() != dimension) {
		throw std::invalid_argument("Incorrect dimensions");
	} // check dimensions
	Point r(dimension);
	for (int i = 0; i < dimension ; i++) {
		r.addElement(p[i] + other.p[i]);
	} // for
	return r;
}

Point Point::operator-(const Point& other) const {
	if (other.getDim() != dimension) {
		throw std::invalid_argument("Incorrect dimensions");
	} // check dimensions
	Point r(dimension);
	for (int i = 0; i < dimension ; i++) {
		r.addElement(p[i] - other.p[i]);
	} // for
	return r;
}

Point Point::operator*(const double& c) const {
	Point r(dimension);
	for (const auto element : p) {
		r.addElement(element * c);
	}
	return r;
}

double Point::getDist(const Point& other) const {
	if (other.getDim() != dimension) {
		throw std::invalid_argument("Incorrect dimensions");
	} // check dimensions
	double temp = 0;
	for (int i = 0; i < dimension; i++) {
		temp += std::pow((p[i] - other.p[i]), 2);
	}
	return std::sqrt(temp);
}

//NOTE : don't repeat static keywords in cpp files in mentioned in hpp file
void Point::printPoint(const Point& po) {
    std::cout << "Dimension of point: " << po.getDim() << std::endl;
    std::cout << "Point : (";
    for (i = 0; i < po.dimension ; i++) {
    	if (i = po.dimension-1) {

    	}
    	std::cout << element << ", ";
    }
    std::cout << ")" << std::endl;

}
