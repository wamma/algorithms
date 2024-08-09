#include <iostream>
using namespace std;
long long a, b, c;

long long pow(long long a, long long b, long long c)
{
    if (b == 1) // base condition
        return a % c;
    long long val = pow(a, b / 2, c);
    val = val * val % c;
    if (b % 2 == 0)
        return val;
    return val * a % c;
}
// a를 b 번 곱한 수를 c로 나눈 나머지
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;
    cout << pow(a, b, c);
    return 0;
}