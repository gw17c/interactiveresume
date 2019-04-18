/**
    @mainpage Roman AUC Year System
 
    @author Gal Wolf
 
    @date February 15th, 2018
 */

#include <iostream>
#include <string>
#include <vector>
#include "roman.hpp"

std::string convertADInt_To_RomanAUC(int);
int convertRomanAUC_To_ADInt(std::string);

//constructor
Roman::Roman() {
   romanStr = "";
}

//string constructor
Roman::Roman(std::string s) {
   SetRoman(s);
}

//int constructor
Roman::Roman(int n) {
   SetRoman(n);
}


//destructor
Roman::~Roman() {
}


//declares the string
void Roman::SetRoman(std::string s) {
    romanStr = s;
}

//declares a year to Roman
void Roman::SetRoman(int n) {
    romanStr = convertADInt_To_RomanAUC(n-753);
}

//declares an AD year to Roman
void Roman::SetRomanWithAD(int n){
    romanStr = convertADInt_To_RomanAUC(n);
}

//returns Roman
std::string Roman::GetRoman() const{
    return romanStr;
}

//returns the year
int Roman::GetInt() const{
    if (romanStr.size()==0) 
      return 0;
    return convertRomanAUC_To_ADInt(romanStr)+753;
}

//returns the AD year
int Roman::GetAD() const{
    return convertRomanAUC_To_ADInt(romanStr);
}

//adds two Roman numerals together and returns the result
Roman& Roman::operator+=(const Roman& rn)
{ 
    Roman ro(romanStr);
    ro = ro.GetInt() + rn.GetInt();
    *this = ro.GetRoman();
    return *this;
}

//increment operator that adds 'n' to the year
Roman Roman::operator++(int n)
{
    if (n == 0)
        n = 1;
    Roman R=*this;
    *this = abs(R.GetInt() + n);
    if (R.GetInt() + n >= 3999)
        SetRoman(3999);
    if (R.GetInt() + n <= 1)
        SetRoman(1);
    return R;
}

//decrement operator that subtracts 'n' from the year
Roman Roman::operator--(int n)
{
    if (n == 0)
        n = 1;
    Roman R=*this;
    *this = abs(R.GetInt() - n);
    if (R.GetInt() - n >= 3999)
        SetRoman(3999);
    if (R.GetInt() - n <= 1)
        SetRoman(1);
    return R;
} 

//converts AD year to Roman Numeral
std::string convertADInt_To_RomanAUC(int n)
{
    std::string roman = "";
    int times, i;
    n += 753;
    
    if (n >= 1000)
    {
        times = n / 1000;
        for (i = 0; i < times; i++)
            roman += "M";
        n = n % 1000;
    }
    
    if (n >= 900)
    {
        roman += "CM";
        n = n % 900;
    }
    
    else if (n >= 500)
    {
        times = n / 500;
        for (i = 0; i < times; i++)
            roman += "D";
        n = n % 500;
    }
    
    if (n >= 400)
    {
        roman += "CD";
        n = n % 400;
    }
    
    else if (n >= 100)
    {
        times = n / 100;
        for (i = 0; i < times; i++)
            roman += "C";
        n = n % 100;
    }
    
    if (n >= 90)
    {
        roman += "XC";
        n = n % 90;
    }
    
    else if (n >= 50)
    {
        times = n / 50;
        for (i = 0; i < times; i++)
            roman += "L";
        n = n % 50;
    }
    
    if (n >= 40)
    {
        roman += "XL";
        n = n % 40;
    }
    
    else if (n >= 10)
    {
        times = n / 10;
        for (i = 0; i < times; i++)
            roman += "X";
        n = n % 10;
    }
    
    if (n >= 9)
    {
        roman += "IX";
        n = n % 9;
    }
    
    else if (n >= 5)
    {
        times = n / 5;
        for (i = 0; i < times; i++)
            roman += "V";
        n = n % 5;
    }
    
    if (n >= 4)
    {
        roman += "IV";
        n = n % 4;
    }
    
    else if (n >= 1)
    {
        times = n / 1;
        for (i = 0; i < times; i++)
            roman += "I";
        n = n % 1;
    }
    
    return roman;
    
}

//converts Roman Numeral to AD year
int convertRomanAUC_To_ADInt(std::string instr)
{
    int result = 0;
    const int len = instr.size();
    
    for (int i = 0; i < len; ++i)
    {
            if (instr[i] == 'I')
            {
                if (instr[i+1] == 'V')
                {
                    result += 4;
                    ++i;
                }
                else if (instr[i+1] == 'X')
                {
                    result += 9;
                    ++i;
                }
                else
                    result += 1;
            }
            else if (instr[i] == 'X')
            {
                if (instr[i+1] == 'L')
                {
                    result += 40;
                    ++i;
                }
                else if (instr[i+1] == 'C')
                {
                    result += 90;
                    ++i;
                }
                else
                    result += 10;
            }
            else if (instr[i] == 'C')
            {
                if (instr[i+1] == 'D')
                {
                    result += 400;
                    ++i;
                }
                else if (instr[i+1] == 'M')
                {
                    result += 900;
                    ++i;
                }
                else
                    result += 100;
            }
            else if (instr[i] == 'I')
                result += 1;
            else if (instr[i] == 'X')
                result += 10;
            else if (instr[i] == 'C')
                result += 100;
            else if (instr[i] == 'V')
                result += 5;
            else if (instr[i] == 'L')
                result += 50;
            else if (instr[i] == 'D')
                result += 500;
            else if (instr[i] == 'M')
                result += 1000;
    }
    
    result -= 753;
    return result;
    
}
