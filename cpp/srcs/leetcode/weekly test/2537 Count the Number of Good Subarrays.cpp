#include <map>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
  public:
    long long countGood(vector<int> &nums, int k)
    {
        unordered_map<int, long long> freq;
        long long pairCount = 0;
        int left = 0;
        long long result = 0;

        for (int right = 0; right < nums.size(); ++right)
        {
            int x = nums[right];

            pairCount += freq[x];
            freq[x]++;

            while (pairCount >= k)
            {
                result += nums.size() - right;

                freq[nums[left]]--;
                pairCount -= freq[nums[left]];
                left++;
            }
        }

        return result;
    }
};