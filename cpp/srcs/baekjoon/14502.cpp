#include <algorithm>
#include <iostream>
#include <vector>

int N, M;
int lab[8][8];     // 초기 연구소 상태 저장 배열
int tempLab[8][8]; // 벽을 설치한 후의 연구소 상태 저장 배열
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int result = 0; // 안전 영역의 최대 크기를 저장하는 변수

void copyLab()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            tempLab[i][j] = lab[i][j];
        }
    }
}

void dfs(int y, int x)
{
    // 바이러스를 퍼뜨리는 DFS 함수
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && ny < N && nx >= 0 && nx < M)
        {
            if (tempLab[ny][nx] == 0)
            {
                tempLab[ny][nx] = 2;
                dfs(ny, nx);
            }
        }
    }
}

int getSafeArea()
{
    int safe = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (tempLab[i][j] == 0)
                ++safe;
        }
    }
    return safe;
}

void buildWall(int count)
{
    if (count == 3) // 벽 3개를 세웠다면
    {
        copyLab();
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (tempLab[i][j] == 2)
                    dfs(i, j);
            }
        }
        result = std::max(result, getSafeArea());
        return;
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (lab[i][j] == 0) // 빈 공간이라면
            {
                lab[i][j] = 1;        // 벽 세움
                buildWall(count + 1); // 다음 벽을 세우기 위해 재귀 호출
                lab[i][j] = 0;        // 다시 빈 공간으로 되돌림 (백트래킹)
            }
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N >> M;
    buildWall(0);
    std::cout << result;

    return 0;
}