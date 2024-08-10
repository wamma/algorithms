#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int buildTowers(const vector<int> &bricks)
{
    vector<int> sortedBricks = bricks;              // 블록 정렬을 위한 복사본
    sort(sortedBricks.begin(), sortedBricks.end()); // 오름차순 정렬

    int n = sortedBricks.size();
    vector<int> tower; // 각 레벨에서 사용된 블록의 최대값을 저장
    int last_max = -1; // 이전 레벨에서 사용된 블록 중 가장 큰 값
    int level = 0;     // 현재 레벨
    int i = 0;         // 블록 배열 인덱스

    while (i < n)
    {
        int count = level + 1; // 현재 레벨에 필요한 블록 수
        if (i + count > n)
            break; // 남은 블록 수가 필요한 블록 수보다 적은 경우

        // 현재 레벨의 블록을 선택
        vector<int> current_level(sortedBricks.begin() + i, sortedBricks.begin() + i + count);
        if (current_level.front() > last_max)
        { // 현재 레벨의 가장 작은 블록이 이전 레벨의 가장 큰 블록보다 커야 함
            last_max = current_level.back(); // 현재 레벨의 가장 큰 블록 업데이트
            tower.push_back(last_max);
            i += count; // 다음 레벨의 블록 시작 인덱스 업데이트
            level++;    // 레벨 증가
        }
        else
        {
            break; // 조건 불만족 시 중단
        }
    }

    return level; // 쌓은 탑의 높이 반환
}

int main()
{
    vector<int> bricks = {5, 5, 5, 5, 5, 5, 5};
    int totalHeight = buildTowers(bricks);
    cout << "Total height of the towers: " << totalHeight << endl;
    return 0;
}
