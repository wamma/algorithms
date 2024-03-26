#include <iostream>
#include <stack>

int main()
{
    int N;
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;

    std::stack<int> s;
    std::string command;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> command;
        if (command == "push")
        {
            int number;
            std::cin >> number;
            s.push(number);
        }
        else if (command == "pop")
        {
            if (s.empty())
                std::cout << "-1" << '\n';
            else
            {
                std::cout << s.top() << '\n';
                s.pop();
            }
        }
        else if (command == "size")
        {
            std::cout << s.size() << '\n';
        }
        else if (command == "empty")
        {
            std::cout << s.empty() << '\n';
        }
        else if (command == "top")
        {
            if (s.empty())
            {
                std::cout << "-1" << '\n';
            }
            else
            {
                std::cout << s.top() << '\n';
            }
        }
    }
    return 0;
}