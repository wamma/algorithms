#include <iostream>
using namespace std;

int n;
string result;

int main()
{
    cin >> n;

    if (n == 0)
    {
        std::cout << "0" << std::endl;
        return 0;
    }

    result = "";

    while (n > 0)
    {
        if (n % 2 == 0)
        {
            result.append("0");
        }
        else
        {
            result.append("1");
        }
        n /= 2;
    }

    reverse(result.begin(), result.end());

    std::cout << result << std::endl;
    return 0;
}