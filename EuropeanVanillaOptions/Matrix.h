#pragma once
#include <vector>

using namespace std;
template <typename T = double> class Matrix
{

private:
	vector<vector<T>> matrix;


public:
	Matrix();
	virtual ~Matrix();

	Matrix(const int& rows, const int& cols, const T& val);
	Matrix(const Matrix<T>& _rhs);
	Matrix<T>& operator=  (const Matrix<T>& _rhs);

	Matrix<T> get_matrix() const;
	T& value(const int& row, const int& col);
};

//76