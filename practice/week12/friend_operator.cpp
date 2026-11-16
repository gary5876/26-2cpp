// 2026-11-16
// << 연산자 중복: 프렌드 비멤버 함수로 정의
#include <iostream>
using namespace std;

class MyVector
{
private:
    double x, y;
public:
    MyVector(double xvalue = 0.0, double yvalue = 0.0) : x(xvalue), y(yvalue) { }

    // 좌측 피연산자 ostream: 멤버 함수 불가, 비멤버로 정의
    friend ostream& operator<<(ostream& os, const MyVector& v) {
        os << "(" << v.x << "," << v.y << ")" << endl;
        return os; // 연쇄 출력용 참조 반환
    }
};

int main()
{
    MyVector v1(1.0, 2.0), v2(3.0, 4.0), v3;
    cout << v1 << v2 << v3;
    return 0;
}
