// 2026-10-12
// Circle 클래스로 피자 객체 2개를 만들어 각각의 면적을 출력하는 프로그램
// 하나의 클래스로 여러 객체를 만들 수 있고, 각 객체의 멤버 변수 값은 서로 다름
#include <iostream>
#include <string>
using namespace std;

// 원을 나타내는 클래스 (객체의 설계도)
class Circle {
public: // 접근 지정자: 클래스 외부(main)에서도 아래 멤버에 접근 가능
    // 멤버 변수 (객체의 상태)
    int radius;   // 반지름
    string color; // 색상

    // 멤버 함수 (객체의 동작): 자신의 반지름으로 원의 면적을 계산해 반환
    double CalcArea() {
        return 3.14 * radius * radius;
    }
};

int main()
{
    // Circle 클래스로 객체 2개 생성 (클래스 이름을 자료형처럼 사용)
    Circle pizza1, pizza2;

    // 객체이름.멤버 형태로 pizza1의 멤버 변수에 값 저장
    pizza1.radius = 100;
    pizza1.color = "yellow";
    cout << "피자의 면적=" << pizza1.CalcArea() << "\n"; // pizza1의 radius(100)로 계산

    // pizza2는 pizza1과 별개의 객체이므로 멤버 변수 값을 따로 가짐
    pizza2.radius = 200;
    pizza2.color = "white";
    cout << "피자의 면적=" << pizza2.CalcArea() << "\n"; // pizza2의 radius(200)로 계산
    return 0;
}
