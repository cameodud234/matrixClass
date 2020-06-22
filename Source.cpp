#include <iostream>
#include <vector>
#include "Matrix.h"

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> vec) {
	for (std::size_t i = 0; i < vec.size(); i++) {
		os << vec[i] << " ";
	}
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>> &mat) {
	for (std::size_t i = 0; i < mat.size(); i++) {
		for (std::size_t j = 0; j < mat[i].size(); j++) {
			os << mat[i][j] << " ";
		}
		os << "\n";
	}

	return os;
}

template <typename T>
void mix(std::vector<std::vector<T>>& val) {
	for (std::size_t i = 0; i < val.size(); i++) {
		for (std::size_t j = 0; j < val[0].size(); j++) {
			val[i][j] = 1;
		}
	}
}



int main(int argc, char* argv[]) {
	try {
		std::vector<std::vector<int>> arr1{ {2,3},{3,4},{5,6} };
		std::vector<std::vector<int>> arr2{ {1,2},{875,323},{6545,7665} };
		
		Matrix<int> A{ arr1 };
		Matrix<int> B{ arr2 };
		A = A + B;

		std::cout << A << std::endl;

	}
	
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}