#include <iostream>
#include <stack>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int k, num;
    std::cin >> k;
    std::stack<int> s;

    for (int i = 0; i < k; ++i)
    {
        std::cin >> num;
        if (num == 0)
            s.pop();
        else
            s.push(num);
    }
    int sum = 0;
    while (!s.empty())
    {
        sum += s.top();
        s.pop();
    }

    std::cout << sum;

    return 0;
}