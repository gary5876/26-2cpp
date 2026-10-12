// 2026-10-12
// Circle 클래스를 정의하고 객체를 만들어 원의 면적을 출력하는 프로그램
#include <iostream>
#include <string>
using namespace std;

// 원을 나타내는 클래스 (객체의 설계도)
class Circle {
public: // 접근 지정자: 클래스 외부(main)에서도 아래 멤버에 접근 가능
    // 멤버 변수 (객체의 상태)
    int radius;     // 반지름
    string color;   // 색상

    // 멤버 함수 (객체의 동작): 자신의 반지름으로 원의 면적을 계산해 반환
    double CalcArea() {
        return 3.14 * radius * radius;
    }
};

int main() {
    Circle obj; // obj는 Circle 자료형의 변수 (Circle 클래스로 만든 객체)

    // 객체이름.멤버 형태로 obj의 멤버 변수에 값 저장
    obj.radius = 100;
    obj.color = "blue";

    // obj의 멤버 함수를 호출해 면적 출력 (3.14 * 100 * 100 = 31400)
    cout << "원의 면적=" << obj.CalcArea() << "\n";
    return 0;
}
