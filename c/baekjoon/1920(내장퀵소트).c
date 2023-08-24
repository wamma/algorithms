#include <stdio.h>
#include <stdlib.h>

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

int binary_search(int *arrN, int key, int low, int high)
{
    int mid_value;
    int i = 0;

    while (low <= high)
    {
        mid_value = (low + high) / 2;
        if (key == arrN[mid_value])
            return (1);
        else if (key > arrN[mid_value])
            low = mid_value + 1;
        else
            high = mid_value - 1;
    }
    return (0);
}

/*arrN을 오름차순으로 정렬하고 arrM의 value가 arrN에 있으면 1, 없으면 0*/
int main(void)
{
    int N, M;
    int arrN[100000];
    int arrM[100000];

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf( "%d", &arrN[i]);
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
        scanf(" %d", &arrM[i]);
    qsort(arrN, N, sizeof(int), compare);
    for (int i = 0; i < M; i++)
        printf("%d\n", binary_search(arrN, arrM[i], 0, N - 1));
    return (0);
}
