// 2026-10-07
// project/week5/tic_tac_toe.cpp의 3, 5, 6, 7번 블록을 함수로 나누어 작성한 Tic Tac Toe 게임
#include <iostream>
using namespace std;

// 보드판의 가로/세로 칸 개수 (함수 매개변수의 배열 크기로도 쓰이므로 전역 상수로 선언)
const int numCell = 3;

// 3. 입력받은 좌표의 유효성을 체크하는 함수 (놓을 수 있는 좌표면 true 반환)
// 보드판을 읽기만 하고 수정하지 않으므로 const를 붙임
bool isValid(const char board[numCell][numCell], int x, int y) {
    // 3-1. 좌표가 보드판을 벗어나는지 체크
    if (x < 0 || y < 0 || x >= numCell || y >= numCell) {
        cout << x << ", " << y << ": ";
        cout << " x 와 y 둘 중 하나가 칸을 벗어납니다." << endl;
        return false;
    }
    // 3-2. 해당 좌표에 이미 돌이 있는지 체크
    if (board[x][y] != ' ') {
        cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
        return false;
    }
    return true;
}

// 5. 현재 보드 판을 출력하는 함수
void printBoard(const char board[numCell][numCell]) {
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
}

// 6. 현재 유저(currentUser)가 빙고를 완성했는지 체크하는 함수 (완성했으면 true 반환)
bool checkWin(const char board[numCell][numCell], char currentUser) {
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

    return isWin;
}

// 7. 모든 칸이 찼는지 체크하는 함수 (빈 칸이 하나도 없으면 true 반환)
bool isFull(const char board[numCell][numCell]) {
    for (int i = 0; i < numCell; i++) {
        for (int j = 0; j < numCell; j++) {
            if (board[i][j] == ' ') { // 빈 칸이 하나라도 있으면 아직 안 찬 것
                return false;
            }
        }
    }
    return true;
}

int main() {
    // 보드판 (2차원 배열). 전역 변수로 두지 않고 main의 지역 변수로 선언함
    // 배열은 값이 아닌 주소가 전달되므로 함수에 매개변수로 넘겨도 같은 보드판을 보게 됨
    char board[numCell][numCell]{};
    int x, y; // 사용자에게 입력받는 x, y 좌표를 저장할 변수

    // 보드판 초기화 (모든 칸을 공백으로)
    for (x = 0; x < numCell; x++) {
        for (y = 0; y < numCell; y++) {
            board[x][y] = ' ';
        }
    }

    // 게임하는 코드
    int k = 0; // 누구 차례인지 체크하기 위한 변수
    char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 문자 변수
    while (true) {
        // 1. 누구 차례인지 출력
        switch (k % 2) {
        case 0:
            cout << k % 2 + 1 << "번 유저(X)의 차례입니다 -> ";
            currentUser = 'X';
            break;
        case 1:
            cout << k % 2 + 1 << "번 유저(O)의 차례입니다 -> ";
            currentUser = 'O';
            break;
        }

        // 2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 3. 입력받은 좌표의 유효성 체크
        if (!isValid(board, x, y)) {
            continue; // 차례를 넘기지 않고 다시 입력받음
        }

        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드 판 출력
        printBoard(board);

        // 6. 빙고 시 승자 출력 후 종료
        if (checkWin(board, currentUser)) {
            cout << k % 2 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
            cout << "종료합니다" << endl;
            break;
        }

        // 7. 모든 칸이 찼으면 종료
        if (isFull(board)) {
            cout << "모든 칸이 다 찼습니다. 종료합니다" << endl;
            break;
        }

        k++; // 다음 유저로 차례 넘기기
    }
    return 0;
}
