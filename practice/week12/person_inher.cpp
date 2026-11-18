// 2026-11-18
// 접근 지정자: name을 protected로 변경, 자식의 SetName 허용
#include <iostream>
#include <string>
using namespace std;

class Person {
protected: // private 시 자식 접근 불가
    string name;
    string address;
};

class Student : Person {
public:
    void SetAddress(string add) {
        address = add;
    }
    string GetAddress() {
        return address;
    }
    void SetName(string name) {
        this->name = name;
    }
};

int main() {
    Student obj;
    obj.SetName("미수");
    obj.SetAddress("서울시 종로구 1번지");
    cout << obj.GetAddress() << endl;

    return 0;
}
