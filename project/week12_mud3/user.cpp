// 2026-11-18
// User, Magician, Warrior 멤버 함수 및 << 연산자 정의
#include "user.h"

User::User() : hp{20}, itemCnt{0} { }

void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
}

int User::GetHP() {
    return hp;
}

void User::IncreaseItemCnt() {
    itemCnt++;
}

void User::doAttack() {
    cout << "공격합니다" << endl;
}

void Magician::doAttack() {
    cout << "마법 사용" << endl;
}

void Warrior::doAttack() {
    cout << "베기 사용" << endl;
}

// private itemCnt 접근
ostream& operator<<(ostream& os, User& user) {
    os << "현재 HP는 " << user.GetHP() << " 이고, 먹은 아이템은 총 " << user.itemCnt << "개 입니다";
    return os;
}
