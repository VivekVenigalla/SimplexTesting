#include "../include/simplicialComplex.hpp"

SimplicialComplex::SimplicialComplex() {
	//empty constructor
}

void SimplicialComplex::addSimplex(const Simplex& si) {
	//recursive definition
	// base step : a point has no faces so it is only added itself
	// recursion step : add all of the faces of it and then itself
	// if it is already in the set then all of its faces are too, so we can stop
	if (contains(si)) { // since a face that is already in the complex will have the same child simplices, ignore it
		return;
	}
	for (const auto& s : si.getFaces()) {
		addSimplex(s); // iterate over all of the child simplices
	}
	simplices.insert(si); // insert for sets
}

bool SimplicialComplex::contains(const Simplex& si) const {
	return simplices.find(si) != simplices.end();
	// you can also use .contains() for sets but this version will work with older c++ versions
}

int SimplicialComplex::getDim() const {
	int dim = -1; // dimension of an empty complex because 0-1 = -1
	for (const auto& s : simplices) {
		if (s.getDim() > dim) {
			dim = s.getDim();
		}
	}
	return dim;
}

std::vector<Simplex> SimplicialComplex::getSimplices(int d) const {
	std::vector<Simplex> result;
	for (const auto& s : simplices) { // simple iteration
		if (s.getDim() == d) { // Remember getDim is a function of Simplex (# of vertexes - 1)
			result.push_back(s);
		}
	}
	return result;
}

int SimplicialComplex::countSimplices(int d) const {
	return (int)getSimplices(d).size();
}

int SimplicialComplex::size() const {
	return (int)simplices.size();
}

void SimplicialComplex::printComplex(const SimplicialComplex& c) {
	std::cout << "Simplicial complex of dimension " << c.getDim() << " with " << c.size() << " simplices" << std::endl;
	for (int d = 0; d <= c.getDim(); d++) {
		std::cout << "Number of " << d << "-simplices: " << c.countSimplices(d) << std::endl;
	}
}
