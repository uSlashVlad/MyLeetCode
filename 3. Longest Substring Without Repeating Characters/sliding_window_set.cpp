#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<char> window; // Actually it is a set of chars
        int start = 0;
        int result = 0;

        for (int i = 0; i < s.length();)
        {
            if (charNotExists(window, s[i]))
            {
                window.push_back(s[i]);
                i++;
                result = max(result, i - start);
            }
            else
            {
                window.erase(window.begin());
                start++;
            }
        }

        return result;
    }

    bool charNotExists(vector<char> &vec, char ch)
    {
        for (char vecCh : vec)
        {
            if (vecCh == ch)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    s.lengthOfLongestSubstring("ynyo");
}
