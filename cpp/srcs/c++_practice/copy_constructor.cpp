#include <iostream>

class MyArray
{
public:
	int size;
	int *data;

	MyArray(int size)
	{
		this->size = size;
		this->data = new int[size];
	}

	MyArray(const MyArray& other);
};

MyArray::MyArray(const MyArray &other) {
	this->size = other.size;
	this->data = other.data; // shallow copy
}

int main()
{
	MyArray buffer(10);
	buffer.data[0] = 2;

	MyArray clone = buffer;
	clone.data[0] = 5;

	std::cout <<"buffer.data[0] = "<< buffer.data[0] << std::endl;
	std::cout <<"clone.data[0] = "<< clone.data[0] << std::endl;

	std::cout<<"buffer address = "<<&buffer<<std::endl;
	std::cout<<"clone address = "<<&clone<<std::endl;
	return 0;
}