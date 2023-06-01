#include <stdio.h>

void	swap_value(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int x = 5;
	int y = 10;

	printf("before swap x = %d, y = %d\n", x, y);
	swap_value(&x, &y);
	printf("after swap x = %d, y = %d\n", x, y);
}