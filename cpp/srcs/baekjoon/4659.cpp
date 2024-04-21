#include <iostream>
#include <string>

using namespace std;

bool hasMo(string word)
{
    for (char c : word)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }
    }
    return false;
}

bool isValidPassword(const std::string &word)
{
    if (!hasMo(word))
        return false;
    int moCount = 0, jaCount = 0;
    char lastChar = ' ';

    for (char c : word)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            moCount++;
            jaCount = 0;
        }
        else
        {
            jaCount++;
            moCount = 0;
        }

        if (moCount >= 3 || jaCount >= 3)
            return false;
        if (lastChar == c && c != 'e' && c != 'o')
            return false;
        lastChar = c;
    }

    return true;
}

int main()
{
    // 영어 모음 하나가 꼭 있어야 함.
    // 모음 혹은 자음이 3개 연속 x
    // 같은 글자가 연속 안되지만 (ee, oo은 됨)
    // 대문자 포함되면 안됨
    // end로 끝남.
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string word;
    while (cin >> word && word != "end")
    {
        if (isValidPassword(word))
        {
            cout << "<" << word << "> is acceptable." << '\n';
        }
        else
        {
            cout << "<" << word << "> is not acceptable." << '\n';
        }
    }
}