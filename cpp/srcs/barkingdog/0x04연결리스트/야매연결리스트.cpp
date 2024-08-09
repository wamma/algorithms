#include <algorithm>
#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = -1;

void insert(int addr, int num)
{
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr] != -1)
        pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr)
{
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1)
        pre[nxt[addr]] = pre[addr];
}

int main()
{
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);

    dat[0] = -1;
    nxt[0] = -1;

    insert(1, 65);
    insert(2, 13);
    insert(4, 21);
    insert(5, 17);

    int cur = nxt[0];
    while (cur != -1)
    {
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    return 0;
}
