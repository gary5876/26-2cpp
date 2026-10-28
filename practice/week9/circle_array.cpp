// 2026-10-28
// Circle 객체 배열 생성 및 난수 초기화
#include <iostream>
#include <cstdlib>
using namespace std;

// 원 클래스
class Circle
{
public:
    int x, y;   // 중심 좌표
    int radius; // 반지름
    Circle() {
        x = 0;
        y = 0;
        radius = 0;
    }
    Circle(int x, int y, int r) {
        this->x = x; // 멤버와 매개변수 이름 동일 시 this로 구분
        this->y = y;
        this->radius = r;
    }
    void Print() {
        cout << "반지름: " << radius << " @(" << x << ", " << y << ")" << endl;
    }
};

int main(void)
{
    Circle objArray[10]; // 기본 생성자 호출, 전부 0

    // & 생략 시 c는 원소의 복사본 -> 복사본만 수정, 원본 배열 불변 (전부 0 출력)
    for (Circle& c : objArray) {
        c.x = rand() % 500;
        c.y = rand() % 300;
        c.radius = rand() % 100;
    }
    for (Circle c : objArray) // 읽기 전용, 복사본으로 충분
        c.Print();

    return 0;
}
