#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second

int board[502][502];
int visited[502][502];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> board[i][j];
    int mx = 0;
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (board[i][j] == 0 || visited[i][j])
                continue;
            count++;
            queue<pair<int, int>> q;
            visited[i][j] = 1;
            q.push({i, j});
            int area = 0;
            while (!q.empty())
            {
                area++;
                auto cur = q.front();
                q.pop();
                for (int dir = 0; dir < 4; ++dir)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if (visited[nx][ny] || board[nx][ny] != 1)
                        continue;
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            mx = max(mx, area);
        }
    }
    cout << count << '\n' << mx;
    return 0;
}