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
	friend matrix operator*(int scalar, const matrix&);
	
		private:
			int** rows;
			int height;
			int width;	
		public:
			matrix(const matrix&);
			matrix();
			matrix(int,int);
			~matrix();

			int* operator[](int) const;
			matrix operator*(int) const;
			matrix operator+(const matrix&) const;
			matrix operator-(const matrix&) const;
			matrix operator+(int) const;
			matrix operator-(int) const;

			matrix operator=(const matrix&);
			


			int getHeight() const;
			int getWidth() const;
			
			int dot(const matrix&) const;
			
			//Transpose			
			matrix T() const;
};

linear::matrix operator*(const linear::matrix&, const linear::matrix&);
linear::matrix operator*(const int, const linear::matrix&);
ostream& operator<<(ostream&,const matrix&);

}
#endif
