// 2026-10-28
// vector에 Circle 객체 저장 (크기 미지정, push_back으로 추가)
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

// 원 클래스
class Circle
{
public:
    int x, y;   // 중심 좌표
    int radius; // 반지름
    Circle() { x = 0; y = 0; radius = 0; }
    Circle(int x, int y, int r) {
        this->x = x;
        this->y = y;
        this->radius = r;
    }
    void Print() {
        cout << "반지름: " << radius << " @(" << x << ", " << y << ")" << endl;
    }
};

int main(void)
{
    vector<Circle> objArray;

    for (int i = 0; i < 10; i++) {
        Circle obj{ rand() % 300, rand() % 300, rand() % 100 };
        objArray.push_back(obj); // obj의 복사본 저장
    }
    for (Circle c : objArray)
        c.Print();

    return 0;
}
