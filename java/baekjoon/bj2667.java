package baekjoon;

import java.io.*;
import java.util.*;

// 1은 집이 있는 곳
// 0은 집이 없는 곳

public class bj2667 {
	private static int n;
	private static boolean[][] visited;
	private static int[][] map;
	private static int[] dx = {-1, 1, 0, 0};
	private static int[] dy = {0, 0, -1, 1};

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		n = Integer.parseInt(br.readLine());

		map = new int[n + 1][n + 1];
		visited = new boolean[n + 1][n + 1];

		for (int i = 0; i < n; i++) {
			String line = br.readLine();
			for (int j = 0; j < n; j++) {
				map[i][j] = line.charAt(j) - '0';
			}
		}

		List<Integer> houseSize = new ArrayList<>();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					int size = bfs(i, j);
					houseSize.add(size);
				}
			}
		}

		Collections.sort(houseSize);
		System.out.println(houseSize.size());
		for (int size : houseSize) {
			System.out.println(size);
		}
	}



	private static int bfs(int x, int y) {
		Queue<int[]> queue = new LinkedList<>();
		queue.offer(new int[] {x, y});
	}
}
