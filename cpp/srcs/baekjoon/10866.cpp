#include <deque>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::string command;
    std::deque<int> d;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> command;
        if (command == "push_front")
        {
            int num;
            std::cin >> num;
            d.push_front(num);
        }
        else if (command == "push_back")
        {
            int num;
            std::cin >> num;
            d.push_back(num);
        }
        else if (command == "pop_front")
        {
            if (d.empty())
                std::cout << -1 << '\n';
            else
            {
                std::cout << d.front() << '\n';
                d.pop_front();
            }
        }
        else if (command == "pop_back")
        {
            if (d.empty())
                std::cout << -1 << '\n';
            else
            {
                std::cout << d.back() << '\n';
                d.pop_back();
            }
        }
        else if (command == "size")
        {
            std::cout << d.size() << '\n';
        }
        else if (command == "empty")
        {
            if (d.empty())
                std::cout << 1 << '\n';
            else
                std::cout << 0 << '\n';
        }
        else if (command == "front")
        {
            if (d.empty())
                std::cout << -1 << '\n';
            else
                std::cout << d.front() << '\n';
        }
        else if (command == "back")
        {
            if (d.empty())
                std::cout << -1 << '\n';
            else
                std::cout << d.back() << '\n';
        }
    }
    return 0;
}