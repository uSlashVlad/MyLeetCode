#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        map<char, short int> s1Map = stringToMap(s1);
        int endOfStr = s2.length() - s1.length();
        for (int i = 0; i <= endOfStr; i++)
        {
            string substr = s2.substr(i, s1.length());
            if (s1Map == stringToMap(substr))
                return true;
        }
        return false;
    }

    map<char, short int> stringToMap(string &str)
    {
        map<char, short int> result;
        for (char ch : str)
            result[ch]++;
        return result;
    }
};
