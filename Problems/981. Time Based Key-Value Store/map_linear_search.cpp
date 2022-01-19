#include "../includes.hpp"
using namespace std;

struct MapItem
{
    map<int, string> m{{0, ""}};

    void set(int timestamp, string value)
    {
        m[timestamp] = value;
    }

    string get(int timestamp)
    {
        string result;
        for (auto item : m)
        {
            if (item.first <= timestamp)
                result = item.second;
            else
                break;
        }
        return result;
    }
};

class TimeMap
{
public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        m[key].set(timestamp, value);
    }

    string get(string key, int timestamp)
    {
        return m[key].get(timestamp);
    }

private:
    map<string, MapItem> m;
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
