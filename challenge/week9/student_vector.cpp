// 2026-10-28
// 실습 1. 학생 수 미정 -> vector로 성적 입력, 평균 계산 (-1 입력 시 종료)
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> scores; // 크기 미지정
    int sum = 0;

    while (true) {
        int score;
        cout << "성적을 입력하시오(종료는 -1) : ";
        cin >> score;
        if (score == -1) break;
        scores.push_back(score);
    }

    if (scores.empty()) { // 0 나누기 방지
        cout << "입력된 성적 없음" << endl;
        return 0;
    }

    for (auto& value : scores)
        sum += value;
    double avg = (double)sum / scores.size();
    cout << "성적 평균=" << avg << endl;

    return 0;
}
