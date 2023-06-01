#include <iostream>

int	&reference_one(int &ref)
{
	ref++;
	return ref;
}

int main(void)
{
	int num1=1;
	int &num2=reference_one(num1);

	num1++;
	num2++;
	std::cout<<"num1: "<<num1<<"\n";
	std::cout<<"num2: "<<num2<<"\n";
	return 0;
}