#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, groupWordCount = 0;
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        std::string word;
        std::cin >> word;
        bool isGroupWord = true;
        bool seen[26] = {false};
        for (int j = 0; j < word.length(); ++j)
        {
            if (j > 0 && word[j] == word[j - 1])
                continue;
            if (seen[word[j] - 'a'])
            {
                isGroupWord = false;
                break;
            }
            seen[word[j] - 'a'] = true;
        }
        if (isGroupWord)
            ++groupWordCount;
    }
    std::cout << groupWordCount << std::endl;
    return 0;
}
