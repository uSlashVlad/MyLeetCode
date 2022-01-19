#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int strLength = haystack.length();
        int prtLength = needle.length();

        for (int i = 0; i <= strLength - prtLength; i++)
        {
            int j = 0;
            for (; j < prtLength; j++)
            {
                if (haystack[i + j] != needle[j])
                    break;
            }
            if (j == prtLength)
                return i;
        }

        return -1;
    }
};
