// 2026-11-02
// 5x5 지도 MUD 게임: 상하좌우 이동, 목적지 도착 시 성공
// 개선: HP 20 시작, 이동 시 HP -1, 적 HP -2, 포션 HP +2, HP 0이면 실패
#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y, int& hp);
bool moveUser(int& user_x, int& user_y, int dx, int dy);

// 메인 함수
int main() {
    // 0: 빈 공간, 1: 아이템, 2: 적, 3: 포션, 4: 목적지
    int map[mapY][mapX] = { {0, 1, 2, 0, 4},
                            {1, 0, 0, 2, 0},
                            {0, 0, 0, 0, 0},
                            {0, 2, 3, 0, 0},
                            {3, 0, 0, 0, 2} };

    // 유저 위치
    int user_x = 0; // 가로 번호
    int user_y = 0; // 세로 번호
    int hp = 20;    // 유저 체력

    // 게임 시작
    while (1) { // 반복 입력
        string user_input = "";

        cout << "현재 HP: " << hp << endl;
        cout << "명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
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
        else if (user_input == "종료") {
            cout << "종료합니다." << endl;
            break;
        }
        else {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        if (moved) {
            hp -= 1; // 이동 1회당 HP 1 감소
            displayMap(map, user_x, user_y);
            checkState(map, user_x, user_y, hp);
        }

        // 목적지 도착 체크
        if (checkGoal(map, user_x, user_y)) {
            cout << "목적지에 도착했습니다! 성공" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }

        // HP 소진 체크
        if (hp <= 0) {
            cout << "HP가 0이 되었습니다. 실패" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }
    }
    return 0;
}

// 지도와 유저 위치 출력
void displayMap(int map[][mapX], int user_x, int user_y) {
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
bool checkGoal(int map[][mapX], int user_x, int user_y) {
    if (map[user_y][user_x] == 4) {
        return true;
    }
    return false;
}

// 현재 칸 상태 메시지 출력 및 HP 반영 (적, 포션은 소멸 없음)
void checkState(int map[][mapX], int user_x, int user_y, int& hp) {
    switch (map[user_y][user_x]) {
    case 1:
        cout << "아이템(무기/갑옷)이 있습니다." << endl;
        break;
    case 2:
        hp -= 2;
        cout << "적이 있습니다. 공격을 받아 HP가 2 줄어듭니다." << endl;
        break;
    case 3:
        hp += 2;
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
