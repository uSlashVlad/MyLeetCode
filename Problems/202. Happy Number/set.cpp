#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        set<int> numbers;
        
        while (n != 1)
        {
            int newN = 0;
            while (n > 0)
            {
                int lastDigit = n % 10;
                newN += lastDigit * lastDigit;
                n /= 10;
            }
            if (numbers.count(newN) == 1)
                return false;

            n = newN;
            numbers.insert(newN);
        }

        return true;
    }
};
