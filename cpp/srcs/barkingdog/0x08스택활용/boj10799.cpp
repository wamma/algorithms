// 쇠막대기
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;
    stack<int> s;
    int pieces = 0;

    for (int i = 0; i < input.length(); ++i)
    {
        if (input[i] == '(')
            s.push(i);
        else // ')' 일때
        {
            if (s.top() == i - 1) // 레이저인 경우
            {
                s.pop();
                pieces += s.size();
            }
            else
            {
                s.pop();
                pieces += 1;
            }
        }
    }

    cout << pieces;
    return 0;
}