#include <iostream>

int main(void)
{
	char name[100];
	char phone[100];

	std::cout<<"이름 : ";
	std::cin>>name;
	
	std::cout<<"전화번호 : ";
	std::cin>>phone;

	std::cout<<"이름은 "<<name<<"이고\n"<<"전화번호는 "<<phone<<"입니다"<<std::endl;
}