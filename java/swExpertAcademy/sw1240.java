package swExpertAcademy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class sw1240 {

    static String[] codes = {
            "0001101", "0110001", "0011001", "0101111", "0010011", "0111011", "0111101", "0110111", "0100011", "0001011"
    };
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine().trim());

        for (int testCase = 0; testCase < T; testCase++) {
            String[] nm = br.readLine().trim().split(" ");
            int n = Integer.parseInt(nm[0]);
            int m = Integer.parseInt(nm[1]);

            String[] arr = new String[n];
            for (int i = 0; i < n; i++) {
                arr[i] = br.readLine().trim();
            }

            int[] password = new int[8];
            int index = 0;
            boolean found = false;

            for (int i = n - 1; i > 0; i--) {
                for (int j = m - 1; j > 0; j-- ) {
                    int start = j - 55;
                    for (int k = 0; k < 8; k++) {
                        String codeSegment = arr[i].substring(start + k * 7, start + (k + 1) * 7);
                        for (int l = 0; l < 10; l++) {
                            if (codes[l].equals(codeSegment)) {
                                password[index++] = l;
                                break;
                            }
                        }
                    }
                }
            }


        }
    }
}
