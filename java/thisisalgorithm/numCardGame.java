package thisisalgorithm;

import java.io.*;
import java.util.*;

public class numCardGame {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		int result = 0;

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int minValue = Integer.MAX_VALUE;

			for (int j = 0; j < m; j++) {
				int value = Integer.parseInt(st.nextToken());
				minValue = Math.min(minValue, value);
			}

			result = Math.max(result, minValue);
		}

		System.out.println(result);
	}
}
