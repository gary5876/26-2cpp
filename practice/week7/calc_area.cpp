// 2026-10-12
// 멤버 함수를 클래스 안에서는 선언만 하고 클래스 외부에서 정의하는 프로그램
// (클래스의 인터페이스와 구현을 분리)
#include <iostream>
#include <string>
using namespace std;

class Circle {
public:
    double calcArea(); // 멤버 함수의 선언만 작성 (구현은 클래스 외부에 있음)

    int radius;     // 반지름
    string color;   // 색상
};
// 클래스 외부에서 멤버 함수들이 정의된다.
// 클래스이름::함수이름 형태로 써서 Circle 클래스의 멤버 함수임을 알려줌
double Circle::calcArea() {
    return 3.14*radius*radius; // 클래스 외부에 정의해도 멤버 변수 radius를 그대로 사용 가능
}

int main()
{
    Circle c; // Circle 객체 생성
    c.radius = 10;
    cout << c.calcArea() << endl; // 3.14 * 10 * 10 = 314
    return 0;
}
