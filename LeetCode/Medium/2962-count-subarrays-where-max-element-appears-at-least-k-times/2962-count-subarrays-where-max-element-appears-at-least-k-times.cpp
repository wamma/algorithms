class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long count = 0;
        int n = nums.size();
        int maxValCount = *max_element(nums.begin(), nums.end());

        int left = 0, maxCount = 0;

        for (int right = 0; right < n; ++right) {
            if (nums[right] == maxValCount) {
                maxCount++;
            }

            while (maxCount >= k) {
                count += (n - right);
                if (nums[left] == maxValCount) {
                    maxCount--;
                }
                left++;
            }
        }

        return count;
    }
};