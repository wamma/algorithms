#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string sentence;
    getline(cin, sentence); // 사용자로부터 문장을 입력 받음

    istringstream iss(sentence); // istringstream을 사용하여 문장을 단어로 분리
    string word;

    while (iss >> word)
    {
        // 공백을 기준으로 단어를 읽음
        int wordValue = 0;
        for (size_t i = 0; i < word.length(); ++i)
        {
            // C++98에서는 size_t를 사용하여 문자열의 길이를 나타냄
            wordValue += static_cast<int>(word[i]); // 각 문자의 ASCII 값을 wordValue에 더함
        }
        cout << wordValue << endl; // 각 단어의 문자 코드 합을 출력
    }

    return 0;
}
