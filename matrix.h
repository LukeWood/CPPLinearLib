#ifndef MATRIX_H
#define MATRIX_H
#include <ostream>
using std::ostream;
namespace linear
{

class matrix
{
	//Prints to std::ostream
	friend ostream& operator<<(ostream&,const matrix&);
	//Multiply Matrices
	friend matrix operator*(const matrix&,const matrix&);
	//Multiply Matrices by a Scalar
	friend matrix operator*(double scalar, const matrix&);
	
		private:
			double** rows;
			int height;
			int width;	
		public:
			//Overloaded Copy Constructor
			matrix(const matrix&);
			//Basic Constructor Creating Matrix [0]
			matrix();
			//Creates a Zero Matrix of size specified;
			matrix(int,int);
			//Destructor
			~matrix();
			//Assignment Operator
			matrix operator=(const matrix&);
			//operator to access a row	
			double* operator[](int) const;
			//Multiply by scalar
			matrix operator*(double) const;
			//Add to matrix
			matrix operator+(const matrix&) const;
			//Subtraction Matrix
			matrix operator-(const matrix&) const;
			//Add a double to ALL values in matrix
			matrix operator+(double) const;
			//subtract from ALL values in matrix
			matrix operator-(double) const;
			
			int getHeight() const;
			int getWidth() const;
			
			//Returns the dot product of the two matrices
			double dot(const matrix&) const;
			
			//Transpose			
			matrix T() const;
};

linear::matrix operator*(const linear::matrix&, const linear::matrix&);
linear::matrix operator*(const int, const linear::matrix&);
ostream& operator<<(ostream&,const matrix&);

}
#endif
