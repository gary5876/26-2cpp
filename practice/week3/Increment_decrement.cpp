// 증감 연산자(++, --) 이해하기: 전위(prefix) vs 후위(postfix)
#include <iostream>
using namespace std;

int main()
{
    int x = 1;

    cout << "x = " << x++ << endl;   // 사용 후 +1 : 1 출력, x는 2가 됨
    cout << "x = " << x++ << endl;   // 사용 후 +1 : 2 출력, x는 3이 됨
    cout << "x = " << ++x << endl;   // +1 후 사용 : x는 4가 되고 4 출력
    cout << "x = " << x-- << endl;   // 사용 후 -1 : 4 출력, x는 3이 됨
    cout << "x = " << x-- << endl;   // 사용 후 -1 : 3 출력, x는 2가 됨
    cout << "x = " << --x << endl;   // -1 후 사용 : x는 1이 되고 1 출력

    return 0;
}
