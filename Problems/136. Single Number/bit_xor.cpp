#include "../includes.hpp"
using namespace std;

// XOR magic with flipping bits, 2 identical numbers will result 0, so only
// single number will be the final result

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0;

        for (int n : nums)
            result ^= n;

        return result;
    }
};
