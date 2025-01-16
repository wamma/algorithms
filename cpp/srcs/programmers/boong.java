public class boong {
    static class Solution {
        public int solution(int[] bandage, int health, int[][] attacks) {
			// bandage는 [시전 시간, 초당 회복량, 추가 회복량]
			// attacks[i]는 [공격 시간, 피해량]
			int heal = health;
			int time = 0;
			int attackIndex = 0;

			while (time < attacks[attacks.length - 1][0] && health > 0)
			{
				if (attackIndex < attacks.length)
				time++;
			}
        }
    }

    public static void main(String[] args) {
        int[] bandage = {5, 1, 5};
        int health = 30;
        int[][] attacks = {{2, 10}, {9, 15}, {10, 5}, {11, 5}};

        Solution solution = new Solution(); // Solution 클래스의 인스턴스 생성
        int result = solution.solution(bandage, health, attacks); // 인스턴스를 통해 메서드 호출

        System.out.println(result);
    }
}
