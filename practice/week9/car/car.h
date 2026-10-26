// 2026-10-26
// Car 클래스 선언부 (정의는 car.cpp)
#include <iostream>
#include <string>
using namespace std;

// 자동차 클래스
class Car
{
    // 기본값 private
    int speed;    //속도
    int gear;     //기어
    string color; //색상
public:
    int getSpeed();       // getter
    void setSpeed(int s); // setter
};
