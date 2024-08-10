#include <cmath>
#include <iostream>
using namespace std;

int findZ(int n, int r, int c)
{
    if (n == 0)
        return 0;
    int half = 1 << (n - 1); // 현재 배열의 한 변의 길이의 절반 계산
    int size = half * half;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r, c;
    cin >> n >> r >> c;
    std::cout << findZ(n, r, c) << std::endl;
    return 0;
}