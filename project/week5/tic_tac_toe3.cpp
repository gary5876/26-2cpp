// 2026-09-28
// 세 명의 유저가 번갈아가며 X, O, △를 놓는 Tic Tac Toe 게임
#include <iostream>
#include <string>
using namespace std;

int main() {
    const int numCell = 3; // 보드판의 가로/세로 칸 개수
    // △는 한 글자(char)에 담을 수 없는 문자라서 보드판을 string 2차원 배열로 사용
    string board[numCell][numCell]{};
    int x, y; // 사용자에게 입력받는 x, y 좌표를 저장할 변수

    // 보드판 초기화 (모든 칸을 공백으로)
    for (x = 0; x < numCell; x++) {
        for (y = 0; y < numCell; y++) {
            board[x][y] = " ";
        }
    }

    // 게임하는 코드
    int k = 0; // 누구 차례인지 체크하기 위한 변수
    string currentUser = "X"; // 현재 유저의 돌을 저장하기 위한 문자열 변수
    while (true) {
        // 1. 누구 차례인지 출력 (유저가 3명이므로 k % 3으로 차례 구분)
        switch (k % 3) {
        case 0:
            cout << k % 3 + 1 << "번 유저(X)의 차례입니다 -> ";
            currentUser = "X";
            break;
        case 1:
            cout << k % 3 + 1 << "번 유저(O)의 차례입니다 -> ";
            currentUser = "O";
            break;
        case 2:
            cout << k % 3 + 1 << "번 유저(△)의 차례입니다 -> ";
            currentUser = "△";
            break;
        }

        // 2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 3. 입력받은 좌표의 유효성 체크
        // 3-1. 좌표가 보드판을 벗어나는지 체크
        if (x < 0 || y < 0 || x >= numCell || y >= numCell) {
            cout << x << ", " << y << ": ";
            cout << " x 와 y 둘 중 하나가 칸을 벗어납니다." << endl;
            continue; // 차례를 넘기지 않고 다시 입력받음
        }
        // 3-2. 해당 좌표에 이미 돌이 있는지 체크
        if (board[x][y] != " ") {
            cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
            continue;
        }

        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드 판 출력
        for (int i = 0; i < numCell; i++) {
            cout << "---|---|---" << endl;
            for (int j = 0; j < numCell; j++) {
                cout << board[i][j];
                if (j == numCell - 1) { // 마지막 칸 뒤에는 구분선을 출력하지 않음
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;

        // 6. 빙고 시 승자 출력 후 종료
        bool isWin = false; // 현재 유저가 빙고를 완성했는지 저장하는 변수

        // 6-1. 가로 체크: 한 행의 모든 칸이 현재 유저의 돌인지 확인
        for (int i = 0; i < numCell; i++) {
            if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
                cout << "가로에 모두 돌이 놓였습니다!: ";
                isWin = true;
            }
        }

        // 6-2. 세로 체크: 한 열의 모든 칸이 현재 유저의 돌인지 확인
        for (int i = 0; i < numCell; i++) {
            if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
                cout << "세로에 모두 돌이 놓였습니다!: ";
                isWin = true;
            }
        }

        // 6-3. 왼쪽 위에서 오른쪽 아래 대각선 체크 (board[0][0], [1][1], [2][2])
        if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
            cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!: ";
            isWin = true;
        }

        // 6-4. 오른쪽 위에서 왼쪽 아래 대각선 체크 (board[0][2], [1][1], [2][0])
        if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
            cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!: ";
            isWin = true;
        }

        if (isWin) {
            cout << k % 3 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
            cout << "종료합니다" << endl;
            break;
        }

        // 7. 모든 칸이 찼으면 종료
        bool isFull = true; // 빈 칸이 하나도 없는지 저장하는 변수
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                if (board[i][j] == " ") { // 빈 칸이 하나라도 있으면 아직 안 찬 것
                    isFull = false;
                }
            }
        }
        if (isFull) {
            cout << "모든 칸이 다 찼습니다. 종료합니다" << endl;
            break;
        }

        k++; // 다음 유저로 차례 넘기기
    }
    return 0;
}
