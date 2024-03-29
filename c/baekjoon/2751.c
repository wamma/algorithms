#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_pivot(int low, int high)
{
	return (low + rand() % (high - low + 1));
}

void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *arr, int low, int high)
{
    int random_pivot_index = random_pivot(low, high); // 난수 생성
    int pivot;

    swap(&arr[random_pivot_index], &arr[high]); // 난수와 high의 값을 swap
    pivot = arr[high];
    int left = low;
    int right = high;

    while (left < right)
    {
        while (left < right && arr[left] <= pivot)
            left++;
        while (left < right && arr[right] >= pivot)
            right--;
        if (left <= right)
            swap(&arr[left], &arr[right]);
    }
    swap(&arr[left], &arr[high]);
    return (left);
}


void	quick_sort(int *arr, int low, int high)
{
	int pivot;

	if (low < high)
    {
        pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot - 1); // pivot보다 작은 값들을 정렬
        quick_sort(arr, pivot + 1, high); // pivot보다 큰 값들을 정렬
    }

}

int main(void)
{
	int size;
	scanf("%d", &size);

	int arr[size];
	for (int i = 0; i < size; i++)
		scanf("%d", &arr[i]);
    srand(time(NULL)); // 난수 생성을 위한 srand 함수
	quick_sort(arr, 0, size - 1);
	for (int i = 0; i < size; i++)
		printf("%d\n", arr[i]);
	return (0);
}