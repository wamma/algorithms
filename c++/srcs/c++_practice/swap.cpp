#include <iostream>

void	swap_value(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int x = 5;
	int y = 10;
	std::cout<<"before swap x = "<<x<<", y = "<<y<<std::endl;
	swap_value(x, y);
	std::cout<<"after swap x = "<<x<<", y = "<<y<<std::endl;
	return 0;
}