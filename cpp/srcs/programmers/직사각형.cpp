#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> v)
{
    int x1 = v[0][0], x2 = v[1][0], x3 = v[2][0];
    int y1 = v[0][1], y2 = v[1][1], y3 = v[2][1];

    int x, y;

    if (x1 == x2)
        x = x3;
    else if (x1 == x3)
        x = x2;
    else
        x = x1;

    if (y1 == y2)
        y = y3;
    else if (y1 == y3)
        y = y2;
    else
        y = y1;

    return {x, y};
}

int main()
{
    vector<vector<int>> v = {{1, 4}, {3, 4}, {3, 10}};

    vector<int> result = solution(v);

    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    return 0;
}