// 2026-09-30
// recommendation_base.cpp를 함수로 나누어 작성함
// 최대 선호도가 동점인 항목이 2개 이상이면 번호가 작은 항목을 추천
#include <iostream>
using namespace std;

const int NUM_USERS = 3; // 사용자 수
const int NUM_ITEMS = 3; // 항목 수
// 두 함수와 main에서 함께 쓰기 위해 전역 변수로 선언
int userPreferences[NUM_USERS][NUM_ITEMS]; // [사용자][항목] 선호

// 사용자 선호도를 입력 받아 2차원 배열을 초기화하는 함수
void initializePreferences(int preferences[NUM_USERS][NUM_ITEMS]) {
    for (int i = 0; i < NUM_USERS; ++i) {
        cout << "사용자 " << (i + 1) << "의 선호도를 입력하세요 (" << NUM_ITEMS << "개의 항목에 대해): ";
        for (int j = 0; j < NUM_ITEMS; ++j) {
            cin >> preferences[i][j];
        }
    }
}

// 사용자별 추천 항목을 찾고 출력하는 함수 (배열을 수정하지 않으므로 const)
void findRecommendedItems(const int preferences[NUM_USERS][NUM_ITEMS]) {
    for (int i = 0; i < NUM_USERS; ++i) {
        int maxPreferenceIndex = 0; // 선호도가 가장 높은 항목의 인덱스
        for (int j = 1; j < NUM_ITEMS; ++j) {
            // 더 클 때만 바꾸므로(>) 동점이면 앞쪽 항목이 유지됨
            if (preferences[i][j] > preferences[i][maxPreferenceIndex]) {
                maxPreferenceIndex = j;
            }
        }

        // 사용자에게 추천하는 항목 출력 (인덱스는 0부터 시작하므로 +1)
        cout << "사용자 " << (i + 1) << "에게 추천하는 항목: ";
        cout << (maxPreferenceIndex + 1) << endl;
    }
}

int main() {
    // 선호도를 초기화하고 사용자에게 추천할 항목 찾기
    initializePreferences(userPreferences);
    findRecommendedItems(userPreferences);

    return 0;
}
