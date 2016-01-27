#include "matrix.h"
#include <ostream>
using linear::matrix;
using std::ostream;
ostream& linear::operator<<(ostream& stream, const matrix& toprint)
{
	stream<<"[";
	for(int i = 0; i < toprint.getHeight(); i++)
	{
		for(int j = 0; j < toprint.getWidth(); j++)
		{
			stream<<toprint[i][j]<<" ";
		}
		if(i!=toprint.getHeight()-1)
		{
		stream<<"\n ";
		}
	}
	stream<<"]\n";
	return stream;
}

int matrix::getHeight() const
{
	return height;
}
int matrix::getWidth() const
{
	return width;
}

matrix::matrix(int iheight, int iwidth)
{
	height = iheight;
	width = iwidth;
	rows = new int*[iheight];
	for(int i=0; i < iheight; i++)
	{
		rows[i] = new int[iwidth];
	}
}

matrix::matrix(const matrix& copyFrom)
{
height = copyFrom.height;
width = copyFrom.width;
rows = new int*[height];
for(int i = 0; i < height; i++)
{
	rows[i] = new int[width];
	for(int j = 0; j < width; j++)
	{
		rows[i][j] = copyFrom.rows[i][j];
	}
}
}

matrix linear::operator*(const matrix& first,const matrix& second)
{
	if(first.getWidth() != second.getHeight())
	{
		matrix m(1,1);
		m[0][0] = 0;
		return m;
	}
	matrix m(first.getHeight(),second.getWidth());
	for(int i = 0; i < first.getHeight(); i++)
	{
		for(int j = 0; j < second.getWidth(); j++)
		{
			int sum = 0;
			for(int k = 0; k < second.getHeight(); k++)
			{
			sum = sum + (first[i][k]*second[j][k]);
			}
			m[i][j] = sum;
		}
	}
	return m;
}

int* linear::matrix::operator[](int index) const
{
	return rows[index];
}
