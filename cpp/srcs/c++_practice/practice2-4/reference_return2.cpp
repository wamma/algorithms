#include <iostream>

int	&reference_two(int &ref)
{
	ref++;
	return ref;
}

int main(void)
{
	int num1=1;
	int num2=reference_two(num1);

	num1 +=1;
	num2 +=100;
	std::cout<<"num1: "<<num1<<"\n";
	std::cout<<"num2: "<<num2<<"\n";
	return 0;
}