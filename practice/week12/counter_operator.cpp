// 2026-11-16
// ++ 연산자 중복: 전위, 후위 구분
// 21쪽 ==, != 연산자 중복 반영: 카운터 값 비교
#include <iostream>
using namespace std;

class Counter {
private:
    int value;
public:
    Counter() : value{0} { }
    ~Counter() { }
    int getValue() const { return value; }
    void setValue(int x) { value = x; }

    Counter& operator++() { // 전위: 증가 후 자기 참조 반환
        ++value;
        return *this;
    }
    Counter operator++(int) { // 후위: int는 구분용
        Counter temp = *this;
        ++value;
        return temp; // 증가 전 사본 반환
    }

    bool operator==(Counter& c2) {
        return value == c2.value;
    }
    bool operator!=(Counter& c2) {
        return !(*this == c2); // == 재사용
    }
};

int main()
{
    Counter c1, c2;
    cout << "카운터의 값: " << c1.getValue() << endl;
    ++c1; // 전위
    cout << "카운터의 값: " << c1.getValue() << endl;
    c2++; // 후위
    cout << "카운터의 값: " << c2.getValue() << endl;

    cout.setf(cout.boolalpha); // 1/0 대신 true/false 출력
    cout << (c1 == c2) << endl; // 동일 값 1: true
    cout << (c1 != c2) << endl; // false
    return 0;
}
