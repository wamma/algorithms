/*두 개의 정수 numBottles와 numExchange가 주어집니다.
numBottles는 처음에 가지고 있는 가득 찬 물병의 수를 나타냅니다. 한 번의 연산으로 다음 연산 중 하나를 수행할 수 있습니다:
가득 찬 물병을 얼마든지 마셔 빈 병으로 바꿉니다.
빈 물병과 가득 찬 물병 하나를 교환합니다. 그런 다음 교환 횟수를 1씩 늘립니다.
여러 개의 빈 병을 같은 값의 numExchange로 교환할 수 없다는 점에 유의하세요. 예를 들어, numBottles == 3이고 numExchange
== 1이면 빈 물병 3개를 가득 찬 물병 3개로 교환할 수 없습니다.
마실 수 있는 물병의 최대 개수를 반환합니다.

예제 1:
입력: numBottles = 13, numExchange = 6
Output: 15
설명: 위의 표는 가득 찬 물병, 빈 물병, numExchange 값 및 마신 물병의 수를 보여줍니다.

예제 2:
입력: numBottles = 10, numExchange = 3
Output: 13
설명: 위의 표는 가득 찬 물병, 빈 물병, numExchange 값 및 마신 물병의 수를 보여줍니다.
제약 조건:
1 <= numBottles <= 100
1 <= numExchange <= 100
*/

class Solution
{
  public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int drunkBottles = 0; // 마신 물병 수
        int emptyBottles = 0; // 현재 빈 물병 수
        while (numBottles > 0)
        {
            // 일단 다마신다.
            drunkBottles += numBottles;
            emptyBottles += numBottles;
            numBottles = 0;

            while (emptyBottles >= numExchange)
            {
                emptyBottles -= numExchange;
                numBottles += 1;
                numExchange += 1;
            }
        }
        return drunkBottles;
    }
};