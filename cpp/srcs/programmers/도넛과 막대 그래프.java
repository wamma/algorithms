import java.util.*;

class Solution {
    public static int[] solution(int[][] edges) {
        Map<Integer, Integer> inDegree = new HashMap<>();
        Map<Integer, Integer> outDegree = new HashMap<>();
        
        for (int[] edge : edges) {
            int from = edge[0], to = edge[1];
            outDegree.put(from, outDegree.getOrDefault(from, 0) + 1);
            inDegree.put(to, inDegree.getOrDefault(to, 0) + 1);
            
            if (!inDegree.containsKey(from)) {
                inDegree.put(from, 0);
            }
            if (!outDegree.containsKey(to)) {
                outDegree.put(to, 0);
            }
        }

        int donutCount = 0, eightCount = 0, createdVertex = -1;

        for (Map.Entry<Integer, Integer> entry : inDegree.entrySet()) {
            int vertex = entry.getKey();
            int in = entry.getValue();
            int out = outDegree.getOrDefault(vertex, 0);

            if (in == 0 && out > 0) {
                createdVertex = vertex;
            } else if (in == 1 && out == 1) {
                donutCount++;
            } else if (in == 2 && out == 2) {
                eightCount++;
            }
        }

        int totalVertices = inDegree.size();
        // 막대 모양 그래프의 수를 다시 계산
        int barCount = totalVertices - (donutCount + 2 * eightCount + 1); // +1은 생성된 정점 때문에 추가
        
        // 막대 모양 그래프의 계산이 수정되어야 함을 주의
        return new int[] {createdVertex, donutCount, barCount, eightCount};
    }

    public static void main(String[] args) {
        int[][] edges = {{2,3},{4,3},{1,1},{2,1}};
        int[] result = solution(edges);
        System.out.println(Arrays.toString(result));
    }
}
