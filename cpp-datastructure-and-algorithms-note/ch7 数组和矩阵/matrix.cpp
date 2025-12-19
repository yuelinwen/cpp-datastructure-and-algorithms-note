#include <iostream>
using namespace std;

template<class T>
class matrix {
	friend ostream& operator<<(ostream&, const matrix<T>&);
public:
	matrix(int theRows = 10, int theCols = 0);
	matrix(const matrix<T>&); // copy constructor
	~matrix() { delete[] element; }
	int rows() const { return rowSize; }
	int columns() const { return colSize; }
	T& operator()(int i, int j);
	matrix<T>& operator=(const matrix<T>&);
	matrix<T> operator+() const; // unary plus
	matrix<T> operator+(const matrix<T>&) const;
	matrix<T> operator-() const; // unary minus
	matrix<T> operator-(const matrix<T>&) const;
	matrix<T> operator*(const matrix<T>&) const;
	matrix<T>& opeartor += (const matrix<T>&);
private:
	int theRow, theColumns;
	T* element;
};


template<class T>
matrix<T>::matrix(int theRows, int theCols) {
	if (theRows < 1 || theCols < 1) {
		cerr << "Matrix size error!" << endl;
		exit(1);
	}
	rowSize = theRows;
	colSize = theCols;
	element = new T[rowSize * colSize];
}

template<class T>
matrix<T>::matrix(const matrix<T>& m) {
	rowSize = m.rowSize;
	colSize = m.colSize;
	element = new T[rowSize * colSize];
	copy(m.element, m.element + rowSize * colSize, element);
}


template<class T>
matrix<T> & matrix<T>::operator=(const matrix<T>& m) {
	if (this != &m) {
		delete[] element;
		rowSize = m.rowSize;
		colSize = m.colSize;
		element = new T[rowSize * colSize];
		copy(m.element, m.element + rowSize * colSize, element);
	}
	return *this;
}