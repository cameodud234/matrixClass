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
	void setDimRow(const std::size_t& dim_row);
	void setDimCol(const std::size_t& dim_col);
	void setMat(const std::vector <std::vector<T>>& mat);
	 
	std::size_t getRowDim() const { return this->dim_row; }
	std::size_t getColDim() const { return this->dim_col; }
	std::vector<std::vector<T>> getMat() const { return this->mat; }
	T getMaxElem() const ;

	void printVec() {
		for (std::size_t i = 0; i < this->dim_row; i++) {
			for (std::size_t j = 0; j < this->dim_col; j++) {
				std::cout << this->mat[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	bool operator==(const Matrix<T>& mat) const;

	Matrix<T>& operator=(const Matrix<T>& mat);

	std::vector<T> operator[](const std::size_t& iter) const { return this->mat.at(iter); }

	

	friend std::ostream& operator<<(std::ostream& os, const Matrix<T> &m) {
		for (std::size_t i = 0; i < m.dim_row; i++) {
			for (std::size_t j = 0; j < m.dim_col; j++) {
				os << m.mat[i][j] << " ";
			}
			os << std::endl;
		}					

		return os;
	}

};


/********************************************************************************************/

// overloaded operators

/********************************************************************************************/

template <typename T>
Matrix<T> operator+(const Matrix<T>& m1, const Matrix<T>& m2) {

	bool rowCheck = m1.getRowDim() == m2.getRowDim();
	bool colCheck = m1.getColDim() == m2.getColDim();

	Matrix<T> obj{};

	if (rowCheck && colCheck) {
		const std::size_t row_dim = m1.getRowDim();
		const std::size_t col_dim = m1.getColDim();

		obj.setDimRow(row_dim);
		obj.setDimCol(col_dim);

		std::vector < std::vector<T>> objMat = obj.getMat();
		std::vector < std::vector<T>> m1Mat = m1.getMat();

		std::vector < std::vector<T>> m2Mat = m2.getMat();

		for (std::size_t i = 0; i < row_dim; i++) {
			for (std::size_t j = 0; j < col_dim; j++) {

				objMat[i][j] = m1Mat[i][j] + m2Mat[i][j];
			}
		}

		obj.setMat(objMat);
	}

	else {
		throw std::exception("row and col space of matrices must match for '+' operator");
	}

	return obj;

}


template <typename T>
Matrix<T> operator-(const Matrix<T>& m1, const Matrix<T>& m2) {

	bool rowCheck = m1.getRowDim() == m2.getRowDim();
	bool colCheck = m1.getColDim() == m2.getColDim();

	Matrix<T> obj{};

	if (rowCheck && colCheck) {
		std::size_t row_dim = m1.getRowDim();
		std::size_t col_dim = m1.getColDim();

		obj.setDimRow(row_dim);
		obj.setDimCol(col_dim);

		std::vector < std::vector<T>> objMat = obj.getMat();
		std::vector < std::vector<T>> m1Mat = m1.getMat();

		std::vector < std::vector<T>> m2Mat = m2.getMat();

		for (std::size_t i = 0; i < row_dim; i++) {
			for (std::size_t j = 0; j < col_dim; j++) {

				objMat[i][j] = m1Mat[i][j] - m2Mat[i][j];
			}
		}

		obj.setMat(objMat);
	}

	else {
		throw std::exception("row and col space of matrices must match for '+' operator");
	}

	return obj;

}


template <typename T>
Matrix<T> operator*(double scale, const Matrix<T>& m) {

	Matrix<T> obj{};

	std::size_t row_dim = m.getRowDim();
	std::size_t col_dim = m.getColDim();

	obj.setDimRow(row_dim);
	obj.setDimCol(col_dim);

	std::vector < std::vector<T>> objMat = obj.getMat();
	std::vector < std::vector<T>> mMat = m.getMat();

	for (std::size_t i = 0; i < row_dim; i++) {
		for (std::size_t j = 0; j < col_dim; j++) {
			objMat[i][j] = scale * mMat[i][j];
		}
	}

	obj.setMat(objMat);

	return obj;
}

template <typename T>
Matrix<T> operator*(const Matrix<T>& m, double scale) {
	return operator*(scale, m);
}

template <typename T>
Matrix<T> operator*(const Matrix<T>& m1, const Matrix<T>& m2) {
	bool dimCheck = m1.getColDim() == m2.getRowDim();
	
	Matrix<T> obj{};
	
	std::size_t rowSize = m1.getRowDim();
	std::size_t colSize = m2.getColDim();
	
	obj.setDimRow(rowSize);
	obj.setDimCol(colSize);

	std::vector<std::vector<T>> objMat = obj.getMat();
	std::vector<std::vector<T>> m1Mat = m1.getMat();
	std::vector<std::vector<T>> m2Mat = m2.getMat();

	if (dimCheck) {
		for (std::size_t i = 0; i < rowSize; i++) {
			for (std::size_t j = 0; j < colSize; j++) {
				T sum = 0;
				for (std::size_t k = 0; k < m1.getColDim(); k++) {
					sum += m1Mat[i][k] * m2Mat[k][j];
				}
				
				objMat[i][j] = sum;
			}
		}
		obj.setMat(objMat);

	}
	else {
		throw std::exception("col space of first matrix must match row space of second matrix.");
	}

	return obj;
}


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



#endif // MATRIX_H