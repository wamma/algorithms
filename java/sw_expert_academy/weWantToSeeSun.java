import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class weWantToSeeSun {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = 10;

        for (int testCase = 1; testCase <= T; testCase++) {
            int N = Integer.parseInt(br.readLine().trim());

            String[] inputs = br.readLine().trim().split(" ");
            int[] heights = new int[N];

            for (int i = 0; i < N; i++) {
                heights[i] = Integer.parseInt(inputs[i]);
            }

            int viewCount = 0;

            for (int i = 2; i < N - 2; i++)
            {
                int maxHeightNeighbor = Math.max(
                        Math.max(heights[i - 2], heights[i - 1]),
                        Math.max(heights[i + 1], heights[i + 2])
                );

                if (heights[i] > maxHeightNeighbor) {
                    viewCount += heights[i] - maxHeightNeighbor;
                }
            }
            System.out.println("#" + testCase + " " + viewCount);
        }
    }
}
