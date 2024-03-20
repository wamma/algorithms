#include <algorithm>
#include <iostream>
#include <vector>

int N, M, result;
int a[10][10];
int visited[10][10];
std::vector<std::pair<int, int>> wall, virus;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

/**
 * 깊이 우선 탐색(DFS)을 수행하는 함수입니다.
 *
 * @param y 탐색을 시작할 좌표의 y값
 * @param x 탐색을 시작할 좌표의 x값
 */
void dfs(int y, int x)
{
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M)
            continue;
        if (visited[ny][nx])
            continue;
        if (a[ny][nx] == 1)
            continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
}

/**
 * @brief go 함수는 바이러스가 퍼지는 영역을 계산하여 반환하는 함수입니다.
 *
 * @return 바이러스가 퍼지지 않은 영역의 개수를 반환합니다.
 */
int go()
{
    int count = 0;
    memset(visited, 0, sizeof(visited));
    // for (std::pair<int, int> a : virus)
    // {
    //     visited[a.first][a.second] = 1;
    //     dfs(a.first, a.second);
    // }
    for (size_t i = 0; i < virus.size(); ++i)
    {
        visited[virus[i].first][virus[i].second] = 1;
        dfs(virus[i].first, virus[i].second);
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (a[i][j] == 0 &&
                visited[i][j] == 0) // visited 배열을 확인하여 바이러스가 퍼진 영역은 카운트 하지 않는다.
                count++;
        }
    }
    return count;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin >> N >> M;
    for (int i = 0; i < N; ++i) // 연구소 상태 입력
    {
        for (int j = 0; j < M; ++j)
        {
            std::cin >> a[i][j];
            if (a[i][j] == 0)
                wall.push_back({i, j});
            if (a[i][j] == 2)
                virus.push_back({i, j});
        }
    }
    int l = wall.size(); // 벽을 세울 수 있는 위치의 갯수
    for (int i = 0; i < l; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            for (int k = 0; k < j; ++k)
            {
                a[wall[i].first][wall[i].second] = 1;
                a[wall[j].first][wall[j].second] = 1;
                a[wall[k].first][wall[k].second] = 1;
                result = std::max(result, go());
                a[wall[i].first][wall[i].second] = 0;
                a[wall[j].first][wall[j].second] = 0;
                a[wall[k].first][wall[k].second] = 0;
            }
        }
    }
    std::cout << result;
    return 0;
}