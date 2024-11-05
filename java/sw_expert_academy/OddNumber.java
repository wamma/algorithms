import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class OddNumber {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine().trim());

        for (int i = 0; i < T; i++) {
            String[] inputs = br.readLine().trim().split(" ");
            int sum = 0;

            for (String input : inputs) {
                int number = Integer.parseInt(input);
                if (number % 2 != 0) {
                    sum += number;
                }
            }

            System.out.println("#" + i + " " + sum);
        }
    }

}
