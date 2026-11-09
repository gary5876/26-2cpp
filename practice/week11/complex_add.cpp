// 2026-11-09
// 함수로 객체 전달 및 반환: const 참조자 매개변수
#include <iostream>
using namespace std;

class Complex {
public:
    double real, imag;
    Complex(double r = 0.0, double i = 0.0) {
        real = r;
        imag = i;
        cout << "생성자 호출: ";
        Print();
    }
    ~Complex() {
        cout << "소멸자 호출: ";
        Print();
    }
    void Print() {
        cout << real << "+" << imag << "i" << endl;
    }
};

// 참조 전달: 복사 생략, const로 원본 변경 방지
Complex Add(const Complex& c1, const Complex& c2) {
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;
    return temp;
}

int main()
{
    Complex c1{ 1, 2 }, c2{ 3, 4 };
    Complex t;
    t = Add(c1, c2); // 반환 객체 대입
    t.Print();
    return 0;
}
