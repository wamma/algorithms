#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

	return ;
}

int	random_pivot(int low, int high)
{
	return (rand() % (high - low + 1) + low);
}

int	partition(int *arr, int low, int high)
{
	int i = low - 1;
	int j = low;
	int pivot_index = random_pivot(low, high);
	int pivot = arr[pivot_index];
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		} 
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quick_sort(int *arr, int low, int high)
{
	int pivot;

	if (low >= high)
		return ;
	else
	{
		pivot = partition(arr, low, high);
		quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}

}

int main(void)
{
	int arr[1000000];
	int size;

	srand(time(NULL));
	scanf("%d", &size);
	for(int i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	quick_sort(arr, 0, size - 1);
	for (int i = 0; i < size; i++)
		printf("%d\n", arr[i]);
}
