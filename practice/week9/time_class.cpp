// 2026-10-26
// 생성자를 이용한 Time 객체 초기화
// 원본: Time(int h, int m)만 존재 -> Time a; 생성 시 에러 (기본 생성자 부재)
// 해결: 디폴트 매개변수 사용 (생성자 중복 정의 Time(){}도 가능, 단 멤버 미초기화)
#include <iostream>
using namespace std;

// 시각(시, 분) 클래스
class Time {
public:
    int hour;   // 시를 나타낸다. 0-23까지 가능하다.
    int minute; // 분을 나타낸다. 0-59까지 가능하다.

    // 생성자: 인자 생략 시 0으로 초기화
    Time(int h = 0, int m = 0) {
        hour = h;
        minute = m;
    }

    // "시:분" 형식 출력
    void Print() {
        cout << hour << ":" << minute << endl;
    }
};

int main()
{
    Time a;                 // ① 디폴트 매개변수 적용 (0:0)
    Time b(10, 30);         // ② OK 하지만 예전의 방법이다.
    Time c{ 10, 40 };       // ③ OK 최신의 방법이다.
    Time d = { 10, 50 };    // ④ OK 하지만 간결하지 않다.

    a.Print(); // 0:0
    b.Print(); // 10:30
    c.Print(); // 10:40
    d.Print(); // 10:50
    return 0;
}
