#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
            result.push_back(nums[i] * nums[i]);
        sort(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = s.sortedSquares(nums);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}