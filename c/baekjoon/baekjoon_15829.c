#include <stdio.h>

#define r 31
#define M 1234567891

/*예를 들어 L = 3 문자열 = xyz
1. x의 해시 값 : (24 * 1) % 1234567891 = 24
2. y의 해시 값 : (25 * 31) % 1234567891 = 775
3. z의 해시 값 : (26 * 961) % 1234567891 = 24976
4. sum = 24 + 775 + 24976 = 25775*/

int main(void)
{
	int L;
	char arr[51];
	long long sum = 0;
	long long R = 1; // 거듭제곱을 저장

	scanf("%d %s", &L, arr);

	for (int i = 0; i < L; i++)
	{
		sum += ((arr[i] - 'a' + 1) * R) % M; // (a * r) mod M -> (문자값 × r^(문자 인덱스)) % M
		R *= r % M; // pow(r, n) 값이 계속 커져서 mod M 해주는거
	}
	printf("%lld\n", sum);
	return (0);
}