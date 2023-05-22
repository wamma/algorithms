#include <iostream>

int	square_volume(int length, int width=1, int height=1)
{
	return length * width * height;
}

int main(void)
{
	std::cout<<"[3, 3, 3] : "<<square_volume(3, 3, 3)<<std::endl;
	std::cout<<"[5, 5, D] : "<<square_volume(5, 5)<<std::endl;
	std::cout<<"[7, D, D] : "<<square_volume(7)<<std::endl;
	//std::cout<<"[D, D, D] : "<<square_volume()<<std::endl;
	return 0;
}
