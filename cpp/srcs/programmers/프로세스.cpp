#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    // 프로세스 우선순위와 초기 위치를 저장하는 큐
    queue<pair<int, int>> q;

    // 큐에 우선순위와 초기 위치를 저장
    for (int i = 0; i < priorities.size(); i++)
    {
        q.push({priorities[i], i});
    }

    // 실행 순서 계산
    while (!q.empty())
    {
        int current_priority = q.front().first;
        int current_position = q.front().second;
        q.pop();

        // 현재 큐에 더 높은 우선순위가 있는지 확인
        bool has_higher = false;
        for (int i = 0; i < priorities.size(); i++)
        {
            if (priorities[i] > current_priority)
            {
                has_higher = true;
                break;
            }
        }

        if (has_higher)
        {
            // 더 높은 우선순위가 있으면 뒤로 보냄
            q.push({current_priority, current_position});
        }
        else
        {
            // 현재 프로세스 실행
            answer++;
            priorities[current_position] = 0; // 실행된 프로세스 우선순위를 0으로 변경

            if (current_position == location)
            {
                break; // 찾던 프로세스가 실행되면 종료
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> priorities = {1, 1, 9, 1, 1, 1};
    int location = 0;

    int result = solution(priorities, location);
    cout << result << "\n";

    return 0;
}