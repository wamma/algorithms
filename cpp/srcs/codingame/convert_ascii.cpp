#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string line;
    getline(cin, line);

    int sum = 0;
    for (size_t i = 0; i < line.length(); ++i)
    {
        sum += static_cast<int>(line[i]);
    }
    int result = floor(sqrt(sum));
    cout << result << endl;
    return 0;
}