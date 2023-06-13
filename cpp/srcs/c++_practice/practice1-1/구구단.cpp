#include <iostream>

int main(void)
{
	int num, result;

	std::cout << "구구단 하고 싶은 숫자 : ";
	std::cin >> num;
	for (int i = 1; i < 10; i++)
	{
		result = num * i;
		std::cout << num << " * " << i << " = " << result << std::endl;
	}
}