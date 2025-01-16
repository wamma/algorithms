package thisisalgorithm;

import java.io.*;
import java.util.*;

public class LRUD {
    public static void main(String[] args) throws IOException {
        // 입력 처리
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine()); // 공간의 크기
        StringTokenizer st = new StringTokenizer(br.readLine()); // 이동 명령어 리스트
        int x = 1, y = 1; // 초기 좌표 (1, 1)

        // 상, 하, 좌, 우에 따른 이동 방향 정의
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        String[] moveTypes = {"U", "D", "L", "R"};

        // 이동 명령어 하나씩 확인
        while (st.hasMoreTokens()) {
            String move = st.nextToken();
            int nx = x, ny = y; // 이동 후 좌표 계산

            // 이동 방향에 따른 좌표 변경
            for (int i = 0; i < moveTypes.length; i++) {
                if (move.equals(moveTypes[i])) {
                    nx = x + dx[i];
                    ny = y + dy[i];
                    break;
                }
            }

            // 공간을 벗어나는 경우 무시
            if (nx < 1 || ny < 1 || nx > N || ny > N) {
                continue;
            }

            // 이동 수행
            x = nx;
            y = ny;
        }

        // 결과 출력
        System.out.println(x + " " + y);
    }
}
