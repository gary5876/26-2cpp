// 2026-11-04
// const 멤버 함수, const 객체 포인터, const 포인터 비교
#include <iostream>
using namespace std;

class Circle
{
private:
    int radius;

public:
    Circle() { radius = 10; }
    ~Circle() { }
    void SetRadius(int radius) { this->radius = radius; } // this: 현재 객체 포인터
    int GetRadius() const { return radius; }              // const 함수: 멤버 변경 금지
};

int main()
{
    Circle* p = new Circle();
    const Circle *pConstObj = new Circle(); // 가리키는 객체 불변, const 함수만 호출 가능
    Circle *const pConstPtr = new Circle(); // 포인터 자체 불변, 객체 변경 가능

    cout << "pRect->radius: " << p->GetRadius() << endl;
    cout << "pConstObj->radius: " << pConstObj->GetRadius() << endl;
    cout << "pConstPtr->radius: " << pConstPtr->GetRadius() << endl << endl;

    p->SetRadius(30);
    // pConstObj->SetRadius(30); // 컴파일 에러: const 객체
    pConstPtr->SetRadius(30);

    cout << "pRect->radius: " << p->GetRadius() << endl;
    cout << "pConstObj->radius: " << pConstObj->GetRadius() << endl;
    cout << "pConstPtr->radius: " << pConstPtr->GetRadius() << endl;

    delete p;
    delete pConstObj;
    delete pConstPtr;
    return 0;
}
