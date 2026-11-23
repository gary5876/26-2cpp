// 2026-11-23
// 인터페이스 RemoteControl: TV, 냉장고 켜기/끄기를 같은 인터페이스로 수행
#include <iostream>
using namespace std;

// 리모컨 인터페이스 정의
class RemoteControl {
public:
    // 순수 가상 함수 정의
    virtual void TurnON() = 0;  // 가전 제품 켜기
    virtual void TurnOFF() = 0; // 가전 제품 끄기
    virtual ~RemoteControl() { } // 가상 소멸자: 자식 소멸자 호출 보장
};

// TV 클래스 정의
class Television : public RemoteControl {
public:
    void TurnON() override {
        cout << "TV를 켭니다." << endl;
    }
    void TurnOFF() override {
        cout << "TV를 끕니다." << endl;
    }
};

// 냉장고 클래스 정의
class Refrigerator : public RemoteControl {
public:
    void TurnON() override {
        cout << "냉장고를 켭니다." << endl;
    }
    void TurnOFF() override {
        cout << "냉장고를 끕니다." << endl;
    }
};

int main() {
    // TV를 켜고 끄는 동작을 인터페이스를 통해 수행
    RemoteControl* remoteTV = new Television();
    remoteTV->TurnON();  // TV 켬
    remoteTV->TurnOFF(); // TV 끔

    // 냉장고를 켜고 끄는 동작을 인터페이스를 통해 수행
    RemoteControl* remoteRefrigerator = new Refrigerator();
    remoteRefrigerator->TurnON();  // 냉장고 켬
    remoteRefrigerator->TurnOFF(); // 냉장고 끔

    delete remoteTV;
    delete remoteRefrigerator;
    return 0;
}
