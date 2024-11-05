import java.util.*;
import java.io.*;

public class Parking {
    static class State {
        int position;
        int speed;
        int time;

        State(int position, int speed, int time) {
            this.position = position;
            this.speed = speed;
            this.time = time;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] nk = br.readLine().trim().split(" ");
        int N = Integer.parseInt(nk[0]);
        int K = Integer.parseInt(nk[1]);

        System.out.println(findMinTime(N, K));
    }

    static int findMinTime(int N, int K) {
        Queue<State> queue = new LinkedList<>();
        // position, speed를 키로 하는 방문 체크 Set
        Set<String> visited = new HashSet<>();

        // 초기 상태: 위치 1, 속도 0, 시간 0
        queue.offer(new State(1, 0, 0));
        visited.add("1,0");

        while (!queue.isEmpty()) {
            State current = queue.poll();

            // 목적지에 도달하고 속도가 0이면 현재까지의 시간 반환
            if (current.position == N && current.speed == 0) {
                return current.time;
            }

            // 가능한 모든 가속도 변화 (-K부터 +K까지)
            for (int acceleration = -K; acceleration <= K; acceleration++) {
                int newSpeed = current.speed + acceleration;

                // 속도는 음수가 될 수 없고, K를 초과할 수 없음
                if (newSpeed < 0 || newSpeed > K) continue;

                int newPosition = current.position + newSpeed;

                // 새로운 위치가 유효한지 확인
                if (newPosition > N || newPosition < 1) continue;

                // 방문하지 않은 상태라면 큐에 추가
                String newState = newPosition + "," + newSpeed;
                if (!visited.contains(newState)) {
                    visited.add(newState);
                    queue.offer(new State(newPosition, newSpeed, current.time + 1));
                }
            }
        }

        return -1; // 도달할 수 없는 경우
    }
}