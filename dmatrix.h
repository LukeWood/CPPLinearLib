#ifndef DMATRIX_H
#define DMATRIX_H
#include <ostream>
using std::ostream;
namespace linear
{

class dmatrix
{

	friend ostream& operator<<(ostream&,const dmatrix&);
	friend dmatrix operator*(const dmatrix&,const dmatrix&);
	friend dmatrix operator*(int scalar, const dmatrix&);
	
		private:
			double** rows;
			int height;
			int width;	
		public:
			dmatrix(const dmatrix&);
			dmatrix();
			dmatrix(int,int);
			~dmatrix();

			double* operator[](int) const;
			dmatrix operator*(int) const;

			dmatrix operator=(const dmatrix&);

			int getHeight() const;
			int getWidth() const;
			
			double dot(const dmatrix&) const;
			
			//Transpose			
			dmatrix T() const;
};

linear::dmatrix operator*(const linear::dmatrix&, const linear::dmatrix&);
linear::dmatrix operator*(const int, const linear::dmatrix&);
ostream& operator<<(ostream&,const dmatrix&);

}
#endif
