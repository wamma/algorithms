#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_pivot(int low, int high)
{
	return (low + rand() % (high - low + 1));
}

int partition(int arr[], int low, int high) {
    int pivotIndex = random_pivot(low, high);
    int pivot = arr[pivotIndex];

    // 피벗을 오른쪽 끝으로 이동
    int temp = arr[pivotIndex];
    arr[pivotIndex] = arr[high];
    arr[high] = temp;

    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void	quick_sort(int *arr, int low, int high)
{
	int pivot;

	if (low >= high)
		return ;
	pivot = partition(arr, low, high);
	quick_sort(arr, low, pivot - 1);
	quick_sort(arr, pivot + 1, high);

}

int main(void)
{
	int arr[10] = {5, 4, 3, 2, 1};
	int size = sizeof(arr) / sizeof(int);
	srand(time(NULL));

	quick_sort(arr, 0, size - 1);
	int i = -1;
	while (++i < size)
		printf("%d ", arr[i]);
	return (0);
}