#include <iostream>
#include <vector>

int main()
{
	long long N, K;

	std::cin >> K >> N;
	std::vector<long long> lanCables(K);
	long long maxLanCableLength = 0;
	for (long long i = 0; i < K; i++)
	{
		std::cin >> lanCables[i];
		maxLanCableLength = std::max(maxLanCableLength, lanCables[i]);
	}

	long long left = 1;
	long long right = maxLanCableLength;
	long long answer = 0;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long lanCount = 0;

		for (int i = 0; i < K; ++i)
		{
			lanCount += lanCables[i] / mid;
		}
		if (lanCount >= N)
		{
			answer = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	std::cout << answer << std::endl;
	return 0;
}