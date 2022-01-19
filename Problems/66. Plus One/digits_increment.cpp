#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int i = digits.size() - 1;

        digits[i]++;
        while (digits[i] == 10 && i > 0)
        {
            digits[i--] = 0;
            digits[i]++;
        }
        if (i == 0 && digits[0] == 10)
        {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
