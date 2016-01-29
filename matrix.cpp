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
			if(j!=toprint.getWidth()-1)
			{
				stream<<toprint[i][j]<<" ";
			}
			else
			{
				stream<<toprint[i][j];
			}
		}
		if(i!=toprint.getHeight()-1)
		{
		stream<<"\n ";
		}
	}
	stream<<"]\n";
	return stream;
}

matrix linear::operator*(int scalar, const matrix& tomult)
{
	matrix m(tomult);
	for(int i = 0; i < m.getHeight(); i++)
	{
		for(int j = 0; j < m.getWidth(); j++)
		{
			m[i][j] = m[i][j] * scalar;
		}
	}
	return m;
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
		for( int j = 0; j < iwidth; j++)
		{
			rows[i][j] = 0;
		}
	}
}

matrix::matrix()
{
	width = 1;
	height = 1;
	rows = new int*[1];
	rows[0] = new int[1];
	rows[0][0] = 0;
}

matrix::matrix(const matrix& copyFrom)
{
	height = copyFrom.getHeight();
	width = copyFrom.getWidth();
	rows = new int*[height];
	for(int i = 0; i < height; i++)
	{
		rows[i] = new int[width];
		for(int j = 0; j < width; j++)
		{
			rows[i][j] = copyFrom[i][j];
		}
	}
}

matrix matrix::operator=(const matrix& copyFrom)
{
	for(int i = 0; i < copyFrom.getHeight(); i++)
	{
		delete[] rows[i];
	}
	delete[] rows;
	height = copyFrom.getHeight();
	width = copyFrom.getWidth();
	rows = new int*[height];
	for(int i = 0; i < height; i++)
	{
		rows[i] = new int[width];
		for(int j = 0; j < copyFrom.getWidth(); j++)
		{
			rows[i][j] = copyFrom[i][j];
		}
	}
	return *this;
}

matrix::~matrix()
{
for(int i = 0; i < height; i++)
{
		delete[] rows[i];
}
delete[] rows;
}

matrix matrix::T() const
{
	matrix m(width, height);
	for(int i =0; i < height; i++)
	{
		for(int j =0; j< width; j++)
		{
			m[j][i] = rows[i][j];
		}
	}
	return m;
}

int matrix::dot(const matrix& other) const
{
	if(height == other.getHeight() && width == other.getWidth())
	{
		int dotProd = 0;
		for(int i = 0; i< height; i++)
		{
			for(int j = 0; j < width; j++)
			{
				dotProd += (rows[i][j] * other[i][j]);
			}
		}
		return dotProd;
	}
	return -1;
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
				sum = sum + (first[i][k]*second[k][j]);
			}
			m[i][j] = sum;
		}
	}
	return m;
}
matrix linear::matrix::operator*(int scalar) const
{
	matrix m(height,width);
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			m[i][j] = rows[i][j] * scalar;
		}
	}
	return m;
}

int* linear::matrix::operator[](int index) const
{
	return rows[index];
}
