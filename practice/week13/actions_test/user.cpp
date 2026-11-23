// 2026-11-23
// printStatus 정의
#include "user.h"
#include <iostream>
using namespace std;

void printStatus(const User& user) {
    cout << user.name << " HP: " << user.hp << '\n';
}
