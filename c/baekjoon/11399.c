#include <stdio.h>
#include <stdlib.h>

int N, P, arr[1001];

int	compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if (num1 < num2)
		return (-1);
	if (num1 > num2)
		return (1);
	return (0);
}

int algorithmn(void)
{
	int sum = 0;
	int i = 0;
	int j;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i + 1; j++)
			sum += arr[j];
	}
	return (sum);
}

int main()
{
	int result = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &P);
		arr[i] = P;
	}
	qsort(arr, N, sizeof(int), compare);
	result = algorithmn();
	printf("%d\n", result);
}
