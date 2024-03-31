#include <iostream>
#include <vector>

using namespace std;

/*주어진 것은 이진 배열 nums.
우리는 서브 배열 하위 배열의 인접한 두 요소가 같은 값을 갖지 않으면 교대로 호출합니다.
교대 서브배열의 개수를 nums로 반환합니다.

예제 1:
입력: nums = [0,1,1,1]
Output: 5
설명:
다음 하위 배열이 번갈아 사용됩니다: [0], [1], [1], [1], [0,1].

예제 2:
입력: nums = [1,0,1,0]
Output: 10
설명:
배열의 모든 서브 배열이 번갈아 가며 나타납니다. 선택할 수 있는 가능한 하위 배열은 10개입니다.

제약 조건:
1 <= nums.length <= 105
nums[i]는 0 또는 1입니다.
*/

class Solution
{
  public:
    long long countAlternatingSubarrays(vector<int> &nums)
    {
        long long result = nums.size(); // 일단 단일 배열도 추가 해야 해서
        int length = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[i - 1])
            {
                ++length;
                result += length - 1;
            }
            else
                length = 1;
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0, 1, 0, 1};
    cout << s.countAlternatingSubarrays(nums) << endl;
    return 0;
}