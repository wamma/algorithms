#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		int findNumbers(vector<int> &nums)
		{
			int even = 0;

			for (int i = 0; i < nums.size(); i++)
			{
				int count = 0;
				int num = nums[i];

				while (num > 0)
				{
					num /= 10;
					count++;
				}

				if (count % 2 == 0)
					even++;
			}
			return even;
		}
};

int main()
{
	Solution s;
	vector<int> nums = {437, 315, 322, 431, 686, 264, 442};
	cout << s.findNumbers(nums) << endl; // 출력: 0
	return 0;
}
