#include <iostream>
#include <cstring>

class Person
{
private:
	const char *name;
	int age;
public:
	Person(const char *my_name, int my_age)
	{
		int len = strlen(my_name) + 1;
		name = new char[len];
		strncpy(const_cast<char*>(name), my_name, len);
		age = my_age;
	}
	void ShowPersonInfo() const
	{
		std::cout<<"이름 : "<<name<<std::endl;
		std::cout<<"나이 : "<<age<<std::endl;
	}
	~Person()
	{
		delete []name;
		std::cout<<"called destructor!"<<std::endl;
	}
};

int main(void)
{
	Person man1("hyungjup", 28);
	Person man2("shikim", 22);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}