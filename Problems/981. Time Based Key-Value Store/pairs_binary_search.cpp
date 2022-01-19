#include "../includes.hpp"
using namespace std;

class TimeMap
{
public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        items[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp)
    {
        auto &pairs = items[key];
        string result = "";
        int l = 0;
        int r = pairs.size() - 1;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            auto guess = pairs[mid];
            if (guess.second <= timestamp)
            {
                result = guess.first;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return result;
    }

private:
    map<string, vector<pair<string, int>>> items;
};

int main()
{
    TimeMap tm;
    tm.set("love", "high", 10);
    tm.set("love", "low", 20);
    cout << tm.get("love", 5) << endl;
    cout << tm.get("love", 10) << endl;
    cout << tm.get("love", 15) << endl;
    cout << tm.get("love", 20) << endl;
    cout << tm.get("love", 25) << endl;
}
