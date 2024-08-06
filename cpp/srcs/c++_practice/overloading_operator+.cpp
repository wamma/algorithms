#include <iostream>

class Position
{
  private:
    int x;
    int y;

  public:
    Position(int x, int y) : x(x), y(y)
    {
    }

    Position operator+(const Position &other) const
    {
        int newX = x + other.x;
        int newY = y + other.y;
        return Position(newX, newY);
    }

    int getX() const
    {
        return x;
    }
    int getY() const
    {
        return y;
    }
};

int main()
{
    Position pos1(3, 5);
    Position pos2(2, 7);

    Position result = pos1.operator+(pos2);

    std::cout << "pos1=(" << pos1.getX() << ", " << pos1.getY() << ")\n";
    std::cout << "pos2=(" << pos2.getX() << ", " << pos2.getY() << ")\n";
    std::cout << "result=(" << result.getX() << ", " << result.getY() << ")\n";

    return 0;
}