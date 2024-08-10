#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> filterSincere(const vector<string> &entries, int length, int a, int b)
{
    vector<string> sincere;

    for (const string &entry : entries)
    {
        size_t pos = 0;
        size_t prev = 0;

        pos = entry.find(' ', prev);
        string fruit = entry.substr(prev, pos - prev);
        prev = pos + 1;

        pos = entry.find(' ', prev);
        string startTimeStr = entry.substr(prev, pos - prev);
        prev = pos + 1;

        pos = entry.find(' ', prev);
        string endTimeStr = entry.substr(prev, pos - prev);
        prev = pos + 1;

        int score = stoi(entry.substr(prev));

        int startHour, startMinute, endHour, endMinute;
        sscanf(startTimeStr.c_str(), "%d:%d", &startHour, &startMinute);
        sscanf(endTimeStr.c_str(), "%d:%d", &endHour, &endMinute);

        int startTimeMinutes = startHour * 60 + startMinute;
        int endTimeMinutes = endHour * 60 + endMinute;
        int actualDuration = endTimeMinutes - startTimeMinutes;

        // 성실성 판단
        if (abs(actualDuration - length) <= a && score >= b)
        {
            sincere.push_back(fruit);
        }
    }

    return sincere;
}

int main()
{
    vector<string> test = {"apple 12:00 15:00 180", "banana 15:32 17:32 45", "cherry 09:15 11:45 30",
                           "date 08:00 11:00 20", "elderberry 10:00 13:00 50"};

    int length = 180;
    int a = 10;
    int b = 50;

    vector<string> sincereList = filterSincere(test, length, a, b);

    for (const string &name : sincereList)
    {
        cout << name << " is sincere." << endl;
    }

    return 0;
}
