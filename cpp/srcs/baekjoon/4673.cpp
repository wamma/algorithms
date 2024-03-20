#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int LIMIT = 10000;
    vector<bool> isSelfNumber(LIMIT + 1, true); // 모든 숫자를 셀프 넘버로 초기화

    for (int currentNumber = 1; currentNumber <= LIMIT; ++currentNumber)
    {
        int sum = currentNumber;
        int numberToAdd = currentNumber;

        // 현재 숫자와 그 숫자의 각 자릿수를 더함
        while (numberToAdd > 0)
        {
            sum += numberToAdd % 10;
            numberToAdd /= 10;
        }

        // 생성된 숫자는 셀프 넘버가 아님
        if (sum <= LIMIT)
        {
            isSelfNumber[sum] = false;
        }
    }

    // 셀프 넘버 출력
    for (int i = 1; i <= LIMIT; ++i)
    {
        if (isSelfNumber[i] == true)
        {
            cout << i << endl;
        }
    }

    return 0;
}
