#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, result = 0;
    std::vector<int> products;
    // 0은 딸기 우유만을 파는 가게, 1은 초코우유만을, 2는 바나나우유 만을
    std::cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int milk;
        std::cin >> milk;
        products.push_back(milk);
    }
    for (int i = 0; i < N; ++i)
    {
        if (products[i] == result % 3)
        {
            ++result;
        }
    }
    std::cout << result;
    return 0;
}