#include <iostream>

int main()
{
    int t, c, r; // t: 총 시간(초), c: 탱크 용량(리터), r: 초당 연료 공급 속도(리터)

    std::cin >> t >> c >> r;
    bool result = false;
    for (int i = 0; i < t; ++i)
    {
        if (r * t >= c)
        {
            result = true;
        }
        else
        {
            result = false;
        }
    }
    if (result == true)
        std::cout << "yes" << std::endl;
    else if (result == false)
        std::cout << "no" << std::endl;
    return 0;
}