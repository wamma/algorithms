#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> solution(vector<int> &arr)
{
    unordered_map<int, int> freq;
    // 코테 문제가 vector<int> arr 안에 [2,1,3,3] 이렇게 있는데 중복된 값이 있으면 결과값을 [2,1]이 되게 하는거다

    for (int x : arr)
    {
        ++freq[x];
    }

    vector<int> answer;
    for (int x : arr)
    {
        if (freq[x] == 1)
        {
            answer.push_back(x);
        }
    }
    if (answer.empty())
        answer.push_back(-1);
    return answer;
}

int main()
{
    vector<int> arr = {1, 2, 3, 3};
    vector<int> result;

    result = solution(arr);

    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    return 0;
}