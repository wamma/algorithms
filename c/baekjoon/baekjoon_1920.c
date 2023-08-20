#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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


void    quick_sort(int *arr, int low, int high)
{
	int pivot;

	if (low < high)
    {
        pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}
int binary_search(int *arrN, int key, int low, int high)
{
    int mid_value;
    int i = 0;

    while (arrN[i] != NULL)
    {
        mid_value = (low + high) / 2;
        if (key == mid_value)
            return (1);
        else if (key > mid_value)
    }
    return (0);
}


/*arrN을 오름차순으로 정렬하고 arrM의 value가 arrN에 있으면 1, 없으면 0*/
int main(void)
{
    int N, M;
    int arrN[100000];
    int arrM[100000];

    srand(time(NULL));

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arrN[i]);
    scanf("%d\n", &M);
    for (int i = 0; i < M; i++)
        scanf("%d\n", arrM[i]);
    quick_sort(arrN, 0, N - 1); // arrN 정렬
    for (int i = 0; i < M; i++)
        printf("%d\n", binary_search(arrN, arrM[i], 0, N - 1));
    return (0);
}
