// 2026-09-30
// 사용자의 선호도를 입력 받아 사용자별로 가장 선호하는 항목을 추천하는 프로그램
#include <iostream>
using namespace std;

int main() {
    const int NUM_USERS = 3; // 사용자 수
    const int NUM_ITEMS = 3; // 항목 수
    int userPreferences[NUM_USERS][NUM_ITEMS]; // [사용자][항목] 선호도

    // 사용자와 항목 간의 선호도를 입력 받아 2차원 배열 초기화
    for (int i = 0; i < NUM_USERS; ++i) {
        cout << "사용자 " << (i + 1) << "의 선호도를 입력하세요 (";
        cout << NUM_ITEMS << "개의 항목에 대해): ";
        for (int j = 0; j < NUM_ITEMS; ++j) {
            cin >> userPreferences[i][j];
        }
    }

    // 각 사용자에 대한 추천 항목 찾기
    for (int i = 0; i < NUM_USERS; ++i) {
        int maxPreferenceIndex = 0; // 선호도가 가장 높은 항목의 인덱스
        for (int j = 1; j < NUM_ITEMS; ++j) {
            if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]) {
                maxPreferenceIndex = j;
            }
        }

        // 사용자에게 추천하는 항목 출력 (인덱스는 0부터 시작하므로 +1)
        cout << "사용자 " << (i + 1) << "에게 추천하는 항목: ";
        cout << (maxPreferenceIndex + 1) << std::endl;
    }

    return 0;
}
