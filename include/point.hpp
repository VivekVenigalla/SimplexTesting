#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
// although we can use arrays they are harder to work with since they are a fixed size
// I will use a vector for ease of building the point

class Point {
//for now we won't have any private variables or funcs
public:
	// instance variables for the point, including dimensionality
	int dimension; //can be size_t but we will use int for now
	std::vector<double> p; // point
	Point(int d, std::vector<double> in);
	Point(int d);
	int getDim() const;
	Point operator+(const Point& other) const;
	Point operator-(const Point& other) const;
	Point operator*(const double& c) const;
	void addElement(double in);
	static void printPoint(const Point& po);
};