package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class bj1024 {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int L = Integer.parseInt(st.nextToken());

		for (int length = L; length <= 100; length++) {
			int temp = N - (length * (length - 1)) / 2;
			
			if (temp % length == 0) {
			int start = temp / length;
			if (start >= 0) {
				for (int i = 0; i < length; i++) {
				System.out.print((start + i) + " ");
				}
				return;
			}
			}
		}
		System.out.println(-1);
	}
}