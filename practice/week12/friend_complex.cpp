// 2026-11-16
// 프렌드 함수 활용: 복소수 덧셈
#include <iostream>
using namespace std;

class Complex {
public:
    friend Complex add(Complex, Complex);
    Complex(double r = 0.0, double i = 0.0) { re = r; im = i; }
    void print() {
        cout << re << " + " << im << "i" << endl;
    }
private:
    double re, im;
};

// private 멤버 re, im 접근
Complex add(Complex a1, Complex a2)
{
    return Complex(a1.re + a2.re, a1.im + a2.im);
}

int main()
{
    Complex c1(1, 2), c2(3, 4);
    Complex c3 = add(c1, c2);
    c3.print();
    return 0;
}
