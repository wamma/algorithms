#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";
    stringstream ss(s);
    string token;
    vector<int> numbers;

    while (ss >> token)
        numbers.push_back(stoi(token));

    int minValue = *min_element(numbers.begin(), numbers.end());
    int maxValue = *max_element(numbers.begin(), numbers.end());

    answer = to_string(minValue) + " " + to_string(maxValue);
    return answer;
}

int main()
{
    string s = "1 2 3 4";
    string result = solution(s);

    cout << result << '\n';
    return 0;
}

/*
입출력 예
s				return
"1 2 3 4"		"1 4"
"-1 -2 -3 -4"	"-4 -1"
"-1 -1"			"-1 -1"
*/