#include <iostream>
#include <queue>
#include <utility>
using namespace std;
#define X first
#define Y second

int dist[100002];
int n, k; // n은 초기위치, k가 찾아야할 위치

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    fill(dist, dist + 100001, -1);
    dist[n] = 0; // 시작 위치를 시간 0으로 설정
    queue<int> q;
    q.push(n);
    while (dist[k] == -1)
    {
        auto cur = q.front(); // 현재 위치
        q.pop();
        for (int nxt : {cur - 1, cur + 1, 2 * cur}) // 걷기(-1, 1), 순간이동(*2)
        {
            if (nxt < 0 || nxt > 100000) // 다음 위치가 범위를 벗어나면 무시
                continue;
            if (dist[nxt] != -1) // 이미 방문한 위치면 무시
                continue;
            dist[nxt] = dist[cur] + 1; // 다음 위치에 대한 시간을 현재 위치 시간 +1로 설정
            q.push(nxt);               // 다음 위치를 큐에 삽입.
        }
    }
    cout << dist[k]; // 동생의 위치까지 도달하는 데 필요한 최소 시간 출력
}