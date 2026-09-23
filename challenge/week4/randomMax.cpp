// 2026-09-23
// 2차원 배열에 저장된 난수 중 가장 큰 수와 그 위치를 출력하는 프로그램
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    srand(time(NULL)); // random 함수 관련 설정

    const int ROWS = 3;
    const int COLS = 5;
    int numbers[ROWS][COLS];

    // 2차원 배열에 0~999 난수 저장 (이중 for문)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            numbers[i][j] = rand() % 1000;
            cout << numbers[i][j] << "\t";
        }
        cout << endl;
    }

    // 가장 큰 값과 그 위치 찾기 (이중 for문)
    int maxValue = numbers[0][0];
    int maxRow = 0, maxCol = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (numbers[i][j] > maxValue) {
                maxValue = numbers[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    cout << "가장 큰 수: " << maxValue << " (위치: " << maxRow << "행 " << maxCol << "열)" << endl;
    return 0;
}
