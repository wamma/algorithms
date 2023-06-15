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

	~MyArray()
	{
		if (this->data == NULL)
			delete[]data;
	}

	MyArray(const MyArray& other)
	{
		this->size = other.size;
		this->data = new int[size]; // deep copy

		for (int i = 0; i < size; i++)
			this->data[i] = other.data[i];
	}
};

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

