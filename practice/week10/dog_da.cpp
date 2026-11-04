// 2026-11-04
// 객체 및 멤버 변수 동적 생성: 생성자에서 new, 소멸자에서 delete
#include <iostream>
using namespace std;

class Dog {
private:
    int *pWeight;
    int *pAge;
public:
    Dog() {
        pAge = new int(1);     // 멤버 동적 할당
        pWeight = new int(10);
    }
    ~Dog() {
        delete pAge;           // 멤버 해제
        delete pWeight;
    }
    int GetAge() { return *pAge; }
    void SetAge(int age) { *pAge = age; }
    int GetWeight() { return *pWeight; }
    void SetWeight(int weight) { *pWeight = weight; }
};

int main()
{
    Dog *pDog = new Dog; // 객체 동적 생성
    cout << "강아지의 나이: " << pDog->GetAge() << endl; // -> 로 멤버 접근

    pDog->SetAge(5);
    cout << "강아지의 나이: " << pDog->GetAge() << endl;

    delete pDog; // 소멸자 호출
    return 0;
}
