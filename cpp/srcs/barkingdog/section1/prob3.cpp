#include <iostream>

int func3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (i * i == n)
            return 1;
    }
    return 0;
}

int main()
{
    int n;
    std::cin >> n;
    int result = func3(n);
    std::cout << result << std::endl;
}