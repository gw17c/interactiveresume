/**
 * @brief Prints out count of most frequently occurring digit
 *       in a string (read from stdin).
 */

#include<iostream>
#include<string>

using namespace std;

int get_max_count(const string&);

int main()
{
    string str;
    
    while (cin >> str)
        cout << get_max_count(str) << "\n";
    
    return 0;
}

int get_max_count(const string & str)
{
    int count, max = 0;
    for (char j = '0'; j <= '9'; j++)
    {
        count = 0;
        for (unsigned int i = 0; i < str.length(); i++)
        {
            if (str[i] == j)
            {
                count++;
            }
        }
        if(count > max)
        {
            max = count;
        }
    }
    return max;
    
}

