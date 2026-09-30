// 2026-09-30
// 매개변수 개수가 다른 중복 함수(overloaded function)를 호출하는 프로그램
#include <iostream>

// 두 숫자의 합 계산
int add(int a, int b) {
    return a + b;
}

// 세 숫자의 합 계산 (이름은 같지만 매개변수 개수가 달라 다른 함수로 사용됨)
int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    std::cout << "2 + 3 = " << add(2, 3) << std::endl;         // 두 숫자 버전 호출
    std::cout << "2 + 3 + 4 = " << add(2, 3, 4) << std::endl;  // 세 숫자 버전 호출
    return 0;
}
