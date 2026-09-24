#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Simplex {
	public:
		Simplex(std::vector<int> ind); // initialize with the indices

		int getDim() const; // get the order/dimension of the simplex
		const std::vector<int>& getVertices() const;

		std::vector<Simplex> getFaces() const;

		bool operator==(const Simplex& other) const;
		bool operator<(const Simplex& other) const;
		
		static void printSimplex(const Simplex& s);
	private:
		std::vector<int> indicesOfPoints; // reference to points in the pointCloud. ASSUME the simplex uses the pointCloud
};
