// 2026-11-23
// GitHub Actions 빌드 검사용 User 구조체 선언부
#include <string>
using namespace std;

struct User {
    string name;
    int hp;
};

void printStatus(const User& user);
