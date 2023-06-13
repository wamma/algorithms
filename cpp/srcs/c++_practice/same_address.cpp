#include <iostream>

int main()
{
	int x = 5;
	int &ref = x;

	std::cout<<"x: "<<x<<std::endl;
	std::cout<<"ref: "<<ref<<std::endl;

	std::cout<<"Address of x: "<<&x<<std::endl;
	std::cout<<"Address of ref: "<<&ref<<std::endl;
}