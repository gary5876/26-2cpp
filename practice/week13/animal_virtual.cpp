// 2026-11-23
// 가상함수: 부모 포인터로 호출해도 실제 객체의 Speak 호출
#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void Speak() { cout << "Animal speak()" << endl; }
};

class Dog : public Animal
{
public:
    int age;
    void Speak() { cout << "멍멍" << endl; }
};

class Cat : public Animal
{
public:
    void Speak() { cout << "야옹" << endl; }
};

int main()
{
    Animal* a1 = new Dog(); // 상향 형변환
    a1->Speak();            // 멍멍

    Animal* a2 = new Cat();
    a2->Speak();            // 야옹

    Animal* a3 = new Animal();
    a3->Speak();            // Animal speak()

    Animal a4 = Cat();
    a4.Speak();             // 객체 슬라이싱: Animal speak()

    // 콤마 연결 시 a1만 해제, 개별 delete
    delete a1;
    delete a2;
    delete a3;

    return 0;
}
