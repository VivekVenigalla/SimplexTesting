#include "../include/simplex.hpp"

Simplex::Simplex(int i_order) : order(i_order){
	std::cout << "Simplex object with order " << this->order << " created" << std::endl;
}

int Simplex::returnOrder() {
	return this->order;
}