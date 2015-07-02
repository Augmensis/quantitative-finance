#pragma once
#include <vector>

template<typename T>
class QSMatrix
{
	std::vector<std::vector<T>> matrix;
	unsigned rows;
	unsigned cols;

public:
	QSMatrix();
	~QSMatrix();

	QSMatrix(const unsigned& _rows, const unsigned& _cols, const T& _initial);
	QSMatrix(const QSMatrix<T>& _rhs);
	QSMatrix<T>& operator=  (const QSMatrix<T>& _rhs);
	QSMatrix<T>& operator+=  (const QSMatrix<T>& _rhs);
	QSMatrix<T>& operator-  (const QSMatrix<T>& _rhs);
	QSMatrix<T>& operator-=  (const QSMatrix<T>& _rhs);
	QSMatrix<T>& operator*  (const QSMatrix<T>& _rhs);
	QSMatrix<T>& operator*=  (const QSMatrix<T>& _rhs);

	QSMatrix<T> Transpose();

	QSMatrix<T>& operator+ (const T& _rhs);
	QSMatrix<T>& operator- (const T& _rhs);
	QSMatrix<T>& operator* (const T& _rhs);
	QSMatrix<T>& operator/ (const T& _rhs);

	QSMatrix<T> get_QSMatrix() const;
	const T& operator()(const unsigned& row, const unsigned& col) const;
	T& operator()(const unsigned& row, const unsigned& col);

	unsigned get_rows();
	unsigned get_cols();

};

#include "Matrix.cpp"