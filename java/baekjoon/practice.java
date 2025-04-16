package baekjoon;

import java.io.*;
import java.util.*;


public class practice {

	private static int n, m;
	private static boolean[] visited;
	private static List<List<Integer>> graph;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		n = Integer.parseInt(br.readLine());
		m = Integer.parseInt(br.readLine());

		graph = new ArrayList<>();
		for (int i = 0; i <= n; i++) {
			graph.add(new ArrayList<>());
		}

		for (int i = 0; i < m; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			graph.get(a).add(b);
			graph.get(b).add(a);
		}

		visited = new boolean[n + 1];

		System.out.println(bfs(1));
	}

	private static int bfs(int start) {
		Queue<Integer> queue = new LinkedList<>();
		queue.offer(start);
		visited[start] = true;

		int count = 0;

		while (!queue.isEmpty()) {
			int current = queue.poll();

			List<Integer> neighbors = graph.get(current);
			for (int i = 0; i < neighbors.size(); i++) {
				int neighbor = neighbors.get(i);

				if (!visited[neighbor]) {
					visited[neighbor] = true;
					queue.add(neighbor);
					count++;
				}
			}
		}
		return count;
	}
}
