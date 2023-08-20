#include <stdio.h>

#define r 31
#define M 1234567891

int main(void)
{
	int L;
	char arr[51];
	long long sum = 0;
	long long R = 1;

	scanf("%d %s", &L, arr);

	for (int i = 0; i < L; i++)
	{
		sum += ((arr[i] - 'a' + 1) * R) % M; // (a * r) mod M
		R *= r % M; // pow(r, n) 값이 계속 커져서 mod M 해주는거
	}
	printf("%lld\n", sum);
	return (0);
}