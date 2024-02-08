#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int arr[100000];

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	int closestSum = 200000000;
	int left = 0;
	int right = N - 1;

	while (left < right)
	{
		int sum = arr[left] + arr[right];
		if (abs(sum) <= abs(closestSum))
		{
			closestSum = sum;
		}
		if (sum > 0)
		{
			right--;
		}
		else
		{
			left++;
		}
	}
	cout << closestSum << endl;
}

