#include "../include/point.hpp"

Point::Point(int d, std::vector<double> in) : dimension(d), p(in);
Point::Point(int d) : dimension(d);

int Point::getDim(const Point& po) {
	return po.dimension;
}

Point::addElement(double in) {
	if (p.size() == dimension) {
		std::cout << "Vector already full";
	} else {
		p.push_back(in);
	}
}

Point Point::operator+(const Point& other){
	if (other.getDim() != dimension) {
		std::cout << "Incorrect dimensions" << std::endl;
		return 
	} // check dimensions
	else {
		Point r(dimension);
		for (int i = 0; i < dimension ; i++) {
			r.addElement(p[i] + other[i]);
		} // for
		return r;
	}
}

Point Point::operator-(const Point& other) {
	if (other.getDim != dimension) {
		std::cout << "Incorrect dimensions" << std::endl;
		return 
	} // check dimensions
	else {
		Point r(dimension);
		for (int i = 0; i < dimension ; i++) {
			r.addElement(p[i] - other[i]);
		} // for
		return r;
	}
}

Point Point::operator*(const double& c) {
	Point r(dimension);
	for (const auto element : p) {
		r.addElement(element * c);
	}
	return r;
}

friend std::ostream& Point::operator<<(std::ostream& os, const Point& po);{
    os << "Player(Name: " << po.name << ", Score: " << po.score << ")";
    return os;
}