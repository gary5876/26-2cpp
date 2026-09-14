// 입출력 함수(cin, cout) 연습: 이름을 입력받아서 출력하기
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    cout << "이름을 입력하시오: ";
    cin >> name;
    cout << name << "을 환영합니다." << endl;

    return 0;
}
