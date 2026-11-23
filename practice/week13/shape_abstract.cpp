// 2026-11-23
// 순수 가상함수 draw: Shape는 추상 클래스, Rect에서 구현 필수
#include <iostream>
using namespace std;

class Shape {
protected:
    int x, y;

public:
    Shape(int x, int y) : x(x), y(y) { }
    virtual void draw() = 0; // 순수 가상함수
};

class Rect : public Shape {
private:
    int width, height;

public:
    Rect(int x, int y, int w, int h) : Shape(x, y), width(w), height(h) { }
    void draw() { // 미구현 시 에러
        cout << "Rectangle Draw" << endl;
    }
};

int main()
{
    Shape* ps = new Rect(0, 0, 100, 100); // OK!
    ps->draw();                           // Rectangle의 draw() 호출
    delete ps;

    return 0;
}
