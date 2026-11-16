// 2026-11-16
// User 클래스 선언부 (정의는 user.cpp)
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

    // cout << user 지원: 비멤버 프렌드
    friend ostream& operator<<(ostream& os, User& user);
};
