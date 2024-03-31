#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int level = 1; // 대각선 레벨
    while (level < n)
    {
        n -= level;
        level++;
    }

    if (level % 2 == 1)
        std::cout << level - n + 1 << "/" << n << '\n';
    else
        std::cout << n << "/" << level - n + 1 << '\n';
    return 0;
}