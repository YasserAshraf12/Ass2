#include <iostream>
#include "Matrix.h"
#include<cmath>
#include<string>
#include<cstring>
#include<sstream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;
ostream & operator << (ostream& out, const BigDecimalInt& aa)
{
    for(int i =0; i < aa.counter; i++)
    {
        out << aa.vec[i];
    }
    return out;
}
//------------------------------------------------------------
istream& operator >> (istream& in, BigDecimalInt& bb)
{
    for(int i =0; i < bb.counter; i++)
    {
        in >> bb.vec[i];
    }
    return in;
}
//-----------------------------------------------------------
int main()
{
    //test case: - + + < 8alat feha moshkila ba2i sa7

    BigDecimalInt num1("-11111111111111112222");
    BigDecimalInt num2("11111111111111115555");
    cout << num1 + num2 <<endl;
    return 0;
}
//--------------------------------------------
