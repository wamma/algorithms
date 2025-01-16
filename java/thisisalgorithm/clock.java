package thisisalgorithm;

import java.io.*;

public class clock {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int h = Integer.parseInt(br.readLine());
		int count = 0;

		for (int i = 0; i <= h; i++) {
			for (int j = 0; j < 60; j++) {
				for (int k = 0; k < 60; k++) {
					String time = i + "" + j + "" + k;
					if (time.contains(String.valueOf(h))) {
						count++;
					}
				}
			}
		}

		System.out.println(count);
	}
}
