#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() == 0)
            return true;
        if (s1.length() > s2.length())
            return false;

        vector<short int> s1Chars(128, 0);
        stringToVector(s1Chars, s1);
        vector<short int> windowChars(128, 0);
        string substr = s2.substr(0, s1.length());
        stringToVector(windowChars, substr);
        if (s1Chars == windowChars)
            return true;

        for (int i = s1.length(); i < s2.length(); i++)
        {
            windowChars[s2[i - s1.length()]]--;
            windowChars[s2[i]]++;
            if (s1Chars == windowChars)
                return true;
        }

        return false;
    }

    void stringToVector(vector<short int> &vec, string &str)
    {
        for (char ch : str)
        {
            vec[ch]++;
        }
    }
};

int main()
{
    Solution s;
    s.checkInclusion("ab", "eidbaooo");
    s.checkInclusion("adc", "dcda");
}
