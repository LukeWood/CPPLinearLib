#ifndef MATRIX_H
#define MATRIX_H
#include <ostream>
using std::ostream;
namespace linear
{

class matrix
{

	friend ostream& operator<<(ostream&,const matrix&);
	friend matrix operator*(const matrix&,const matrix&);
	friend matrix operator*(double scalar, const matrix&);
	
		private:
			double** rows;
			int height;
			int width;	
		public:
			matrix(const matrix&);
			matrix();
			matrix(int,int);
			~matrix();

			double* operator[](int) const;
			matrix operator*(double) const;
			matrix operator+(const matrix&) const;
			matrix operator-(const matrix&) const;
			matrix operator+(double) const;
			matrix operator-(double) const;

			matrix operator=(const matrix&);
			
			int getHeight() const;
			int getWidth() const;
			
			double dot(const matrix&) const;
			
			//Transpose			
			matrix T() const;
};

linear::matrix operator*(const linear::matrix&, const linear::matrix&);
linear::matrix operator*(const int, const linear::matrix&);
ostream& operator<<(ostream&,const matrix&);

}
#endif
