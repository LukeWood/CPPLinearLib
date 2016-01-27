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
	private:
		int** rows;
		int height;
		int width;	
	public:
		matrix(const matrix&);
		matrix(int,int);
		int* operator[](int) const;
		int getHeight() const;
		int getWidth() const;
};
linear::matrix operator*(const linear::matrix&, const linear::matrix&);
ostream& operator<<(ostream&,const matrix&);
}
#endif
