#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t low = 1;
        uint32_t high = pow(2, 31);

        while (low < high)
        {
            uint32_t nL = n & low, nH = n & high;
            if ((nL + nH > 0) && (nL == 0 || nH == 0))
                n ^= low | high;

            low <<= 1;
            high >>= 1;
        }

        return n;
    }
};
