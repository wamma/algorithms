#include <iostream>
#include <vector>

int main()
{
    const int MAX_RANK = 13;
    std::vector<int> cardCount(MAX_RANK + 1, 0);

    for (int i = 0; i < 5; ++i)
    {
        int rank;
        std::cin >> rank;
        cardCount[rank]++;
    }

    int pairCount = 0;
    for (int i = 1; i <= MAX_RANK; ++i)
    {
        pairCount += cardCount[i] * (cardCount[i] - 1) / 2;
    }
    std::cout << pairCount << std::endl;
    return 0;
}
