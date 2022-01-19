#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        unordered_map<string, int> combinations;

        int length = strs.size();

        for (string str : strs)
        {
            for (int i = str.length(); i > 0; i--)
            {
                str.resize(i);
                combinations[str]++;
            }
        }

        string result = "";

        for (auto pair : combinations)
        {
            if (pair.second == length && pair.first.length() > result.length())
            {
                result = pair.first;
            }
        }

        return result;
    }
};
