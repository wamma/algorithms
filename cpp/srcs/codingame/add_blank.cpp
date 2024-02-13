#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore(); // 줄바꿈 문자를 무시합니다.

    std::vector<std::vector<std::string>> lines;
    std::string input;
    std::vector<int> columnWidths;

    // 입력을 읽고 처리합니다.
    for (int i = 0; i < n; ++i)
    {
        std::getline(std::cin, input);
        std::istringstream iss(input);
        std::vector<std::string> words;
        std::string word;
        while (iss >> word)
        {
            words.push_back(word);
        }
        lines.push_back(words);

        // 열 너비를 갱신합니다.
        if (columnWidths.size() < words.size())
        {
            columnWidths.resize(words.size(), 0);
        }
        for (size_t j = 0; j < words.size(); ++j)
        {
            if (static_cast<int>(words[j].length()) > columnWidths[j])
            {
                columnWidths[j] = words[j].length();
            }
        }
    }

    // 포맷된 출력을 생성합니다.
    for (size_t i = 0; i < lines.size(); ++i)
    {
        for (size_t j = 0; j < lines[i].size(); ++j)
        {
            std::cout << lines[i][j];
            if (j < lines[i].size() - 1)
            { // 마지막 열이 아니라면 공백을 추가합니다.
                int spaces = columnWidths[j] - lines[i][j].length() + 1;
                for (int k = 0; k < spaces; ++k)
                {
                    std::cout << ' ';
                }
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
