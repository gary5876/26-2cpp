// 2026-11-18
// 멤버 함수 재정의(override)
#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    void Speak()
    {
        cout << "동물이 소리를 내고 있음" << endl;
    }
};

class Dog : public Animal {
public:
    void Speak() // 주석 처리 시 부모 Speak 호출
    {
        cout << "멍멍!" << endl;
    }
};

int main()
{
    Dog obj;
    obj.Speak();
    return 0;
}
