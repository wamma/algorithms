#include <iostream>

namespace mystd
{
	using namespace std;

	class ostream
	{
	public:
		void operator<< (const char *str)
		{
			printf("%s", str);
		}
		void operator<< (char str)
		{
			printf("%c", str);
		}
		void operator<< (int num)
		{
			printf("%d", num);
		}
		void operator<< (double e)
		{
			printf("%g", e);
		}
		void operator<< (ostream& (*fp)(ostream &ostm))
		{
			fp(*this); // fp(ostream &ostm) = endl(ostream &ostm)
		}
	};

	ostream& endl(ostream &ostm)
	{
		ostm<<'\n';
		fflush(stdout); // fflush() : 스트림에 남아있는 데이터를 모두 출력
		return ostm;
	}
	ostream cout;
}

int main(void)
{
	using mystd::cout;
	using mystd::endl;

	cout<<"Simple String";
	cout<<endl;
	cout<<3.14;
	cout<<endl;
	cout<<123;
	endl(cout);
	return 0;
}

