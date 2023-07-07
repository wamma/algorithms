#include <iostream>
#include <string>

class BankAccount {
	private:
		std::string owner;
		int account_number;
		double balance;

		// 외부에서 직접 접근할 수 없는, 클래스 내부용 멤버 함수
		void print_account_info() const {
			std::cout << "Owner: " << owner << std::endl;
			std::cout << "Account Number: " << account_number << std::endl;
			std::cout << "Balance: " << balance << std::endl;
		}

	public:
		BankAccount(const std::string& owner_name, int number, double initial_balance)
			: owner(owner_name), account_number(number), balance(initial_balance) {}

		// 입금 기능
		void deposit(double amount) {
			if (amount > 0) {
				balance += amount;
				std::cout << "Successfully deposited " << amount << " dollars.\n";
				print_account_info();
			} else {
				std::cout << "Invalid deposit amount. Please enter a positive value.\n";
			}
		}

		// 출금 기능
		void withdraw(double amount) {
			if (amount > 0 && balance >= amount) {
				balance -= amount;
				std::cout << "Successfully withdrew " << amount << " dollars.\n";
				print_account_info();
			} else {
				std::cout << "Invalid withdrawal amount or insufficient balance.\n";
			}
		}
};

int main()
{
	BankAccount my_account("John Doe", 123456, 500.00);

	my_account.deposit(200.00);    // 잔액 700.00
	my_account.withdraw(100.00);   // 잔액 600.00
	my_account.deposit(-300.00);   // 오류 메시지 출력

	return 0;
}
