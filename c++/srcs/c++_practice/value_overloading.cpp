#include <iostream>

void	my_func(void)
{
	std::cout<<"my_func(void) called"<<std::endl;
}

void	my_func(char c)
{
	std::cout<<"my_func(char c)called"<<std::endl;
}

void	my_func(int a, int b)
{
	std::cout<<"my_func(int a, int b) called"<<std::endl;
}

int main(void)
{
	my_func();
	my_func('A');
	my_func(12, 13);
	return 0;
}
