#include <algorithm>
#include <iostream>

int N;
int T[1500001];
int P[1500001];
int DP[1500001];

int main()
{
    std::cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        std::cin >> T[i] >> P[i];
    }

    int max_profit = 0;
    for (int i = 1; i <= N; ++i)
    {
        // 현재까지의 최대 수익을 다음 날로 이월
        DP[i] = std::max(DP[i], DP[i - 1]);
        // 상담을 완료하는 날짜
        int next = i + T[i] - 1;
        // 상담이 가능한 경우
        if (next <= N)
        {
            DP[next] = std::max(DP[next], DP[i - 1] + P[i]);
        }
        max_profit = std::max(max_profit, DP[next]);
    }

    std::cout << max_profit << std::endl;
    return 0;
}
