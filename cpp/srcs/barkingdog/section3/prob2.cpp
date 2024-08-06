#include <iostream>
#include <string>
using namespace std;

int func2(int arr[], int n)
{
    int nums[101] = {};
    for (int i = 0; i < n; ++i)
    {
        if (nums[100 - arr[i]] == 1)
            return 1;
        nums[arr[i]] = 1;
    }
    return 0;
}

int main()
{
    int arr[] = {50, 42};
    int n = 2;
    int res = func2(arr, n);
    cout << res << "\n";
}