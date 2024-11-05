import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class maximumPrize {
    static int changeCount;
    static int answer;
    static String[] target;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine().trim());

        for (int testCase = 1; testCase <= T; testCase++) {
            String[] inputs = br.readLine().trim().split(" ");
            target = inputs[0].split("");
            changeCount = Integer.parseInt(inputs[1]);

            answer = 0;
            dfs(0 ,0);

            // 홀수 교환이 남았을 경우, 맨 마지막 두 자리 교환하여 최대값 체크
            if (changeCount % 2 != 0) {
                swap(target.length - 1, target.length - 2);
                StringBuilder targetNum = new StringBuilder();
                for (String tmp : target) {
                    targetNum.append(tmp);
                }
                answer = Math.max(answer, Integer.parseInt(targetNum.toString()));
                // 원래 상태로 복원
                swap(target.length - 1, target.length - 2);
            }

            System.out.println("#" + testCase + " " + answer);
        }
    }

    static void dfs (int k, int count) {
        if (count == changeCount) {
            StringBuilder targetNum = new StringBuilder();

            for (String tmp : target) {
                targetNum.append(tmp);
            }

            answer = Math.max(answer, Integer.parseInt(targetNum.toString()));
            return;
        }

        for (int i = k; i < target.length; i++) {
            for (int j = i + 1; j < target.length; j++) {
                swap(i, j);  // 교환
                dfs(i, count + 1);
                swap(i, j);  // 원래 상태로 복원 (백트래킹)
            }
        }
    }

    private static void swap(int i, int j) {
        String temp = target[i];
        target[i] = target[j];
        target[j] = temp;
    }
}
