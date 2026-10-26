// 2026-10-26
// Car 클래스 멤버 함수 정의부
#include "car.h" // 사용자 정의 헤더는 "" 사용

// 속도 반환 (클래스명::함수명)
int Car::getSpeed()
{
    return speed;
}

// 속도 설정
void Car::setSpeed(int s)
{
    speed = s;
}
