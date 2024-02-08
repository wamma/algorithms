#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    long long result = 1; // Using long long to handle large factorials
    for (int i = 1; i <= n; ++i)
    {
        if (i % 2 == 1)
        { // Check if i is odd
            result *= i;
        }
    }

    std::cout << result << std::endl;
    return 0;
}
