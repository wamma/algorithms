#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int next(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

bool solution(int n)
{
    // 주어진 숫자가 만약에 int num = 19면
    // 1 * 1 + 9 * 9 = 82
    // 8 * 8 + 2 * 2 = 68
    // 6 * 6 + 8 * 8 = 100
    // 1 * 1 + 0 * 0 + 0 * 0 = 1
    // 이런 순서로 1이 되면 true 아니면 false 반환하는 문제

    unordered_set<int> seen;
    while (n != 1 && !seen.count(n))
    {
        seen.insert(n);
        n = next(n);
    }
    return n == 1;
}

int main()
{
    int n = 21;
    bool b = solution(n);
    cout << b << endl;
    return 0;
}