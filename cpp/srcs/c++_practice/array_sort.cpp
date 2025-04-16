#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {1, 4, 7, 8, 0};

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i] < arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << "arr[i]: " << arr[i] << std::endl;
    }
}