#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling)
{
    int answer = 0;
    for (const string &word : babbling)
    {
        bool usedAya = false, usedYe = false, usedWoo = false, usedMa = false;
        bool isValid = true;

        string currentWord = word;

        while (!currentWord.empty() && isValid)
        {
            if (currentWord.substr(0, 3) == "aya" && !usedAya)
            {
                usedAya = true;
                currentWord = currentWord.substr(3);
            }
            else if (currentWord.substr(0, 2) == "ye" && !usedYe)
            {
                usedYe = true;
                currentWord = currentWord.substr(2);
            }
            else if (currentWord.substr(0, 3) == "woo" && !usedWoo)
            {
                usedWoo = true;
                currentWord = currentWord.substr(3);
            }
            else if (currentWord.substr(0, 2) == "ma" && !usedMa)
            {
                usedMa = true;
                currentWord = currentWord.substr(2);
            }
            else
            {
                isValid = false;
            }
        }
        if (isValid && currentWord.empty())
        {
            answer++;
        }
    }
    return answer;
}