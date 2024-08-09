#include <iostream>
using namespace std;

long long modPow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    long long A, B, C;
    cin >> A >> B >> C;

    cout << modPow(A, B, C) << endl;

    return 0;
}