package baekjoon;

import java.io.*;
import java.util.*;

public class bj1206 {
	public static int n, m;
	public static boolean[][] graph;
	public static boolean[] visited;

	private static void dfs(int start, StringBuilder result) {
		result.append(start).append(" ");
		visited[start] = true;

		for (int i = 1; i <= n; i++) {
			if (graph[start][i] && !visited[i]) {
				dfs(i, result);
			}
		}
	}

	private static void bfs(int start, StringBuilder result) {
		Queue<Integer> queue = new LinkedList<>();
		queue.add(start);
		visited[start] = true;
		result.append(start).append(" ");

		while (!queue.isEmpty()) {
			int node = queue.poll();

			for (int i = 1; i <= n; i++) {
				if (graph[node][i] && !visited[i]) {
					queue.add(i);
					visited[i] = true;
					result.append(i).append(" ");
				}
			}
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int v = Integer.parseInt(st.nextToken());

		graph = new boolean[n + 1][n + 1];
		visited = new boolean[n + 1];

		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			graph[a][b] = graph[b][a] = true;
		}
		StringBuilder dfsResult = new StringBuilder();
		
		dfs(v, dfsResult);
		System.out.println(dfsResult);

		Arrays.fill(visited, false);
		StringBuilder bfsResult = new StringBuilder();
		bfs(v, bfsResult);
		System.out.println(bfsResult);
	}
}
