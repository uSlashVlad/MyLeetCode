#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int i = 0;
        int j = 1;

        while (j < s.length())
        {
            if (s[j] != ' ')
            {
                j++;
            }
            else
            {
                reverseSubstring(s, i, j - 1);
                i = j + 1;
                j += 2;
            }
        }
        reverseSubstring(s, i, j - 1);

        return s;
    }

    void reverseSubstring(string &str, int start, int end)
    {
        while (start < end)
        {
            swap(str[start], str[end]);
            start++;
            end--;
        }
    }
};
