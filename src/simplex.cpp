#include "../include/simplex.hpp"

Simplex::Simplex(int i_order, PointCloud& ref) : order(i_order), pcRef(ref){
	std::cout << "Simplex object with order " << this->order << " created" << std::endl;
}

void Simplex::addIndices(std::vector<int> ind) {
	if ((int)ind.size() !=  order + 1) {
		std::cout << "Order is not equal to the |indices| + 1" << std::endl;
	} else {
		this->indicesOfPoints = ind;
	}
}

int Simplex::returnOrder() {
	return this->order;
}