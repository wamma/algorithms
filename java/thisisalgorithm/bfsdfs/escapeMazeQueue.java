package thisisalgorithm.bfsdfs;

import java.io.*;
import java.util.*;

public class escapeMazeQueue {
	public static int n, m;
	public static int[][] graph = new int[200][200];
	public static int dx[] = {-1, 1, 0, 0};
	public static int dy[] = {0, 0, -1, 1};

	public static int bfs(int x, int y) {
		Queue<int[]> queue = new LinkedList<>();
		queue.offer(new int[]{x, y});

		while (!queue.isEmpty()) {
			int[] cur = queue.poll();
			int curX = cur[0];
			int curY = cur[1];

			for (int i = 0; i < 4; i++) {
				int nx = curX + dx[i];
				int ny = curY + dy[i];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

				if (graph[nx][ny] == 0) continue;

				if (graph[nx][ny] == 1) {
					graph[nx][ny] = graph[curX][curY] + 1;
					queue.offer(new int[]{nx, ny});
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
