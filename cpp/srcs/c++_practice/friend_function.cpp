#include <iostream>

class B;

class A
{
private:
	int private_data;

public:
	A(int data) : private_data(data) {}

	void displayData()
	{
		std::cout << "A : private_data = " << private_data << std::endl;
	}

	friend class B;
};

class B
{
public:
	void modifyData(A& obj, int newData)
	{
		obj.private_data = newData;
	}
};

int main()
{
	A objA(5);
	B objB;

	objA.displayData(); // 초기값 출력

	objB.modifyData(objA, 10);

	objA.displayData(); // 변경된 값 출력

	return 0;
}