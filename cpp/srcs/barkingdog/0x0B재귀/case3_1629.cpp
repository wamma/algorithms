#include <iostream>
using namespace std;
using ll = long long;

ll a, b, c;

ll pow(ll a, ll b, ll c)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % c;
    ll half = pow(a, b / 2, c); // A^(B/2) % C를 계산
    half = (half * half) % c;   // (A^(B/2) % C) * (A^(B/2) % C)

    if (b % 2 == 1)
        half = (half * (a % c)) % c;
    return half;
}
/*
분할 정복 지수 거듭제곱

*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;

    cout << pow(a, b, c);
    return 0;
}