#ifndef MATRIX_H
#define MATRIX_H
#include <ostream>
namespace neuralnets
{
class matrix
{
	std::ostream friend &operator<<(std::ostream&,matrix&);
	matrix friend operator*(const matrix&,const matrix&);
	private:
		int** rows;
		int height;
		int width;	
	public:
		matrix operator=(const matrix&);
		matrix(int,int);
		int* operator[](int);
};
}
#endif
