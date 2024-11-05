import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class NumberControl {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine().trim()); // 테스트 케이스 수

        for (int i = 1; i <= T; i++) {
            String N = br.readLine().trim(); // 입력 숫자 N

             String minNum = N; // 초기 최솟값
            String maxNum = N; // 초기 최댓값

            // 모든 자리 조합을 시도하여 최솟값과 최댓값을 찾는다
            for (int j = 0; j < N.length(); j++) {
                for (int k = j + 1; k < N.length(); k++) {
                    // 자리 교환
                    char[] chars = N.toCharArray();
                    char temp = chars[j]; // j번째 자리와
                    chars[j] = chars[k]; // k번째 자리 교환
                    chars[k] = temp;

                    // 새로 만든 수
                    String newNum = new String(chars);

                    // 맨 앞에 '0'이 아니면 최솟값과 최댓값 갱신
                    if (newNum.charAt(0) != '0') {
                        // 최솟값 비교
                        if (newNum.compareTo(minNum) < 0) {
                            minNum = newNum;
                        }
                        // 최댓값 비교
                        if (newNum.compareTo(maxNum) > 0) {
                            maxNum = newNum;
                        }
                    }
                }
            }

            // 결과 출력
            System.out.println("#" + i + " " + minNum + " " + maxNum);
        }

        br.close(); // BufferedReader 리소스 해제
    }
}
