#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		void	duplicateZeros(vector<int>& arr)
		{
			int i = 0;
			int j = 0;
			int size = arr.size();
			vector<int> tmp(size);
			while (i < size)
			{
				if (arr[j] == 0)
				{
					tmp[i++] = 0;
					if (i < size)
						tmp[i++] = 0;
				}
				else
					tmp[i++] = arr[j];
				j++;
			}
			arr = tmp;
		}
};

int main()
{
	Solution s;
	vector<int> arr = {1, 0, 2, 3, 0, 4, 5, 0};
	s.duplicateZeros(arr);
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
	return (0);
}