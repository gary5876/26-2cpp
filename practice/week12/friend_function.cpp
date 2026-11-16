// 2026-11-16
// 프렌드 함수: 외부 함수의 private 멤버 접근
#include <iostream>
using namespace std;

class Box {
    double length, width, height;
public:
    Box(double l, double w, double h) : length{l}, width{w}, height{h} { }
    friend void printBox(Box box); // 접근 권한 부여
};

// 멤버 함수 아님
void printBox(Box box) {
    cout << "Box( " << box.length << ", " << box.width << ", " << box.height << ") " << endl;
}

int main() {
    Box box(10, 20, 30);
    printBox(box);

    return 0;
}
