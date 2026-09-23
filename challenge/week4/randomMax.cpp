// 2026-09-23
// 2차원 배열에 저장된 난수 중 가장 큰 수와 그 위치를 출력하는 프로그램
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    int numCell = 10;
    int numList[numCell][numCell];

    // 2차원 배열에 난수 저장하는 코드 (이중 for문)
    for (int i = 0; i < numCell; i++) {
        for (int j = 0; j < numCell; j++) {
            int elem = rand() % 1000;
            numList[i][j] = elem;
            cout << i << ", " << j << " : " << elem << endl;
        }
    }
    cout << endl;

    // 큰 값과 그 위치를 찾는 코드 (이중 for문)
    int max = -1; // 큰 값 저장을 위한 변수
    int maxI; // 큰 값이 있는 i 를 저장하기 위한 변수
    int maxJ; // 큰 값이 있는 j 를 저장하기 위한 변수
    for (int i = 0; i < numCell; i++) {
        for (int j = 0; j < numCell; j++) {
            int value = numList[i][j];
            if (value > max) {
                max = value;
                maxI = i;
                maxJ = j;
            }
        }
    }
    cout << "가장 큰 값은 " << max << "이고,";
    cout << "i와 j는 각각 " << maxI << ", " << maxJ << "입니다." << endl;
    cout << "검증 결과: " << numList[maxI][maxJ] << endl;

    return 0;
}
