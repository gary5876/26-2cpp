// 2026-11-23
// Magician, Warrior 멤버 함수 및 << 연산자 정의
#include "user.h"

// Magician
Magician::Magician() : hp{20}, itemCnt{0} { }

void Magician::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

void Magician::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
}

int Magician::GetHP() {
    return hp;
}

void Magician::IncreaseItemCnt() {
    itemCnt++;
}

int Magician::GetItemCnt() {
    return itemCnt;
}

void Magician::doAttack() {
    cout << "마법 사용" << endl;
}

string Magician::GetJob() {
    return "마법사";
}

// Warrior
Warrior::Warrior() : hp{20}, itemCnt{0} { }

void Warrior::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

void Warrior::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
}

int Warrior::GetHP() {
    return hp;
}

void Warrior::IncreaseItemCnt() {
    itemCnt++;
}

int Warrior::GetItemCnt() {
    return itemCnt;
}

void Warrior::doAttack() {
    cout << "베기 사용" << endl;
}

string Warrior::GetJob() {
    return "전사";
}

ostream& operator<<(ostream& os, User& user) {
    os << "현재 HP는 " << user.GetHP() << " 이고, 먹은 아이템은 총 " << user.GetItemCnt() << "개 입니다";
    return os;
}
