#include <iostream>

class B;

class A
{
private:
	int private_data;

public:
	A(int data) : private_data(data) {}

	void displayData(B& objB);
};

class B
{
private:
	int private_data;

public:
	B(int data) : private_data(data) {}

	friend class A;

	void displayData(A& objA){
		std::cout<<"B: privateData = "<<private_data<<std::endl;
		std::
	}
}