#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int s;
    cin >> s;
    cin.ignore();

    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            cout << "+";
        }
        cout << endl;
    }
    return 0;
}