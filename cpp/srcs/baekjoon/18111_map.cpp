#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, B;
    std::cin >> N >> M >> B;

    std::vector<int> heightCount(257, 0); // 높이 분포를 저장할 배열
    int minHeight = 256, maxHeight = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int h;
            std::cin >> h;
            minHeight = std::min(minHeight, h);
            maxHeight = std::max(maxHeight, h);
            heightCount[h]++;
        }
    }

    int resultTime = INT_MAX, resultHeight = -1;
    for (int h = minHeight; h <= maxHeight; ++h)
    {
        int build = 0, remove = 0, inventory = B;
        for (int i = minHeight; i <= maxHeight; ++i)
        {
            int diff = i - h;
            if (diff > 0) // 블록 제거
            {
                remove += diff * heightCount[i];
                inventory += diff * heightCount[i]; // 제거한 블록은 인벤토리에 추가
            }
            else if (diff < 0) // 블록 추가
            {
                build -= diff * heightCount[i];
                inventory += diff * heightCount[i]; // 필요한 만큼 인벤토리에서 블록 사용
            }
        }

        if (inventory >= 0) // 인벤토리가 음수가 아닌 경우만 유효
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
