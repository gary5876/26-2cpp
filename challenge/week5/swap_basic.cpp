// 2026-09-30
// 참조자 매개변수 대신 포인터 매개변수를 이용해 두 변수의 값을 바꾸는 swap 함수 프로그램
#include <iostream>
using namespace std;

// x, y는 호출한 쪽 변수의 주소를 저장하는 포인터
// *x, *y로 그 주소에 있는 원본 값에 접근하므로 여기서 바꾸면 원본 값도 바뀜
void swap(int* x, int* y) {
    int tmp; // 임시 저장소
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main() {
    int a = 100, b = 200;

    cout << "a=" << a << " b=" << b << endl;

    // 두 변수 내 값 변경 (&a, &b: 변수의 주소를 전달)
    swap(&a, &b);

    cout << "a=" << a << " b=" << b << endl;
    return 0;
}
