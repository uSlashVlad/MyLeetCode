#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> st1, st2;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '#')
                st1.push(s[i]);
            else if (!st1.empty())
                st1.pop();
        }

        for (int i = 0; i < t.length(); i++)
        {
            if (t[i] != '#')
                st2.push(t[i]);
            else if (!st2.empty())
                st2.pop();
        }

        return st1 == st2;
    }
};
