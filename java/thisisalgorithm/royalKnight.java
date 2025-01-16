package thisisalgorithm;

import java.io.*;

public class royalKnight {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		String input = br.readLine();
		char colChar = input.charAt(0);
        int row = Character.getNumericValue(input.charAt(1));

        int col = colChar - 'a' + 1;

		int[][] steps = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};

		int result = 0;

		for (int[] step : steps) {
			int nextRow = row + step[0];
			int nextCol = col + step[1];

			if (nextRow >= 1 && nextRow <= 8 && nextCol >= 1 && nextCol <= 8) {
				result++;
			}
		}
		System.out.println(result);
	}
}
