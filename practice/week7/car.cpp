// 2026-10-12
// 자동차를 Car 클래스로 추상화하고 멤버 함수로 속도를 올리고 내리는 프로그램
#include <iostream>
#include <string>
using namespace std;

// 자동차를 나타내는 클래스 (상태: 속도, 기어, 색상 / 동작: 가속, 감속)
class Car {
public:
    // 멤버 변수 선언
    int speed; // 속도
    int gear; // 기어
    string color; // 색상

    // 멤버 함수 선언
    void SpeedUp() { // 속도 증가 멤버 함수
        speed += 10; // 이 함수를 호출한 객체의 speed를 10 증가
    }

    void SpeedDown() { // 속도 감소 멤버 함수
        speed -= 10; // 이 함수를 호출한 객체의 speed를 10 감소
    }
};

int main()
{
    Car myCar; // Car 클래스로 myCar 객체 생성

    // myCar의 멤버 변수 초기화
    myCar.speed = 100;
    myCar.gear = 3;
    myCar.color = "red";

    cout << "1st speed: " << myCar.speed << endl; // 처음 속도 (100)

    myCar.SpeedUp(); // 속도 10 증가
    cout << "2nd speed: " << myCar.speed << endl; // 110

    myCar.SpeedDown(); // 속도 10 감소
    cout << "3rd speed: " << myCar.speed << endl; // 다시 100

    return 0;
}
