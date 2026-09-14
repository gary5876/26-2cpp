// 상수(constant) 연습: symbolic 상수(#define), literal 상수, const 상수
#include <iostream>
#define PI 3.14159265359      // PI가 기호(symbolic) 상수
using namespace std;

int main()
{
    int income = 1000;                 // 1000이 리터럴(literal) 상수
    const double TAX_RATE = 0.25;      // TAX_RATE가 const(타입을 가지는) 상수 변수
    income = income - TAX_RATE * income;

    double x = 100;
    x = x * PI;

    cout << x << endl;
    return 0;
}
