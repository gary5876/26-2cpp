// 2026-11-18
// 상속 시 생성자, 소멸자 호출 순서 및 부모 생성자 명시 호출
#include <iostream>
using namespace std;

class Shape {
    int x, y;
public:
    Shape() {
        cout << "Shape 생성자() " << endl;
    }
    Shape(int xloc, int yloc) : x{xloc}, y{yloc} {
        cout << "Shape 생성자(xloc, yloc) " << endl;
    }
    ~Shape() {
        cout << "Shape 소멸자() " << endl;
    }
};

class Rectangle : public Shape {
    int width, height;
public:
    // 초기화 리스트로 부모 생성자 선택
    Rectangle(int x, int y, int w, int h) : Shape(x, y) {
        width = w;
        height = h;
        cout << "Rectangle 생성자(x, y, w, h)" << endl;
    }
    ~Rectangle() {
        cout << "Rectangle 소멸자()" << endl;
    }
};

int main()
{
    Rectangle r(0, 0, 100, 100);
    return 0;
}
