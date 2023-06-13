#include <iostream>
using namespace std;

bool	is_positive(int num)
{
	if (num <= 0)
		return false;
	else
		return true;
}

int main()
{
	bool is_pos;
	int num;
	cout<<"Input number: ";
	cin>>num;

	is_pos = is_positive(num);
	if (is_pos)
		cout<<"positive number"<<endl;
	else
		cout<<"negatice number"<<endl;
	return 0;
}