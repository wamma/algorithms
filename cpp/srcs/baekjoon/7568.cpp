#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int k;
    std::cin >> k;
    std::vector<std::pair<int, int>> people(k);
    std::vector<int> rank(k, 1);

    for (int i = 0; i < k; ++i)
        std::cin >> people[i].first >> people[i].second;

    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            if (i == j)
                continue;
            if (people[i].first < people[j].first && people[i].second < people[j].second)
                rank[i]++;
        }
    }
    for (int i = 0; i < k; ++i)
        std::cout << rank[i] << ' ';
    std::cout << '\n';

    return 0;
}
