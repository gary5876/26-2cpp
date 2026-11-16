// 2026-11-16
// 프렌드 클래스: B가 A의 private 멤버 접근
#include <iostream>
#include <string>
using namespace std;

class A {
public:
    friend class B; // B를 A의 프렌드로 지정
    A(string s = "") : secret{s} { }
private:
    string secret; // B 접근 가능
};

class B {
public:
    B() { }
    void print(A obj) {
        cout << obj.secret << endl;
    }
};

int main()
{
    A a("이것은 기밀 정보입니다.");
    B b;
    b.print(a);

    return 0;
}
