class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int evenCount = 0;

        for (int num : nums) {
            int digits = 0;
            int tmp = num;

            while (tmp > 0) {
                tmp /= 10;
                digits++;
            }

            if (digits % 2 == 0) {
                evenCount++;
            }
        }

        return evenCount;
    }
};