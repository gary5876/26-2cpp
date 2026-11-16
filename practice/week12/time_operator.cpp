// 2026-11-16
// == 및 != 연산자 중복: 시각 비교
#include <iostream>
using namespace std;

class Time
{
    int hour, min, sec;
public:
    Time(int h = 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) { }

    bool operator==(Time& t2) {
        return (hour == t2.hour &&
                min == t2.min &&
                sec == t2.sec);
    }

    bool operator!=(Time& t2) {
        return !(*this == t2); // == 재사용
    }
};

int main()
{
    Time t1(1, 2, 3), t2(1, 2, 3);

    cout.setf(cout.boolalpha); // 1/0 대신 true/false 출력
    cout << (t1 == t2) << endl;
    cout << (t1 != t2) << endl;
    return 0;
}
