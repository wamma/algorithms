package thisisalgorithm;

import java.io.*;
import java.util.*;

public class until1 {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());

		int count = 0;
		while (n > 1) {
			if (n % k == 0) {
				n /= k;
				count++;
			}
			else {
				int mod = n % k;
				n -= mod;
				count += mod;
			}
			if (n == 1) break;
		}
		if (n % k == 0) count++;
		else count += (n - 1);

		System.out.println(count);
	}
}
