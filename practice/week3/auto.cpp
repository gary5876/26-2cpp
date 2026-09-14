// 2026-09-14
#include <iostream>
using namespace std;

auto add(int x, int y)
{
    return x + y;
}

int main()
{
    auto d = 1.0;          // double로 추론됨
    auto sum = add(5, 6);  // add()의 반환형인 int로 추론됨

    cout << sum;
    return 0;
}
