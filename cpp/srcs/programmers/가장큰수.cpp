#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers)
{
    vector<string> stringNumbers;

    for (int i = 0; i < numbers.size(); ++i)
    {
        stringNumbers.push_back(to_string(numbers[i]));
    }

    sort(stringNumbers.begin(), stringNumbers.end(), [](const string &a, const string &b) { return a + b > b + a; });

	string result;

	for (string s : stringNumbers) {
		result += s;
	}

	if (result[0] == '0') return "0";

	return result;
}include