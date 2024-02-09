#include <cmath>
#include <iostream>

int main()
{
    int x;
    std::cin >> x; // 표준 입력에서 x 값을 읽어옴

    int n = x % 1000; // x의 마지막 세 자리
    int u = x / 1000; // x의 앞부분 (정수 나눗셈으로 인해 자동으로 내림 처리됨)

    for (int i = 0; i < n; ++i)
    {
        u *= 31;
        u %= 10867;
        u %= 1000;
    }

    std::cout << u << std::endl; // 최종 결과 출력

    return 0;
}
