/* Name: Gal Wolf
 Date: November 2nd, 2017
 Section: 0014
 Assignment: Homework 4 part 4
 Due Date: November 1st
 About this project: Simple calculator.
 Assumptions: Assumes the program will ask for numbers and operations and return the evaluated total. Assumes when a "?" is inputed, the program will output the result.
 
 All work below was performed by Gal Wolf */

#include<iostream>
#include<cmath>

using namespace std;

int add(int x, int y);
int sub(int x, int y);
int mult(int x, int y);
int divi(int x, int y);
int mod(int x, int y);
void evaluate(int x, char op);

int main()
{
    int x;
    char op;
    cout << "Enter the expression: \n";
    cin >> x;
    cin >> op;
    //reads in the numbers and operators until "?" is inputed
    while (!(op == '?'))
    {
        cin >> x;
        cin >> op;
    }
    //calls the evaluate function
    evaluate(x, op);
    //prints the result
    cout << "The result is " << endl;
    for (int i = 0; i < x; i++)
    {
        cout << x << endl;
    }
}

int add(int a, int b) //simple addition function
{
    int c = a + b;
    return c;
}

int sub(int c, int d) //simple subtraction function
{
    int e = c - d;
    return e;
}

int mult(int e, int f) //simple multiplication function
{
    int g = e * f;
    return g;
}

int divi(int g, int h) //simple division function
{
    int i = g / h;
    return i;
}

int mod(int i, int j) //simple modulus function
{
    int k = i % j;
    return k;
}

void evaluate(int x, char op)
{
    int result = 1, a, b, c, d, e;
    
    //loops the input of the user
    for (int i = 0; i < result; i++)
    {
        //if-else if statements for each operation entered
        while (op != '?')
        {
            if (op == '+')
            {
                a = add(x, x);
            }
            else if (op == '-')
            {
                b = sub(x, x);
            }
            else if (op == '*')
            {
                c = mult(x, x);
            }
            else if (op == '/')
            {
                d = divi(x, x);
            }
            else if (op == '%')
            {
                e = mod(x, x);
            }
        }
        //reads in the result
        for (int i = 0; i < result; i++)
        {
            x += a;
            x -= b;
            x *= c;
            x /= d;
            x %= e;
        }
    }
    
}
