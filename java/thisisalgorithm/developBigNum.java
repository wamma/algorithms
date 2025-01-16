package thisisalgorithm;

import java.io.*;
import java.util.*;

public class developBigNum {
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

		int count = (m / (k + 1)) * k;
		count += m % (k + 1);

		int result = 0;
		result += count * first;
		result += (m - count) * second;
		System.out.println(result);
	}
}
