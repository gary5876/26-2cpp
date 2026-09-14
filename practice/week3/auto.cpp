// auto 키워드: 컴파일러가 변수/반환형의 자료형을 자동으로 추론(automatic type deduction)
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
