#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high) {
	int random_pivot_index = low + rand() % (high - low);
	swap(&arr[random_pivot_index], &arr[high]);

	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return i + 1;
}

void quick_sort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = partition(arr, low, high);

		quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}
}

int main() {
	int arr[] = {5, 4, 3, 1, 2, 1};
	int n = sizeof(arr) / sizeof(arr[0]);

	srand(time(NULL));
	quick_sort(arr, 0, n - 1);

	printf("Sorted array is: \n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
