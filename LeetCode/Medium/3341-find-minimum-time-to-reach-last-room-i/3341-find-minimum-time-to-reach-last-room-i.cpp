struct State {
    int x, y, time;
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> visited(n, vector<int>(m, INT_MAX));
        // queue<tuple<int, int, int>> q;
        queue<State> q;

        q.push({0, 0, 0});
        visited[0][0] = 0;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            State cur = q.front(); q.pop();
            int x = cur.x, y = cur.y, time = cur.time;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                int nextTime = max(time, moveTime[nx][ny]) + 1;
                if (nextTime < visited[nx][ny]) {
                    visited[nx][ny] = nextTime;
                    q.push({nx, ny, nextTime});
                }
            }
        }

        return visited[n - 1][m - 1];
    }
};