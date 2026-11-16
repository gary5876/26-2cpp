// 2026-11-16
// MUD 게임 확장 2: 지도 2차원 벡터화, 아이템 획득 수 관리, 정보 명령어 추가
#include <iostream>
#include <string>
#include <vector>
#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(vector<vector<int>>& map, int user_x, int user_y);
bool checkGoal(vector<vector<int>>& map, int user_x, int user_y);
void checkState(vector<vector<int>>& map, int user_x, int user_y, User& user);
bool moveUser(int& user_x, int& user_y, int dx, int dy);
bool CheckUser(User user);

// 메인 함수
int main() {
    // 0: 빈 공간, 1: 아이템, 2: 적, 3: 포션, 4: 목적지
    vector<vector<int>> map = { {0, 1, 2, 0, 4},
                                {1, 0, 0, 2, 0},
                                {0, 0, 0, 0, 0},
                                {0, 2, 3, 0, 0},
                                {3, 0, 0, 0, 2} };

    // 유저 위치
    int user_x = 0; // 가로 번호
    int user_y = 0; // 세로 번호
    User user;      // 단일 유저 객체 (HP 20)

    // 게임 시작
    while (1) { // 반복 입력
        string user_input = "";

        cout << "현재 HP: " << user.GetHP() << endl;
        cout << "명령어를 입력하세요 (상,하,좌,우,지도,정보,종료): ";
        if (!(cin >> user_input)) break; // 입력 종료(EOF) 시 탈출

        bool moved = false; // 이동 성공 여부

        if (user_input == "상") {
            moved = moveUser(user_x, user_y, 0, -1);
            if (moved) cout << "위로 한 칸 올라갑니다." << endl;
        }
        else if (user_input == "하") {
            moved = moveUser(user_x, user_y, 0, 1);
            if (moved) cout << "아래로 한 칸 내려갑니다." << endl;
        }
        else if (user_input == "좌") {
            moved = moveUser(user_x, user_y, -1, 0);
            if (moved) cout << "왼쪽으로 이동합니다." << endl;
        }
        else if (user_input == "우") {
            moved = moveUser(user_x, user_y, 1, 0);
            if (moved) cout << "오른쪽으로 이동합니다." << endl;
        }
        else if (user_input == "지도") {
            displayMap(map, user_x, user_y);
        }
        else if (user_input == "정보") {
            cout << user << endl; // << 연산자 중복
        }
        else if (user_input == "종료") {
            cout << "종료합니다." << endl;
            break;
        }
        else {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        if (moved) {
            user.DecreaseHP(1); // 이동 1회당 HP 1 감소
            displayMap(map, user_x, user_y);
            checkState(map, user_x, user_y, user);
        }

        // 목적지 도착 체크
        if (checkGoal(map, user_x, user_y)) {
            cout << "목적지에 도착했습니다! 성공" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }

        // HP 소진 체크
        if (!CheckUser(user)) {
            cout << "HP가 0이 되었습니다. 실패" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }
    }
    return 0;
}

// 지도와 유저 위치 출력
void displayMap(vector<vector<int>>& map, int user_x, int user_y) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user_y && j == user_x) {
                cout << " USER |"; // 양 옆 1칸 공백
            }
            else {
                int posState = map[i][j];
                switch (posState) {
                case 0:
                    cout << "      |"; // 6칸 공백
                    break;
                case 1:
                    cout << "아이템|";
                    break;
                case 2:
                    cout << "  적  |"; // 양 옆 2칸 공백
                    break;
                case 3:
                    cout << " 포션 |"; // 양 옆 1칸 공백
                    break;
                case 4:
                    cout << "목적지|";
                    break;
                }
            }
        }
        cout << endl;
        cout << " -------------------------------- " << endl;
    }
}

// 좌표 유효성 체크
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
    bool checkFlag = false;
    if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
        checkFlag = true;
    }
    return checkFlag;
}

// 목적지 도착 체크
bool checkGoal(vector<vector<int>>& map, int user_x, int user_y) {
    if (map[user_y][user_x] == 4) {
        return true;
    }
    return false;
}

// 현재 칸 상태 메시지 출력 및 HP, 아이템 반영 (아이템은 획득 후 소멸, 적과 포션은 유지)
void checkState(vector<vector<int>>& map, int user_x, int user_y, User& user) {
    switch (map[user_y][user_x]) {
    case 1:
        user.IncreaseItemCnt();
        map[user_y][user_x] = 0; // 획득 후 제거, 중복 획득 방지
        cout << "아이템(무기/갑옷)을 획득했습니다." << endl;
        break;
    case 2:
        user.DecreaseHP(2);
        cout << "적이 있습니다. 공격을 받아 HP가 2 줄어듭니다." << endl;
        break;
    case 3:
        user.IncreaseHP(2);
        cout << "포션이 있습니다. 포션을 마셔 HP가 2 늘어납니다." << endl;
        break;
    }
}

// 상하좌우 이동 공통 처리, 이동 성공 시 true
bool moveUser(int& user_x, int& user_y, int dx, int dy) {
    int next_x = user_x + dx;
    int next_y = user_y + dy;
    if (!checkXY(next_x, mapX, next_y, mapY)) {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        return false;
    }
    user_x = next_x;
    user_y = next_y;
    return true;
}

// 생존 체크: HP 0 이하면 false
bool CheckUser(User user) {
    if (user.GetHP() <= 0) {
        return false;
    }
    return true;
}
