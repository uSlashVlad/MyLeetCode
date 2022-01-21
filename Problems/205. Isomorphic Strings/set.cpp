#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        map<char, char> mapping;
        map<char, char> rMapping;

        for (int i = 0; i < s.length(); i++)
        {
            char c1 = s[i];
            char c2 = t[i];
            if (mapping.count(c1) > 0 && mapping[c1] != c2 ||
                rMapping.count(c2) > 0 && rMapping[c2] != c1)
                return false;
            mapping[c1] = c2;
            rMapping[c2] = c1;
        }

        return true;
    }
};
