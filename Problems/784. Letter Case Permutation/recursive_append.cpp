#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    vector<string> letterCasePermutation(string s)
    {
        vector<string> result;

        int i = 0;
        while (i < s.size() && isDigit(s[i]))
            i++;

        if (i < s.size())
        {
            auto str1 = s.substr(0, i + 1);
            auto str2 = s.substr(0, i) + flipLetter(s[i]);
            auto subResults = letterCasePermutation(s.substr(i + 1, s.size() - (i + 1)));
            for (auto str3 : subResults)
            {
                result.push_back(str1 + str3);
                result.push_back(str2 + str3);
            }
        }
        else
        {
            return {s};
        }

        return result;
    }

    bool isDigit(char ch)
    {
        return ch > 47 && ch < 58;
    }

    char flipLetter(char ch)
    {
        return isLetterCapital(ch) ? ch + 32 : ch - 32;
    }

    bool isLetterCapital(char ch)
    {
        return ch > 64 && ch < 91;
    }
};

int main()
{
    Solution s;
    s.letterCasePermutation("3z4");
}

// a1b2
// s = "a1b2", i = 0, str1 = "A", subResults =
//   s = "1b2", i = 1, str1 = "1B", subResults =
//     s = "2", i = 1
//     => ["2"]
//   = ["2"]
//   => ["1b2", "1B2"]
// = ["1b2", "1B2"]
// => ["a1b2", "a1B2", "A1b2", "A1B2"]
