// 2026-11-18
// User 클래스 및 상속 클래스 Magician, Warrior 선언부 (정의는 user.cpp)
#include <iostream>
using namespace std;

class User {
private:
    int hp;      // 체력
    int itemCnt; // 획득 아이템 수
public:
    User();                       // hp 20, itemCnt 0 초기화
    void IncreaseHP(int inc_hp);  // HP 증가
    void DecreaseHP(int dec_hp);  // HP 감소
    int GetHP();                  // HP 반환
    void IncreaseItemCnt();       // 아이템 수 1 증가
    void doAttack();              // "공격합니다" 출력

    // cout << user 지원: 비멤버 프렌드
    friend ostream& operator<<(ostream& os, User& user);
};

class Magician : public User {
public:
    void doAttack(); // 재정의: "마법 사용" 출력
};

class Warrior : public User {
public:
    void doAttack(); // 재정의: "베기 사용" 출력
};
