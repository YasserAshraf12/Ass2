#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include<vector>
#include<stdio.h>
//----------------------------------------------
class BigDecimalInt
{
    friend std::ostream& operator <<(std::ostream& out, const BigDecimalInt& aa);
    friend std::istream& operator >>(std::istream& in, BigDecimalInt& bb);
private:
    std::string decStr; // input string from user
    int decInt;
	bool Negative;
public:
    int counter; // length of string
    std::vector<int>vec;
    BigDecimalInt();
    BigDecimalInt(std::vector<int>);
    BigDecimalInt(const BigDecimalInt& cc);
    BigDecimalInt(std::string);
    BigDecimalInt(int);
    BigDecimalInt operator+(BigDecimalInt&);
    BigDecimalInt operator-(BigDecimalInt&);
    std::vector<int>sum(std::vector<int>mm, std::vector<int>bb);
    std::vector<int>subtract(std::vector<int>s, std::vector<int>d);
    void check_isBigger(std::vector<int>&,std::vector<int>&);
    void check_Big(std::vector<int>& , std::vector<int>&);
    void if_minus(std::vector<int>& , std::vector<int>&);
    //---------------------------------------------------------------
};
#endif
