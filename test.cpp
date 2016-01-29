#include "dmatrix.cpp"
#include <iostream>

using namespace linear;
using std::cout;
int main()
{
dmatrix m1(2,1);
m1[0][0] = .01;
m1[1][0] = .123;
dmatrix m2(1,2);
m2[0][0]=2;
m2[0][1]=3;
cout<<m1;
cout<<m2;
cout<<m1*m2;
}
