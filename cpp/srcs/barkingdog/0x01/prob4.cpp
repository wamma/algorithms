#include <iostream>

int func4(int n)
{
    int res = 1;
    while (2 * res <= n)
        res *= 2;
    return res;
}

int main()
{
    int n;
    std::cin >> n;
    int result = func4(n);
    std::cout << result << std::endl;
}