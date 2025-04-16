package thisisalgorithm;

import java.io.*;
import java.util.StringTokenizer;

public class soulknight {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		char colChar = input.charAt(0);
		int row = Character.getNumericValue(input.charAt(1));

		int col = colChar - 'a' + 1;

		int[][] steps = {{-2, 1}, {-2, -1}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {1, 2}, {1, -2}};

		
	}
}
