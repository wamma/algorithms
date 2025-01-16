#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<string> friends, vector<string> gifts)
{
    unordered_map<string, int> giftCount;      // 선물 주고받은 횟수 추적
    unordered_map<string, int> giftIndex;      // 각 친구의 선물 지수
    unordered_map<string, int> nextMonthGifts; // 다음 달에 받을 선물 수

    for (const auto &record : gifts)
    {
        auto pos = record.find(' ');
        string giver = record.substr(0, pos);
        string receiver = record.substr(pos + 1);

        giftCount[giver + "_" + receiver]++;
    }
}

int main()
{
    vector<string> friends = {"muzi", "ryan", "frodo", "neo"};
    vector<string> gifts = {"muzi frodo", "muzi frodo", "ryan muzi",  "ryan muzi",
                            "ryan muzi",  "frodo muzi", "frodo ryan", "neo muzi"};
    int maxCount = solution(friends, gifts);
    cout << maxCount << '\n';
    return 0;
}