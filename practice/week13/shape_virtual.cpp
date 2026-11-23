// 2026-11-23
// 가상함수 Draw: Shape 포인터로 Rect의 Draw 호출 (동적 바인딩)
#include <iostream>
using namespace std;

class Shape {
protected:
    int x, y;

public:
    Shape(int x, int y) : x(x), y(y) { }
    virtual void Draw() {
        cout << "Shape Draw" << endl;
    }
};

class Rect : public Shape {
private:
    int width, height;

public:
    Rect(int x, int y, int w, int h) : Shape(x, y), width(w), height(h) { } // Shape() 생성자 호출 후 초기화
    void Draw() {
        cout << "Rectangle Draw" << endl;
    }
};

int main()
{
    Shape* ps = new Rect(0, 0, 100, 100); // OK!
    ps->Draw();                           // Rectangle Draw

    delete ps;

    return 0;
}
