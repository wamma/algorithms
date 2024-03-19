#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M, B; //N: 세로, M: 가로, B: 높이
    std::cin >> N >> M >> B;
    std::vector<std::vector<int> > ground(N, std::vector<int>(M));
    int minHeight = 256, maxHeight = 0;
    for(int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            std::cin >> ground[i][j];
            minHeight = std::min(minHeight, ground[i][j]);
            maxHeight = std::max(maxHeight, ground[i][j]);
        }
    }

    int resultTime = INT_MAX, resultHeight = -1;

    // 모든 가능한 높이에 대해 시도
    for(int h = minHeight; h <= maxHeight + B; ++h)
    {
        int build = 0, remove = 0;

        // 현재 높이로 맞추기 위한 추가/제거 작업 계산
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                int diff = ground[i][j] - h;
                if (diff > 0) // 블록 제거
                    remove += diff;
                else if (diff <0) // 블록 추가
                    build -= diff;
            }
        }

        // 인벤토리에 있는 블록과 작업 가능 여부 확인
        if (build <= remove + B)
        {
            int time = remove * 2 + build;
            if (time < resultTime || (time == resultTime && h > resultHeight))
            {
                resultTime = time;
                resultHeight = h;
            }
        }

    }
    std::cout << resultTime << ' ' << resultHeight << "\n";
    return 0;
}
