#include <iostream>
#include <stack>
using namespace std;

template <typename T> class MyQueue
{
  private:
    stack<T> s1, s2; // s1:입력 스택, s2: 출력 스택

  public:
    void push(const T &x)
    {
        s1.push(x);
    }

    void pop()
    {
        if (empty()) {
			throw out_of_range("Queue is empty");
		}

		if (s2.empty()) {
			while (!s1.empty())
		}
    }
}

int main()
{
}