#include <iostream>

class Animal {
	public:
		// 가상 함수로 선언
		virtual void makeSound() {
			std::cout << "동물이 소리를 낸다." << std::endl;
		}
};

class Dog : public Animal {
	public:
		void makeSound() override {
			std::cout << "강아지가 멍멍 짖는다!" << std::endl;
		}
};

class Cat : public Animal {
	public:
		void makeSound() override {
			std::cout << "고양이가 야옹야옹 운다!" << std::endl;
		}
};

int main() {
	Animal* Dogptr = new Dog();  // Dog 객체를 가리키는 Animal 포인터
	Animal* Catptr = new Cat();

	Dogptr->makeSound();  // 실제로는 Dog의 makeSound() 함수가 호출됩니다.
	Catptr->makeSound();

	delete Dogptr;
	delete Catptr;

	return 0;
}
