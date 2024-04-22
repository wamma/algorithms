#include <iostream>
#include <vector>

using namespace std;

int countLength(const vector<string> &arr, int x, int y, int dx, int dy)
{
    int length = 0;
    int N = arr.size();
    x += dx;
    y += dy;
    while (x >= 0 && x < N && y >= 0 && y < N && arr[x][y] == '*')
    {
        length++;
        x += dx;
        y += dy;
    }
    return length;
}

int main()
{
    // _는 아무것도 아님
    // *는 신체 일부
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<string> arr(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    int heartX = -1, heartY = -1;
    bool found = false;
    for (int i = 1; i <= N - 1 && !found; ++i)
    {
        for (int j = 1; j <= N - 1 && !found; ++j)
        {
            if (arr[i][j] == '*' && arr[i - 1][j] == '*' && arr[i + 1][j] == '*' && arr[i][j - 1] == '*' &&
                arr[i][j + 1] == '*')
            {
                heartX = i;
                heartY = j;
                found = true;
                break;
            }
        }
    }

    // (0, -1): 왼쪽 방향(왼쪽 팔 길이 측정)
    // (0, 1): 오른쪽 방향(오른쪽 팔 길이 측정)
    // (1, 0): 아래 방향(허리와 다리 길이 측정)
    int leftArmLength = countLength(arr, heartX, heartY, 0, -1);
    int rightArmLength = countLength(arr, heartX, heartY, 0, 1);
    int waistLength = countLength(arr, heartX, heartY, 1, 0);
    int leftLegLength = countLength(arr, heartX + waistLength, heartY - 1, 1, 0);
    int rightLegLength = countLength(arr, heartX + waistLength, heartY + 1, 1, 0);
    cout << heartX + 1 << " " << heartY + 1 << '\n';
    cout << leftArmLength << " " << rightArmLength << " " << waistLength << " " << leftLegLength << " "
         << rightLegLength << '\n';
    return 0;
}