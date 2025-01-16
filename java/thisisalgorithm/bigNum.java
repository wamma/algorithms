package thisisalgorithm;

import java.io.*;
import java.util.*;


public class bigNum {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		int[] data = new int[n];
		for (int i = 0; i < n; i++) {
			data[i] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(data);
		int first = data[n - 1];
		int second = data[n - 2];
		
		int result = 0;

		while (true) {
			for (int i = 0; i < k; i++) {
				if (m == 0) break;
				result += first;
				m--;
			}
			if (m == 0) break;

			result += second;
			m--;
			if (m == 0) break;
		}
		System.out.println(result);
	}
}
