package thisisalgorithm.bfsdfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class escapeMaze {
	public static int n, m;
	public static int[][] graph = new int[200][200];
	public static int dx[] = {-1, 1, 0, 0};
	public static int dy[] = {0, 0, -1, 1};

	public static int bfs(int x, int y) {
		int[][] queue = new int[200 * 200][2];
		int front = 0, rear = 0;

		queue[rear][0] = x;
		queue[rear][1] = y;
		rear++;

		while (front < rear) {
			int curX = queue[front][0];
			int curY = queue[front][1];
			front++;

			for (int i = 0; i < 4; i++) {
				int nx = curX + dx[i];
				int ny = curY + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

				if (graph[nx][ny] == 0) continue;

				if (graph[nx][ny] == 1) {
					graph[nx][ny] = graph[curX][curY] + 1;
					queue[rear][0] = nx;
					queue[rear][1] = ny;
					rear++;
				}
			}
		}

		return graph[n - 1][m - 1];
	}


	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		for (int i = 0; i < n; i++) {
			String str = br.readLine();
			for (int j = 0; j < m; j++) {
				graph[i][j] = str.charAt(j) - '0';
			}
		}

		System.out.println(bfs(0, 0));
	}
}
