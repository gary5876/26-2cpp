// 2026-11-04
// 포인터 선언, 주소 연산자(&), 역참조(*), 포인터 연산
#include <iostream>
using namespace std;

int main()
{
    int number = 10;
    // number의 주소를 p에 저장
    int *p = &number;

    // p가 가리키는 공간의 값 출력
    cout << *p << endl; // 10

    // 포인터 연산: +1 시 자료형 크기만큼 주소 증가
    int a = 5;
    int *a_ptr = &a;
    cout << a_ptr << endl;
    a_ptr += 1; // int: 4바이트 증가
    cout << a_ptr << endl;

    double b = 3.14;
    double *b_ptr = &b;
    cout << b_ptr << endl;
    b_ptr += 1; // double: 8바이트 증가
    cout << b_ptr << endl;
    return 0;
}
