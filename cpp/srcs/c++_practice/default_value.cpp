#include <iostream>

int addr(int num1=1, int num2=2);
{
	return num1+num2;
}

int main(void)
{
	std::cout<<addr()<<std::endl;
	std::cout<<addr(5)<<std::endl; //이 경우 인자는 첫번쨰 매개변수로 전달된다.
	std::cout<<addr(3, 5)<<std::endl;
	return 0;
}