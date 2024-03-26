#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string word;
    int count = 0;

    std::cin >> word;
    for (size_t i = 0; i < word.length(); ++i)
    {
        if (word[i] == 'c' && (i + 1 < word.length() && (word[i + 1] == '=' || word[i + 1] == '-')))
            ++i;
        else if (word[i] == 'd')
        {
            if ((i + 1 < word.length() && word[i + 1] == '-'))
                ++i;
            else if (i + 2 < word.length() && word[i + 1] == 'z' && word[i + 2] == '=')
                i += 2;
        }
        else if ((word[i] == 'l' || word[i] == 'n') && (i + 1 < word.length() && word[i + 1] == 'j'))
            ++i;
        else if ((word[i] == 's' || word[i] == 'z') && (i + 1 < word.length() && word[i + 1] == '='))
            ++i;
        ++count;
    }

    std::cout << count << '\n';
    return 0;
}