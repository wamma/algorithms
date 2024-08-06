#include <iostream>

int func1(int n)
{
    int res = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
            res += i;
    }
    return res;
}

int main()
{
    int result = func1(34567);
    std::cout << result << std::endl;
}