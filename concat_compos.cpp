/** 
    @mainpage Concat Composites

    @author Gal Wolf

    Program to slice a string formed after concatenating the first
    k composite numbers.
*/

/** \file concat_compos.cpp
    \brief Main program that, given a number n, returns a substring
    of the string formed by concatenating the first k composite numbers.

    The program accepts a number n from stdin provided by a user.
    Then, the program takes the first few composite numbers, 
    converts them to strings and concatenates them to get a string, say concat_compos 
    of length 1000.  

    Finally, the program prints the first 5 characters of concat_compos 
    starting at index n.  
    
    For example, the first few prime numbers are 4, 6, 8, 9, 10, 12, 14...  
    Thus, concat_compos = "4689101214...". If the user provides n = 3,
    the program should print 91012.

    Requires: C++11
*/

#include<iostream>
#include<string>
#include<sstream>

/** \brief Returns a string of length 1000 formed after concatenating
    the first k composite numbers.

    @return std::string
*/

std::string get_concatenated_compos()
{
    std::string concat_compos, str;
    std::stringstream s1;
    
    int i, j, f;
    
    for (i = 2; i <= 1000; i++)
    {
        for (j = 1; j < i; j++)
        {
            if (i % j == 0)
                f = j;
        }
        if (f > 1)
        {
            s1 << i;
            concat_compos = s1.str();
        }
    }
    concat_compos.resize(1000);
    return concat_compos;
}

/** \brief Return a slice of a string of length 5 beginning at the
    given index.

    @param compos is a string
    @param index is an integer
    @return std::string
*/

std::string get_slice_of_5(const std::string & compos, const int index)
{
    std:: string concat_compos (compos, index, 5);
    
    return concat_compos;
}

/** \brief Program entry point

    The program starts execution from here. It accepts integer input
    from the user until the EOF is reached or when the user terminates
    the program.
*/

int main()
{
    int n;
    std::string concat_compos;

    while(std::cin >> n)
    {
        concat_compos = get_concatenated_compos();
        std::cout << get_slice_of_5(concat_compos, n) << std::endl;
    }

    return 0;
}
