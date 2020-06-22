#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <limits>

template <typename T>
class Matrix
{
private:
	std::vector<std::vector<T>> mat;
	std::size_t dim_row;
	std::size_t dim_col;
	void matChecker(const std::vector<std::vector<T>>& mat) const;
public:
	Matrix();
	Matrix(const std::vector<std::vector<T>>& mat);
	Matrix(const Matrix<T>& mat);

	// This sets row size and if bigger than current
	// the values will be a boolean val one for 1's 
	// and boolean one for 0's
	void setDimRow(std::size_t& dim_row, bool one);
	void setDimCol(std::size_t& dim_col, bool one);
	void setMat(const std::vector <std::vector<T>>& mat);
	 
	std::size_t getRowDim() const { return this->dim_row; }
	std::size_t getColDim() const { return this->dim_col; }
	std::vector<std::vector<T>> getMat() const { return this->mat; }

	bool operator==(const Matrix<T>& mat) const;

	Matrix<T>& operator=(const Matrix<T>& mat);

	std::vector<T> operator[](const std::size_t& iter) const { return this->mat.at(iter); }

	friend std::ostream& operator<<(std::ostream& os, const Matrix<T> &mat) {
		for (std::size_t i = 0; i < mat.dim_row; i++) {
			for (std::size_t j = 0; j < mat.dim_col; j++) {
				os << mat.mat[i][j] << " ";
			}
			os << std::endl;
		}

		return os;
	}

};

template <typename T>
Matrix<T>& operator+(const Matrix<T>& m1, const Matrix<T>& m2) {

	Matrix<T> obj{m1};

	std::vector < std::vector<T>> objMat;
	std::vector < std::vector<T>> m1Mat = m1.getMat();
	std::vector < std::vector<T>> m2Mat = m2.getMat();


	for (std::size_t i = 0; i < m1.getRowDim(); i++) {
		for (std::size_t j = 0; j < obj.getColDim(); j++) {
			objMat[i][j] = m1Mat[i][j] + m2Mat[i][j];
		}
	}

	return obj;

}



#endif // MATRIX_H