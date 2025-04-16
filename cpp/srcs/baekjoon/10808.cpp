#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    vector<int> alphabet_count(26, 0);

    for (int i = 0; i < S.size(); ++i)
    {
        int index = S[i] - 'a';
        alphabet_count[index]++;
    }

    for (int i = 0; i < alphabet_count.size(); ++i)
    {
        cout << alphabet_count[i] << " ";
    }
}