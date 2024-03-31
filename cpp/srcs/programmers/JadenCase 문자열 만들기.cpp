#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";
    bool isNewWord = true;

    for (char &c : s)
    {
        if (c == ' ')
            isNewWord = true;
        else if (isNewWord)
        {
            c = toupper(c);
            isNewWord = false;
        }
        else
        {
            c = tolower(c);
        }
    }
    answer = s;
    return answer;
}