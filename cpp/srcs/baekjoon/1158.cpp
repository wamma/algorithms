#include <iostream>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, K;
    std::cin >> N >> K;

    std::queue<int> q;
    for (int i = 1; i <= N; i++)
        q.push(i);

    std::cout << "<";
    while (!q.empty())
    {
        for (int i = 0; i < K - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        std::cout << q.front();
        q.pop();
        if (!q.empty())
        {
            std::cout << ", ";
        }
    }
    std::cout << ">" << std::endl;

    return 0;
}