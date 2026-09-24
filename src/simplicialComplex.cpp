#include "../include/simplicialComplex.hpp"

SimplicialComplex::SimplicialComplex() {
	//empty constructor
}

void SimplicialComplex::addSimplex(const Simplex& si) {
	//recursive definition
	// base step : a point has no faces so it is only added itself
	// recursion step : add all of the faces of it and then itself
	// if it is already in the set then all of its faces are too, so we can stop
	if (contains(si)) {
		return;
	}
	for (const auto& s : si.getFaces()) {
		addSimplex(s);
	}
	simplices.insert(si);
}

bool SimplicialComplex::contains(const Simplex& si) const {
	return simplices.find(si) != simplices.end();
}

int SimplicialComplex::getDim() const {
	int dim = -1; // dimension of the empty complex
	for (const auto& s : simplices) {
		if (s.getDim() > dim) {
			dim = s.getDim();
		}
	}
	return dim;
}

std::vector<Simplex> SimplicialComplex::getSimplices(int d) const {
	std::vector<Simplex> result;
	for (const auto& s : simplices) {
		if (s.getDim() == d) {
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
