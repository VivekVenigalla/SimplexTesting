#pragma once
#include "./simplex.hpp"
#include <set>

class SimplicialComplex {
	public:
		SimplicialComplex(); // no additional parameters to initialize
		void addSimplex(const Simplex& si);
		bool contains(const Simplex& si) const;
		int getDim() const;
		std::vector<Simplex> getSimplices(int d) const;
		int countSimplices(int d) const;
		int size() const;
		static void printComplex(const SimplicialComplex& c);
	private:
		std::set<Simplex> simplices; // std::set auto rejects duplicates
};
