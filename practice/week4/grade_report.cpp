// 2026-09-23
// 학생들의 성적을 2차원 배열에 저장하고 과목별 평균을 구하는 프로그램
#include <iostream>
using namespace std;

int main()
{
    const int STUDENTS = 3; // 학생 수 (행)
    const int SUBJECTS = 3; // 과목 수 (열)
    string subjects[SUBJECTS] = {"국어", "영어", "수학"};
    int scores[STUDENTS][SUBJECTS] = {
        {85, 90, 78},
        {92, 88, 95},
        {76, 85, 89}
    };

    for (int j = 0; j < SUBJECTS; j++) {
        int sum = 0;
        for (int i = 0; i < STUDENTS; i++) {
            sum += scores[i][j];
        }
        double average = (double)sum / STUDENTS; // 평균은 실수로 출력
        cout << subjects[j] << " 평균: " << average << endl;
    }

    return 0;
}
