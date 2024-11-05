import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Sum {
    public static int[][] matrix;
    public static int maxSum;

    public static void main(String[] args) throws IOException {
        System.setIn(new FileInputStream("src/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = 10;

        for (int t = 1; t <= T; t++) {
            int testCase = Integer.parseInt(br.readLine().trim());

            matrix = new int[100][100];

            for (int i = 0; i < 100; i++) {
                String[] line = br.readLine().trim().split(" ");

                for (int j = 0; j < 100; j++) {
                    matrix[i][j] = Integer.parseInt(line[j]);
                }
            }

            maxSum = 0;

            for (int i = 0; i < 100; i++) {
                int rowSum = 0;
                for (int j = 0; j < 100; j++) {
                    rowSum += matrix[i][j];
                }
                maxSum = Math.max(maxSum, rowSum);
            }

            for (int j = 0; j < 100; j++) {
                int colSum = 0;
                for (int i = 0; i < 100; i++) {
                    colSum += matrix[i][j];
                }
                maxSum = Math.max(maxSum, colSum);
            }

            int diagonalSum = 0;
            for (int i = 0; i < 100; i++) {
                diagonalSum += matrix[i][i];
            }
            maxSum = Math.max(maxSum, diagonalSum);

            int antiDiagonalSum = 0;
            for (int i = 0; i < 100; i++) {
                antiDiagonalSum += matrix[i][99 - i];
            }
            maxSum = Math.max(maxSum, antiDiagonalSum);

            System.out.println("#" + t + " " + maxSum);
        }
    }
}
