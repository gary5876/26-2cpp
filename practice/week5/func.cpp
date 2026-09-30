// 2026-09-30
// 매개변수 기본값(초기화 값)을 가진 함수를 호출하는 프로그램
#include <iostream>
using namespace std;

// 두 정수의 합을 반환하는 함수 (value2를 생략하면 기본값 0 사용)
int Sum(int value1, int value2 = 0) {
    int result = value1 + value2;
    return result;
}

int main() {
    int a = 2, b = 3;
    // 1. 매개변수로 a, b 보냄
    int value = Sum(a, b);
    cout << value << endl;

    // 2. 매개변수 a만 보냄 (value2는 기본값 0)
    value = Sum(a);
    cout << value << endl;

    return 0;
}
