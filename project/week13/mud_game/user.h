// 2026-11-23
// User 인터페이스 및 구현 클래스 Magician, Warrior 선언부 (정의는 user.cpp)
#include <iostream>
#include <string>
using namespace std;

// 인터페이스: 전 함수 순수 가상
class User {
public:
    virtual void IncreaseHP(int inc_hp) = 0; // HP 증가
    virtual void DecreaseHP(int dec_hp) = 0; // HP 감소
    virtual int GetHP() = 0;                 // HP 반환
    virtual void IncreaseItemCnt() = 0;      // 아이템 수 1 증가
    virtual int GetItemCnt() = 0;            // 아이템 수 반환
    virtual void doAttack() = 0;             // 직업별 공격 출력
    virtual string GetJob() = 0;             // 직업명 반환
    virtual ~User() { }                      // 가상 소멸자: User* delete 시 자식 소멸자 호출
};

class Magician : public User {
private:
    int hp;      // 체력
    int itemCnt; // 획득 아이템 수
public:
    Magician(); // hp 20, itemCnt 0 초기화
    void IncreaseHP(int inc_hp) override;
    void DecreaseHP(int dec_hp) override;
    int GetHP() override;
    void IncreaseItemCnt() override;
    int GetItemCnt() override;
    void doAttack() override; // "마법 사용" 출력
    string GetJob() override; // "마법사" 반환
};

class Warrior : public User {
private:
    int hp;      // 체력
    int itemCnt; // 획득 아이템 수
public:
    Warrior(); // hp 20, itemCnt 0 초기화
    void IncreaseHP(int inc_hp) override;
    void DecreaseHP(int dec_hp) override;
    int GetHP() override;
    void IncreaseItemCnt() override;
    int GetItemCnt() override;
    void doAttack() override; // "베기 사용" 출력
    string GetJob() override; // "전사" 반환
};

// cout << user 지원: 인터페이스 함수만 사용, 프렌드 불필요
ostream& operator<<(ostream& os, User& user);
