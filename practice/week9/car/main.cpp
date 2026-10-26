// 2026-10-26
// Car 클래스 사용 (빌드: g++ car.cpp main.cpp -o car_main)
#include "car.h" // 클래스 선언 포함
using namespace std;

int main()
{
    Car myCar; // 객체 생성

    myCar.setSpeed(80); // private이므로 setter 사용
    cout << "현재 속도는 ";
    cout << myCar.getSpeed(); // 80

    return 0;
}
