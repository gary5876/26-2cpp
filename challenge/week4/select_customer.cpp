// 2026-09-23
// 고객 정보를 입력받고, 특정 나이 이상의 고객을 출력하는 프로그램
#include <iostream>
using namespace std;

int main()
{
    const int CUSTOMERS = 5; // 고객 수
    string names[CUSTOMERS]; // 고객 이름
    int ages[CUSTOMERS]; // 고객 나이
    int ageThreshold = 30; // 기준 나이
    bool found = false; // 기준 나이보다 많은 고객이 있는지

    // 고객의 이름과 나이를 입력받는 코드
    for (int i = 0; i < CUSTOMERS; i++) {
        cout << i + 1 << "번 고객의 이름과 나이를 입력하시오: ";
        cin >> names[i] >> ages[i];
    }

    // ageThreshold보다 나이가 많은 고객 이름 (나이) 출력
    cout << ageThreshold << "세 이상의 고객:" << endl;
    for (int i = 0; i < CUSTOMERS; i++) {
        if (ages[i] >= ageThreshold) {
            cout << names[i] << " (" << ages[i] << ")" << endl;
            found = true;
        }
    }

    // 특정 나이보다 많은 고객이 없는 경우 메시지 출력
    if (!found)
        cout << ageThreshold << "세 이상의 고객이 없습니다." << endl;

    return 0;
}
