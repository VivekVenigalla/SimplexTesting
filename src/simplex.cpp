#include "../include/simplex.hpp"

Simplex::Simplex(std::vector<int> ind) : indicesOfPoints(ind) {
	if (indicesOfPoints.empty()) {
		throw std::invalid_argument("Simplex needs at least one vertex");
	}
	// NOTE : .begin() gives the iterator whcih tells the algorithm where to start
	// the iterator is kind of like a pointer to a object of the vector but made for iterations
	std::sort(indicesOfPoints.begin(), indicesOfPoints.end()); // sort the whole vector
	// use std::adjacent_find to find any indices that are the same(we can do this since the vector is sorted)
	// returns the index of an element that has a matching element to the right, else returns the last element iterator
	if (std::adjacent_find(indicesOfPoints.begin(), indicesOfPoints.end()) != indicesOfPoints.end()) {
		throw std::invalid_argument("Simplex vertices must be distinct");
	}
}

int Simplex::getDim() const {
	return (int)indicesOfPoints.size() - 1; // the dimension/order of a simplex is # vertices - 1
}

const std::vector<int>& Simplex::getVertices() const {
	return indicesOfPoints;
}

std::vector<Simplex> Simplex::getFaces() const {
	std::vector<Simplex> faces;
	if (getDim() == 0) {
		return faces;
	}
	for (size_t i = 0; i < indicesOfPoints.size(); i++) {
		std::vector<int> face = indicesOfPoints;
		face.erase(face.begin() + i);
		faces.push_back(Simplex(face));
	}
	return faces;
}

bool Simplex::operator==(const Simplex& other) const {
	return indicesOfPoints == other.indicesOfPoints; // equals operator
}

bool Simplex::operator<(const Simplex& other) const {
	return indicesOfPoints < other.indicesOfPoints; // check if a simplex is smaller than another simplex
	// < operator compares lexigraphically between two vectors
}

void Simplex::printSimplex(const Simplex& s) {
	std::cout << "Simplex of dimension " << s.getDim() << ": [";
	for (size_t i = 0; i < s.indicesOfPoints.size(); i++) {
		if (i > 0) {
			std::cout << ", ";
		}
		std::cout << s.indicesOfPoints[i];
	}
	std::cout << "]" << std::endl;
}
