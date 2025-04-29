#include <cctype>
#include <string>
#include <vector>

using namespace std;

int solution(const vector<string> &arr)
{
    // vector<string> arr에 문장이 길게 있다.
    // team_name:
    // t로 시작된 문장이어야 하고 application_name : a로 시작된 문장이어야 한다.
    // 이렇게 규칙대로 안써져 있을때 count++

    int count = 0;
    const string tKey = "team_name: ";
    const string aKey = "application_name: ";

    for (const auto &line : arr)
    {
        bool valid = true;

        // team_name 위치 찾고 값의 첫 글자가 t인지 체크
        auto tPos = line.find(tKey);
        if (tPos == string::npos)
        {
            valid = false;
        }
        else
        {
			
        }
    }
}