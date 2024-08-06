#include <iostream>

int func2(int arr[], int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (arr[i] + arr[j] == 100)
                return 1;
        }
    }
    return 0;
}

int main()
{
    int arr[] = {4, 13, 63, 87};
    int result = func2(arr, 4);
    std::cout << result << std::endl;
}