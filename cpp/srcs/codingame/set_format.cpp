#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 함수: 문자열을 소문자로 변환
string toLowerCase(const string &str)
{
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// 함수: 문자열의 첫 글자를 대문자로 변환
string capitalize(const string &str)
{
    if (str.empty())
        return str;
    string capStr = toLowerCase(str);
    capStr[0] = toupper(capStr[0]);
    return capStr;
}

int main()
{
    string name;
    getline(cin, name);
    string format;
    cin >> format;

    vector<string> words;
    string currentWord;

    // 단어를 분리하고 포맷에 따라 변환
    for (size_t i = 0; i < name.size(); ++i)
    {
        if (isalpha(name[i]))
        {
            currentWord += tolower(name[i]);
        }
        else if (!currentWord.empty())
        {
            words.push_back(currentWord);
            currentWord.clear();
        }
    }
    if (!currentWord.empty())
    {
        words.push_back(currentWord);
    }

    if (format == "snake_case")
    {
        for (size_t i = 0; i < words.size(); ++i)
        {
            cout << (i > 0 ? "_" : "") << words[i];
        }
    }
    else if (format == "camelCase")
    {
        for (size_t i = 0; i < words.size(); ++i)
        {
            cout << (i == 0 ? toLowerCase(words[i]) : capitalize(words[i]));
        }
    }
    else if (format == "PascalCase")
    {
        for (const auto &word : words)
        {
            cout << capitalize(word);
        }
    }
    cout << endl;

    return 0;
}
