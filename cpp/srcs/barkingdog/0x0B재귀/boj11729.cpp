#include <iostream>
using namespace std;

/*
n-1개의 원판을 기둥1에서 기둥2로 옮긴다
n번 원판을 기둥1에서 기둥3으로 옮긴다.
n-1개의 원판을 기둥2에서 기둥3으로 옮긴다.
-> 원판이 n-1개일 때 옮길수 있으면 원판이 n개일때에도 옮길 수 있다.

원판이 1개일때 원판을 원하는 곳으로 옮길 수 있다.
원판이 k개 일 때 옮길 수 있으면 원판이 k + 1개 일 때도 옮길 수 있다.
*/
void move(int n, int start, int end, int bojo)
{
    // 원판 1개를 바로 목표 장대로 이동
    if (n == 1)
    {
        cout << start << " " << end << '\n';
        return;
    }
    // n-1개를 보조 장대로 이동
    move(n - 1, start, bojo, end);
    // 가장 큰 원판을 목표 장대로 이동
    cout << start << " " << end << '\n';
    // n-1개를 목표 장대로 이동
    move(n - 1, bojo, end, start);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    // 총 이동 횟수: 2^n - 1
    cout << (1 << n) - 1 << '\n';
    move(n, 1, 3, 2);
}