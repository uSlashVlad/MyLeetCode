#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int sum = 0;
        short int prev = 9999;
        int length = s.size();
        for (int i = 0; i < length; i++)
        {
            short int digit = rDigit(s[i]);
            if (prev >= digit)
            {
                sum += digit;
            }
            else
            {
                // prev x2 here because in such case digit was already added to sum
                sum += digit - prev * 2;
            }
            prev = digit;
        }
        return sum;
    }

    short int rDigit(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }
};
