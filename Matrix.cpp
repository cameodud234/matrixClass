#include "Matrix.h"

template class Matrix<int>;
template class Matrix<long int>;
template class Matrix<float>;
template class Matrix<double>;
template class Matrix<std::size_t>;

template <typename T>
Matrix<T>::Matrix() {
	this->dim_row = 0;
	this->dim_col = 0;
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
void Matrix<T>::setDimRow(const std::size_t& dim_row) {
	this->mat.resize(dim_row);
	this->dim_row = dim_row;
}

template <typename T>
void Matrix<T>::setDimCol(const std::size_t& dim_col) {

	for (std::size_t i = 0; i < this->dim_row; i++) {
		this->mat[i].resize(dim_col);
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
T Matrix<T>::getMaxElem() const {
	T max = 0;
	for (std::size_t i = 0; i < this->dim_row; i++) {
		for (std::size_t j = 0; j < this->dim_col; j++) {
			if (max < this->mat[i][j]) {
				max = this->mat[i][j];
			}
		}
	}
	return max;
}

template <typename T>
bool Matrix<T>::operator==(const Matrix<T>& mat) const {
	bool val = (this->mat == mat.mat) &&
		(this->dim_row == mat.dim_row) &&
		(this->dim_col == mat.dim_col);

	return val;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& mat) {
	this->mat = mat.mat;
	this->dim_row = mat.dim_row;
	this->dim_col = mat.dim_col;
	return *this;
}

