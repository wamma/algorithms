import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

// 높은곳에서 낮은 곳으로 옮기는 작업을 덤프라고 정의

public class Flatten {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = 10;

        for (int testCase = 1; testCase<= T; testCase++) {
            int dumpCount = Integer.parseInt(br.readLine().trim());
            String[] inputs = br.readLine().trim().split(" ");
            int[] heights = new int[inputs.length];

            for (int i = 0; i < inputs.length; i++) {
                heights[i] = Integer.parseInt(inputs[i]);
            }

            for (int i = 1; i <= dumpCount; i++) {
                Arrays.sort(heights);
                heights[0] += 1;
                heights[heights.length - 1]  -= 1;  // 제일 처음 덤프 하는 행동
            }

            Arrays.sort(heights);
            int result = heights[heights.length - 1] - heights[0];

            System.out.println("#" + testCase + " " + result);
        }
    }
}
