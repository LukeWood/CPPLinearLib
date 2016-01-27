#include "matrix.h"
#include <iostream>

using namespace linear;
using std::cout;
int main()
{
matrix m1(2,1);
m1[0][0] = 1;
m1[1][0] = 1;
matrix m2(2,1);
m2[0][0]=2;
m2[1][0]=3;
cout<<m1;
cout<<m2;
cout<<m1.dot(m2);
}
