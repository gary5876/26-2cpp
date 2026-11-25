// 2026-11-25
// 디버깅 실습: 세 점수 합. 기대 60, 실제 30 (중단점과 Step으로 원인 추적)
#include <iostream>

int sumScores(const int scores[], int count) {
    int total = 0;
    for (int i = 0; i < count - 1; ++i) { // 중단점: i < count - 1 (마지막 점수 누락)   
        total += scores[i];
    }
    return total;
}

int main() {
    const int scores[] = {10, 20, 30};
    int result = sumScores(scores, 3);
    std::cout << result << '\n';
}
