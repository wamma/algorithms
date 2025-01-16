package swExpertAcademy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class sw1204 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine().trim());

        for (int testCase = 1; testCase <= T; testCase++) {
            int testNumber = Integer.parseInt(br.readLine().trim());
            String[] numberStr = br.readLine().trim().split(" ");
            int[] numbers = new int[101];

            for (String number : numberStr) {
                int score = Integer.parseInt(number);
                numbers[score]++;
            }

            int maxCount = 0;
            int mode = 0;

            for (int i = 100; i >= 0; i--) {
                if ()
            }
        }
    }
}
