// 2026-11-16
// User 클래스 멤버 함수 정의
#include "user.h"

User::User() : hp{20} { }

void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
}

int User::GetHP() {
    return hp;
}
