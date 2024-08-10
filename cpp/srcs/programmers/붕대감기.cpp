#include <algorithm>
#include <vector>

int solution(std::vector<int> bandage, int health, std::vector<std::vector<int>> attacks)
{
    int max_health = health;
    int t = bandage[0];
    int x = bandage[1];
    int y = bandage[2];

    int current_health = health;
    int continuous_success = 0;
    int attack_index = 0;
    int time = 0;

    // 정렬된 attacks를 기반으로 각 시간을 처리
    while (attack_index < attacks.size() || continuous_success > 0)
    {
        if (attack_index < attacks.size() && attacks[attack_index][0] == time)
        {
            // 공격 받는 경우
            current_health -= attacks[attack_index][1];
            attack_index++;
            continuous_success = 0; // 연속 성공 초기화
            if (current_health <= 0)
                return -1; // 캐릭터 사망
        }
        else
        {
            // 붕대 감기 진행
            if (continuous_success < t)
            {
                if (current_health < max_health)
                {
                    int recovery = std::min(x, max_health - current_health);
                    current_health += recovery;
                }
                continuous_success++;
            }
            if (continuous_success == t)
            {
                if (current_health < max_health)
                {
                    int bonus_recovery = std::min(y, max_health - current_health);
                    current_health += bonus_recovery;
                }
                continuous_success = 0; // 연속 성공 초기화
            }
        }
        time++;
    }

    return current_health;
}
