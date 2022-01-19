#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        int length = 0;
        int digits[10];

        while (x > 0)
        {
            digits[length] = x % 10;
            x /= 10;
            length++;
        }

        for (int i = 0; i < length; i++)
        {
            int reverse_index = length - i - 1;
            if (digits[i] != digits[reverse_index])
                return false;
        }
        return true;
    }
};
