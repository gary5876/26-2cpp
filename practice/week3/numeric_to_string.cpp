// 숫자를 문자열로 바꾸는 to_string() 함수 연습
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "사과";
    string s2;

    // 왜 에러가 날까?
    // string("사과" + " ")과 int(10)를 +로 바로 이어붙일 수 없기 때문이다.
    // string과 결합하려면 숫자를 먼저 문자열로 변환해야 한다.
    // s2 = s1 + " " + 10 + "개";

    // to_string(10)으로 10을 문자열로 변환한 후 s1과 개 문자열과 통합되어 s2에 저장된다
    s2 = s1 + " " + to_string(10) + "개";
    cout << s2 << endl;

    return 0;
}
