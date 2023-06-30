#include <iostream>

class Position {
	private:
		int x;
		int y;

	public:
		Position(int x, int y): x(x), y(y) {}

		friend Position operator+(const Position& pos1, const Position& pos2) {
			int newX = pos1.x + pos2.x;
			int newY = pos1.y + pos2.y;
			return Position(newX, newY);
		}

		int getX() const { return x; }
		int getY() const { return y; }
};

int main()
{
	Position pos1(3, 5);
	Position pos2(2, 7);

	Position result = operator+(pos1, pos2);

	std::cout<<"pos1=("<<pos1.getX()<<", "<<pos1.getY()<<")\n";
	std::cout<<"pos2=("<<pos2.getX()<<", "<<pos2.getY()<<")\n";
	std::cout<<"result=("<<result.getX()<<", "<<result.getY()<<")\n";
	return 0;
}