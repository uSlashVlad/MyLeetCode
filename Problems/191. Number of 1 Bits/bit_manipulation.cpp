#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n > 0)
        {
            count += n & 1;
            n >>= 1;
        }

        return count;
    }
};

int main()
{
    Solution s;
    int smth = s.hammingWeight(0b00000000000000000000000000001011);
    cout << smth;
}
