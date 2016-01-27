#include "matrix.h"
#include <iostream>
using namespace neuralnets;
std::ostream &operator<<(std::ostream& stream, matrix& toprint)
{
	for(int i = 0; i < toprint.height; i++)
	{
		for(int j = 0; j < toprint.width; j++)
		{
			stream<<toprint[i][j];
		}
		stream<<"\n";
	}
	return stream;
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

matrix matrix::operator=(const matrix& copyFrom)
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

matrix operator*( matrix& first, matrix& second)
{
	if(first.width != second.height)
	{
		matrix m(1,1);
		m[0][0] = 0;
		return m;
	}
	
}

int* matrix::operator [](int index)
{
	return rows[index];
}
