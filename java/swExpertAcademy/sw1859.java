package swExpertAcademy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class sw1859 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine().trim());

        for (int testCase = 1; testCase <= T; testCase++) {
            int N = Integer.parseInt(br.readLine().trim());
            String[] pricesStr = br.readLine().trim().split(" ");
            int[] prices = new int[N];

            for (int i = 0; i < N; i++) {
                prices[i] = Integer.parseInt(pricesStr[i]);
            }

            long sum = 0;
            int maxPrice = prices[N - 1];

            for (int i = N - 2; i >= 0; i--) {
                if (prices[i] < maxPrice) {
                    sum += maxPrice - prices[i];
                } else if (maxPrice < prices[i]) {
                    maxPrice = prices[i];
                } else {
                    continue;
                }
            }

            System.out.println("#" + testCase + " " + sum);
        }
    }
}
