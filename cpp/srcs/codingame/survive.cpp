#include <iostream>
using namespace std;

int main()
{
    int f, p, e, s;
    cin >> f >> p >> e >> s;

    // 총 일일 식량 소비량과 순일일 식량 변화량 계산
    int total_daily_consumption = s * p;
    int net_daily_change = e - total_daily_consumption;

    // 순일일 변화량이 음수가 아닌 경우, 생존은 '영원'입니다.
    if (net_daily_change >= 0)
    {
        cout << "영원" << endl;
    }
    else
    {
        // 식량이 모두 소진되기까지의 날짜 계산
        int days = f / -net_daily_change; // 명확성을 위해 음수인 net_daily_change를 사용합니다.
        cout << days << endl;
    }

    return 0;
}
