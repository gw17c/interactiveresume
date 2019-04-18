/**
 * @brief Example driver program for class Roman
 */

#include <iostream>
#include "roman.hpp"

int main () {
    Roman p;
    Roman s(1900);
    std::cout << "Roman for the number 1900: " << s.GetRoman() << std::endl; //MCM

    Roman q("MCMXCV");
    std::cout << q.GetInt() << std::endl; //1995
    q--; 
    std::cout << q.GetInt() << std::endl; //1994
    std::cout << q.GetRoman() << std::endl; //MCMXCIV
    q.operator--(2); 
    std::cout << q.GetInt() << std::endl; //1992

    Roman r("MCM");
    std::cout << r.GetInt() << std::endl; //1900
    r.operator++(7); 
    std::cout << r.GetInt() << std::endl; //1907
    r++;
    std::cout << r.GetInt() << std::endl; //1908
    std::cout << r.GetRoman() << std::endl; //MCMVIII
    std::cout << r.GetAD() << std::endl; //1155
    r.operator++(4000); 
    std::cout << r.GetInt() << std::endl; //3999
    r.operator++(-4000);
    std::cout << r.GetInt() << std::endl; //1

    Roman t;
    t.SetRomanWithAD(1155); 
    std::cout << t.GetRoman() << std::endl; //MCMVIII
    std::cout << t++.GetRoman().length() << std::endl; //7
    std::cout << t.GetRoman().length() << std::endl; //5, for "MCMIX"

    p.SetRoman("VII");
    std::cout << p.GetInt() << std::endl; //7
    Roman k("III");
    p+=k;
    std::cout << p.GetInt() << std::endl; //10
    std::cout << p.GetRoman() << std::endl; //X

    return 0;   
}

