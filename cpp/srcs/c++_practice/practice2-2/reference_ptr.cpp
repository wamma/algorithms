#include <iostream>
using namespace std;

int main()
{
	int num = 12;
	int *ptr = &num;
	int **double_ptr = &ptr;

	int &reference = num;
	int *(&p_reference) = ptr;
	int **(d_p_reference) = double_ptr;

	cout<<reference<<endl;
	cout<<*p_reference<<endl; //p_reference는 포인터 변수 ptr의 참조자이므로, 변수 num에 저장된 값 출력
	cout<<**d_p_reference<<endl; //d_p_reference는 포인터 변수 double_ptr의 참조자이므로, 변수 num에 저장된 값 출력
	return 0;
}