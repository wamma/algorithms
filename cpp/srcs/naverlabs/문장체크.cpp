#include <cctype>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> &arr)
{
    // vector<string> arr에 문장이 길게 있다.
    // team_name:t로 시작된 문장이어야 하고
    // application_name : a로 시작된 문장이어야 한다.
    // 이렇게 규칙대로 안써져 있을때 count++ 하여 return count 하는 문제

    int count = 0;
    const string tKey = "team_name : ";
    const string aKey = "application_name : ";
    for (const auto &line : arr)
    {
        bool valid = true;

        auto t_pos = line.find(tKey);
        if (t_pos == string::npos)
        {
            valid = false;
        }
        else
        {
			
        }
    }
}

int main()
{
}