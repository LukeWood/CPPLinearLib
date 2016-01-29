#include "matrix.cpp"
#include <iostream>

using namespace linear;
using std::cout;
int main()
{
matrix m1(1,3);
cout<<m1;
m1 = m1.T();
cout<<m1;
return 0;
}
