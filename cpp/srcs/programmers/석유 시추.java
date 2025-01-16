import java.util.*;

public class 석유 시추 {
	public int solution(int[][] land) {
		int n = land.length;
		int m = land[0].length;
		boolean[][] visited = new boolean[n][m];
		int[] columnOil = new int[m]; // 각 열별 석유량 저장

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (land[i][j] == 1 && !visited[i][j]) {
					bfs(land, visited, n, m, i, j, columnOil);
				}
			}
		}

		int maxOil = 0;
		for (int oil : columnOil) {
			maxOil = Math.max(maxOil, oil);
		}

		return maxOil;
	}

	private void bfs(int[][] land, boolean visited[][], int n, int m, int row, int col, int[] columnOil) {
		int[] dx = {-1, 1, 0, 0};
		int[] dy = {0, 0, -1, 1};
		Queue<int[]> queue = new LinkedList<>();
		queue.offer(new int[]{row, col});
		visited[row][col] = true;

		while (!queue.isEmpty())
		{
			int[] current = queue.poll();
			int x = current[0];
			int y = current[1];
			columnOil[y]++;

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[]
				
			}
		}
	}
}
