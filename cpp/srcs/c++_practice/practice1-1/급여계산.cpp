#include <iostream>

int main(void)
{
	int sale_price, result;
	float percent = 0.12;

	while (1)
	{
	std::cout<<"판매 금액을 만원 단위로 입력(-1 to end) : ";
	std::cin>>sale_price;
	if (sale_price == -1)
		break ;
	result = 50 + sale_price * percent;
	std::cout<<"이번 달 급여: "<<result<<"만원"<<std::endl;
	}
	std::cout<<"프로그램을 종료합니다."<<std::endl;
}
