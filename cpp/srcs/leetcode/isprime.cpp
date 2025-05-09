#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return true;
    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    bool flag = isPrime(n);

    cout << boolalpha << flag << '\n';
    return 0;
}