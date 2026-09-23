// 2026-09-23
// 학생 성적을 입력받아 평균을 구하는 프로그램
#include <iostream>
using namespace std;

int main()
{
    const int STUDENTS = 5; // 학생 수
    int scores[STUDENTS]; // 성적을 저장할 배열
    int sum = 0;

    for (int i = 0; i < STUDENTS; i++) {
        cout << i + 1 << "번 학생의 성적을 입력하시오: ";
        cin >> scores[i];
    }

    // 범위기반 for문으로 합계 구하기
    for (int score : scores) {
        sum += score;
    }

    double average = (double)sum / STUDENTS;
    cout << "성적 평균 = " << average << endl;

    return 0;
}
