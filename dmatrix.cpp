#include "dmatrix.h"
#include <ostream>
using linear::dmatrix;
using std::ostream;
ostream& linear::operator<<(ostream& stream, const dmatrix& toprint)
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

dmatrix linear::operator*(int scalar, const dmatrix& tomult)
{
	dmatrix m(tomult);
	for(int i = 0; i < m.getHeight(); i++)
	{
		for(int j = 0; j < m.getWidth(); j++)
		{
			m[i][j] = m[i][j] * scalar;
		}
	}
	return m;
}

int dmatrix::getHeight() const
{
	return height;
}
int dmatrix::getWidth() const
{
	return width;
}

dmatrix::dmatrix(int iheight, int iwidth)
{
	height = iheight;
	width = iwidth;
	rows = new double*[iheight];
	for(int i=0; i < iheight; i++)
	{
		rows[i] = new double[iwidth];
		for( int j = 0; j < iwidth; j++)
		{
			rows[i][j] = 0;
		}
	}
}

dmatrix::dmatrix()
{
	width = 1;
	height = 1;
	rows = new double*[1];
	rows[0] = new double[1];
	rows[0][0] = 0;
}

dmatrix::dmatrix(const dmatrix& copyFrom)
{
	height = copyFrom.getHeight();
	width = copyFrom.getWidth();
	rows = new double*[height];
	for(int i = 0; i < height; i++)
	{
		rows[i] = new double[width];
		for(int j = 0; j < width; j++)
		{
			rows[i][j] = copyFrom[i][j];
		}
	}
}

dmatrix dmatrix::operator=(const dmatrix& copyFrom)
{
	for(int i = 0; i < copyFrom.getHeight(); i++)
	{
		delete[] rows[i];
	}
	delete[] rows;
	height = copyFrom.getHeight();
	width = copyFrom.getWidth();
	rows = new double*[height];
	for(int i = 0; i < height; i++)
	{
		rows[i] = new double[width];
		for(int j = 0; j < copyFrom.getWidth(); j++)
		{
			rows[i][j] = copyFrom[i][j];
		}
	}
	return *this;
}

dmatrix::~dmatrix()
{
for(int i = 0; i < height; i++)
{
		delete[] rows[i];
}
delete[] rows;
}

dmatrix dmatrix::T() const
{
	dmatrix m(width, height);
	for(int i =0; i < height; i++)
	{
		for(int j =0; j< width; j++)
		{
			m[j][i] = rows[i][j];
		}
	}
	return m;
}

double dmatrix::dot(const dmatrix& other) const
{
	if(height == other.getHeight() && width == other.getWidth())
	{
		double dotProd = 0;
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

dmatrix linear::operator*(const dmatrix& first,const dmatrix& second)
{
	if(first.getWidth() != second.getHeight())
	{
		dmatrix m(1,1);
		m[0][0] = 0;
		return m;
	}
	dmatrix m(first.getHeight(),second.getWidth());
	for(int i = 0; i < first.getHeight(); i++)
	{
		for(int j = 0; j < second.getWidth(); j++)
		{
			double sum = 0;
			for(int k = 0; k < second.getHeight(); k++)
			{
				sum = sum + (first[i][k]*second[k][j]);
			}
			m[i][j] = sum;
		}
	}
	return m;
}
dmatrix linear::dmatrix::operator*(int scalar) const
{
	dmatrix m(height,width);
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			m[i][j] = rows[i][j] * scalar;
		}
	}
	return m;
}

double* linear::dmatrix::operator[](int index) const
{
	return rows[index];
}
