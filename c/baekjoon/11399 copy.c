#include <stdio.h>
#include <stdlib.h>

int N, P, arr[1001];

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[low + rand() % (high - low + 1)]; // pivot 선정
        int left = low;
        int right = high;

        while (left <= right)
        {
            while (arr[left] < pivot)
                left++;

            while (arr[right] > pivot)
                right--;

            if (left <= right)
            {
                swap(&arr[left], &arr[right]);
                left++;
                right--;
            }
        }
        quick_sort(arr, low, right);
        quick_sort(arr, left, high);
    }
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
	quick_sort(arr, 0, N - 1);
	result = algorithmn();
	printf("%d\n", result);
}
