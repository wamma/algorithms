package baekjoon;

import java.io.*;
import java.util.*;

public class bj2178 {
	private static final int[] dx = {-1, 1, 0, 0};
	private static final int[] dy = {0, 0, -1, 1};

	private static boolean[][] visited;
	private static int[][] maze;
	private static int n, m;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		maze = new int[n][m];

		for (int i = 0; i < n; i++) {
			String line = br.readLine();
			for (int j = 0; j < m; j++) {
				maze[i][j] = line.charAt(j) - '0';
			}
		}

		visited = new boolean[n][m];

		System.out.println(bfs());
	}

	private static int bfs() {
		Queue<int[]> queue = new LinkedList<>();
		queue.offer(new int[]{0, 0});

		visited[0][0] = true;

		while (!queue.isEmpty()) {
			int[] current = queue.poll();
			int x = current[0];
			int y = current[1];

			if (x == n - 1 && y == m - 1) {
				return maze[x][y];
			}

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 1 && !visited[nx][ny]) {
					visited[nx][ny] = true;
					maze[nx][ny] = maze[x][y] + 1;
					queue.add(new int[]{nx, ny});
				}
			}
		}

		return -1;
	}
}
