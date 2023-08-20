#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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

int main(void)
{
    int N, M;
    int arrN[100000];
    int arrM[100000];

    srand(time(NULL));

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arrN[i]);

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
        scanf("%d", &arrM[i]);

    quick_sort(arrN, 0, N - 1); // arrN 정렬

    /* Binary Search */
    for (int i = 0; i < M; i++)
    {
        int key = arrM[i];
        int low = 0;
        int high = N - 1;
        int found = 0;

        while (low <= high)
        {
            int mid_value = (low + high) / 2;
            if (key == arrN[mid_value])
            {
                found = 1;
                break;
            }
            else if (key > arrN[mid_value])
                low = mid_value + 1;
            else
                high = mid_value - 1;
        }
        printf("%d\n", found);
    }
    return (0);
}
