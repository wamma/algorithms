import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class hamburgerDiet {
    static int maxScore;
    static int N, L;
    static int[] scores, calories;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine().trim());



        for (int testCase = 1; testCase <= T; testCase++) {
            String[] nl = br.readLine().trim().split(" ");

            N = Integer.parseInt(nl[0]);
            L = Integer.parseInt(nl[1]);

            scores = new int[N];
            calories = new int[N];

            for (int i = 0; i < N; i++) {
                String[] inputs = br.readLine().trim().split(" ");
                scores[i] = Integer.parseInt(inputs[0]);
                calories[i] = Integer.parseInt(inputs[1]);
            }

            maxScore = 0;

            findMaxScore(0, 0, 0);

            System.out.println("#" + testCase + " " + maxScore);
        }
    }

    private static void findMaxScore(int index, int currentScore, int currentCalories) {
        if (currentCalories > L) return;

        maxScore = Math.max(maxScore, currentScore);

        if (index == N) return;
        findMaxScore(index + 1, currentScore + scores[index], currentCalories + calories[index]);
        findMaxScore(index + 1, currentScore, currentCalories);
    }
}
