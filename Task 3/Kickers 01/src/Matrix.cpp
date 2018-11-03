#include "Matrix.h"
#include<string>
#include<cstring>
#include<sstream>
#include<iostream>
#include<vector>
#include<algorithm>
#include <iterator>
#include<stdio.h>
#include<cmath>
#include<numeric>
#include<functional>
//-------------------------------------
int counter = 0;
//-------------------------------
BigDecimalInt::BigDecimalInt()
{
    decStr="";
    decInt=0;
    counter=0;
}
BigDecimalInt::BigDecimalInt(const BigDecimalInt& cc)
{
    this->decStr = cc.decStr;
    this->decInt = cc.decInt;
	this->Negative = false;// this is only just an assumption
}
//----------------------------------------
BigDecimalInt::BigDecimalInt(std::string decStr)
{
    this->counter = decStr.length();
	int i = 0;
	if (decStr[0] == '-') {
		Negative = true;
		i = 1;
	}
	else
		Negative = false;
    this->decStr = decStr;
    for(i; i < this->counter; i++)
    {
        int l = (int)(decStr[i]- '0'); // conversion to integer
        vec.push_back(l);
    }
}
//-----------------------------------------------------
BigDecimalInt::BigDecimalInt(std::vector<int> v)
{
    std::copy(v.begin(),v.end(),back_inserter(this->vec));
    this->decInt=0;
    this->counter=v.size();
    this->decStr="";
	this->Negative = false; //just assumption

}
//---------------------------------------------
BigDecimalInt BigDecimalInt::operator+(BigDecimalInt& dec)
{
	std::vector<int> result = sum(this->vec, dec.vec);
	int m = 1;
	if ((this->Negative == true)&&( dec.Negative==true))
		result[0] *= -1;
	else if ((this->Negative == true) && (dec.Negative == false)) {
		if (abs((stod(this->decStr)))>(abs(stod(dec.decStr)))){
			m=-1;
            result = subtract(this->vec, dec.vec);
            result[0] *= m;
		}
		else{
            result = subtract(this->vec , dec.vec);
		}
	}
	else if ((this->Negative == false) && (dec.Negative == true)) {
		if (abs((stod(dec.decStr)))>(abs(stod(this->decStr)))){
			m = -1;
            result = subtract(this->vec, dec.vec);
            result[0] *= m;
		}
		else{
            result = subtract(dec.vec, this->vec);
		}
	}
    return BigDecimalInt(result);
}
//-----------------------------------------------------
std::vector<int> BigDecimalInt::sum(std::vector<int>vec, std::vector<int>vec3)
{
    std::vector<int>finalVec;
    check_isBigger(vec , vec3);
    int carry = 0;
    int p = vec.size();
    int u=0;
    for(int i = p-1; i >= 0; i--)
    {
        u= vec[i] + vec3[i]+carry;
        if( u >= 10)
        {
            carry = 1;
            finalVec.push_back((u % 10));
            if(i == 0 && carry ==1)
            {
                finalVec.push_back((u/10)%10);
            }
        }
        else{
            finalVec.push_back(u);
            carry = 0;
        }
    }
    std::reverse(finalVec.begin(), finalVec.end());
    return finalVec;
}
//---------------------------------------------------------------------------
void BigDecimalInt::check_isBigger(std::vector<int>&vec, std::vector<int>&vec3)
{
    int a = vec.size();
    int b = vec3.size();
    if (a > b)
    {
        std::reverse(vec3.begin(), vec3.end());
        int z = a - b;
        for(int i = 0; i < z; i++)
        {
            vec3.push_back(0);
        }
        std::reverse(vec3.begin(), vec3.end());
    }
    else{
        std::reverse(vec.begin(), vec.end());
        int z = b - a;
        for(int i = 0; i < z; i++)
        {
            vec.push_back(0);
        }
    std::reverse(vec.begin(), vec.end());
    }
}
//--------------------------------------------------------------------
BigDecimalInt BigDecimalInt:: operator-(BigDecimalInt& dec)
{
    std::vector<int> result = subtract(this->vec ,dec.vec);
    int m = -1;
    if((this->Negative == true) && (dec.Negative == true))
        result[0] *=m;
    else if((this->Negative == true) && (dec.Negative == false))
    {
        if((abs(stod(this->decStr))) > (abs(stod(dec.decStr))))
        {
            result = sum(dec.vec, this->vec);
            result[0] *=m;
        }
        else{
            result = sum(this->vec, dec.vec);
            result[0] *=m;
        }
    }
    else if((this->Negative == false) && (dec.Negative == true))
    {
        if((abs(stod(this->decStr))) > (abs(stod(dec.decStr))))
        {
            result = sum(dec.vec , this->vec);
        }
        else{
            result = sum(this->vec, dec.vec);
        }
    }
    return BigDecimalInt(result);
}
//------------------------------------------------------------------
std::vector<int> BigDecimalInt::subtract(std::vector<int>vec, std::vector<int>vec3)
{
    std::vector<int>finalVec;
    check_isBigger(vec , vec3);
    check_Big(vec , vec3);
    int k = vec.size();
    int  sub = 0;
    int carry = 0;
    for(int i = k-1; i >= 0; i--)
    {
        sub = vec[i] - vec3[i] -carry;
        if( sub < 0)
        {
            carry = 1;
            sub = sub + 10;
            finalVec.push_back(sub);
        }
        else{
            carry = 0;
            finalVec.push_back(sub);
        }
    }
    std::reverse(finalVec.begin(), finalVec.end());
    return finalVec;
}
//--------------------------------------------------------------
void BigDecimalInt::check_Big(std::vector<int>&vec , std::vector<int>&vec3)
{
    check_isBigger(vec, vec3);
	if (this->Negative == true)
		return;
    for(int i = 0; i < counter; i++)
    {
        if(vec[i] < vec3[i])
        {
            vec.swap(vec3);
            break;
        }
        else if (vec[i] == vec3[i] && vec[i+1] < vec3[i+1]){
            vec.swap(vec3);
            break;
        }
        else{
            continue;
        }
    }
}
//----------------------------------------------

