#include "Matrix.h"

template class Matrix<int>;
template class Matrix<unsigned int>;
template class Matrix<long int>;
template class Matrix<float>;
template class Matrix<double>;
template class Matrix<std::size_t>;

template <typename T>
Matrix<T>::Matrix() {
	this->dim_row = INT_MIN;
	this->dim_col = INT_MIN;
}

template <typename T>
void Matrix<T>::matChecker(const std::vector < std::vector<T>>& mat) const {
	std::size_t dim_row = mat.size();
	std::size_t dim_col = mat[0].size();

	// Check if the column dimension is consistent
	// to perform meaningful math calculations.
	for (std::size_t i = 1; i < dim_row; i++) {
		std::size_t tmp_size = mat[i].size();
		if (tmp_size != dim_col) {
			throw std::exception("Rows and columns must be consistent");
		}
	}
}

template <typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>>& mat) {
	this->matChecker(mat);
	this->dim_col = mat[0].size();
	this->dim_row = mat.size();
	this->mat = mat;
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& mat) {
	this->mat = mat.mat;
	this->dim_row = mat.dim_row;
	this->dim_col = mat.dim_col;
}

template <typename T>
void Matrix<T>::setDimRow(std::size_t& dim_row, bool& one) {

	if (dim_row > this->dim_row && one) {

		std::vector<T> addVec{};
		for (std::size_t i = 0; i < this->dim_col; i++) {
			addVec.push_back(1);
		}

		this->mat.push_back(addVec);

	}
	else if (dim_row > this->dim_row && !one) {

		std::vector<T> addVec{};
		for (std::size_t i = 0; i < this->dim_col; i++) {
			addVec.push_back(0);
		}

		this->mat.push_back(addVec);

	}

	else {
		this->mat.resize(dim_row);
	}

	this->dim_row = dim_row;

}

template <typename T>
void Matrix<T>::setDimCol(std::size_t& dim_col, bool& one) {

	if (dim_col > this->dim_col && one) {

		for (std::size_t i = 0; i < this->dim_row; i++) {
			this->mat[i].push_back(1);
		}

	}

	else if (dim_col > this->dim_col && !one) {

		for (std::size_t i = 0; i < this->dim_row; i++) {
			this->mat[i].push_back(0);
		}

	}

	else {
		for (std::size_t i = 0; i < this->dim_row; i++) {
			this->mat[i].resize(dim_col);
		}
	}

	this->dim_col = dim_col;

}

template <typename T>
void Matrix<T>::setMat(const std::vector <std::vector<T>>& mat) {
	this->matChecker(mat);
	this->mat = mat;
	this->dim_row = mat.size();
	this->dim_col = mat[0].size();
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& m) {
	bool rowIsSame = this->dim_row == m.getRowDim();
	bool colIsSame = this->dim_col == m.getColDim();
	
	Matrix<T> obj{};

	// We can resize this here instead of dynamically resizing this.

	if (rowIsSame && colIsSame) {
		for (std::size_t i = 0; i < this->dim_row; i++) {
			for (std::size_t j = 0; j < this->dim_col; j++) {
				
			}
		}
	}

	return obj;
}

template <typename T>
bool Matrix<T>::operator==(const Matrix<T>& mat) const {
	bool val = (this->mat == mat.mat) &&
		(this->dim_row == mat.dim_row) &&
		(this->dim_col == mat.dim_col);

	return val;
}

template <typename T>
Matrix<T> Matrix<T>::operator=(const Matrix<T>& mat) {
	Matrix obj{ mat };
	obj.mat = mat.mat;
	obj.dim_row = mat.dim_row;
	obj.dim_col = mat.dim_col;
	return obj;
}