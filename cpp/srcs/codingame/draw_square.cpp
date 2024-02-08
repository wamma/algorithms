#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    cin.ignore();

    map<int, string> d;
    for (int i = 0; i < n; ++i)
    {
        int index;
        string label;
        cin >> index >> label;
        d[index] = label;
    }

    for (int i = 0; i < h; ++i)
    {
        if (i == 0 || i == h - 1)
        {
            cout << string(w, '-') << endl;
        }
        else
        {
            if (d.find(i + 1) != d.end())
            {
                cout << "|"
                     << d[i + 1]
                            .substr(0, min((int)d[i + 1].size(), w - 2))
                            .append(w - 2 - min((int)d[i + 1].size(), w - 2), ' ')
                            .c_str()
                     << "|" << endl;
            }
            else
            {
                cout << "|" << string(w - 2, ' ') << "|" << endl;
            }
        }
    }

    return 0;
}
