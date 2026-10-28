// 2026-10-26
// 접근 지정자와 getter/setter를 활용한 Time 클래스
// [에러 원인] hour가 private -> 클래스 외부(main)에서 a.hour 접근 불가
// [수정] hour를 public으로 이동 (minute는 private 유지, setter로만 접근)
#include <iostream>
using namespace std;

// 시각(시, 분) 클래스
class Time {
private: // 클래스 내부에서만 접근 가능
    int minute; // 0-59
public:  // 외부에서도 접근 가능
    int hour;   // 0-23 (public으로 이동)

    // 멤버 함수 선언 (정의는 클래스 외부)
    Time(int h, int m);
    void IncHour();
    void Print();

    // getter
    int GetHour() { return hour; }
    int GetMinute() { return minute; }
    // setter
    void SetHour(int h) { hour = h; }
    void SetMinute(int m) { minute = m; }
};

// 생성자 외부 정의 (클래스명::함수명)
Time::Time(int h, int m) {
    hour = h;
    minute = m;
}

// 시 1 증가, 23 초과 시 0
void Time::IncHour() {
    ++hour;
    if (hour > 23)
        hour = 0;
}

// "시:분" 형식 출력
void Time::Print() {
    cout << hour << ":" << minute << endl;
}

int main()
{
    Time a{ 0, 0 };  // 0:0 초기화
    a.hour = 10;     // public이므로 접근 가능
    a.SetHour(6);    // setter로 설정
    a.SetMinute(30); // private이므로 setter로만 설정

    a.Print(); // 6:30
    return 0;
}
