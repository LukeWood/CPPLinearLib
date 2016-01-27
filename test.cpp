#include "matrix.h"
#include <iostream>

using namespace linear;
using std::cout;
int main()
{
matrix m1(2,2);
m1[1][0] = 0;
m1[0][1]=0;
m1[0][0]=0;
m1[1][1]=1;
matrix m2(2,2);
matrix m4 = m1*2;
cout<<m4;
}
