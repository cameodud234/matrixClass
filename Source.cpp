#include <iostream>
#include <vector>
#include "Matrix.h"
#include <random>
#include <time.h>


// easy way to resize matrix
template <typename T>
void vectorResize(std::vector<std::vector<T>>& vec, const std::size_t& n, const std::size_t& m) {
	vec.resize(n);
	for (std::size_t i = 0; i < n; i++) {
		vec[i].resize(m);
	}
}


void run() {
	std::vector<std::vector<double>> arr1;
	std::vector<std::vector<double>> arr2;

	srand(time(NULL));

	const std::size_t n_dim = 1000; // row space
	const std::size_t m_dim = 1000; // col space
	const std::size_t r_dim = 1000; // arr2 col space
	
	vectorResize(arr1,n_dim,m_dim);
	vectorResize(arr2,m_dim,r_dim);


	const unsigned int m = 1000; // size of random number

	for (std::size_t i = 0; i < n_dim; i++) {
		for (std::size_t j = 0; j < m_dim; j++) {
			double r1 = rand() % ((int)m);
			double r2 = rand() % ((int)m);
			arr1[i][j] = r1;
			arr2[i][j] = r2;
		}
	}

	Matrix<double> A1{ arr1 };
	Matrix<double> A2{ arr2 };

	Matrix<double> B1{};
	Matrix<double> B2{};
	Matrix<double> B3{};

	B1 = A1 + A2;
	B2 = A1 - A2;
	B3 = A1 * A2;

	std::cout << "A1 MAX Elem " << A1.getMaxElem() << std::endl;
	std::cout << "A2 MAX Elem " << A2.getMaxElem() << std::endl;
	std::cout << "A1 + A2 MAX Elem: " << B1.getMaxElem() << std::endl;
	std::cout << "A1 - A2 MAX Elem: " << B2.getMaxElem() << std::endl;
	std::cout << "A1 * A2 MAX Elem: " << B3.getMaxElem() << std::endl;
}



int main(int argc, char* argv[]) {
	try {
		run();
	}
	
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}