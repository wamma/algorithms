#include <iostream>

class Complex {
	public:
		// 생성자
		Complex(double real, double imaginary): real_(real), imaginary_(imaginary) {}

		// 멤버 함함수수로 구현한 operator+
		Complex operator+(const Complex& other) const {
			return Complex(real_ + other.real_, imaginary_ + other.imaginary_);
		}

		// getter 함수 : 객체의 특정 속성 값을 반환해주는 멤버 함수
		double real() const { return real_; }
		double imaginary() const { return imaginary_; }
	private:
		double real_; // 복소수의 실수 부분
		double imaginary_; // 복소수의 허수 부분
};

int main() {
	// 복소수 객체 생성
	Complex a(1, 2); // a = 1 + 2i
	Complex b(3, 4); // b = 3 + 4i

	// 멤버 함수로 구현된 operator+를 사용하여 두 복소수의 합을 구함
	Complex c = a + b;

	std::cout<<"a=("<<a.real()<<", "<<a.imaginary()<<")\n"; // a = (1, 2)
	std::cout<<"b=("<<b.real()<<", "<<b.imaginary()<<")\n"; // b = (3, 4)
	std::cout<<"c=("<<c.real()<<", "<<c.imaginary()<<")\n"; // c = (4, 6)

	return 0;
}