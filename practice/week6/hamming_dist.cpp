// 2026-10-07
// 두 문자열의 해밍 거리를 구하는 프로그램
// 해밍 거리: 두 문자열의 동일한 위치에 틀린 글자가 몇 개인지를 바탕으로 계산된 거리
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2; // 비교할 두 문자열
    int count = 0; // 같은 위치에서 서로 다른 글자의 개수 (해밍 거리)

    cout << "DNA1: ";
    cin >> s1;
    cout << "DNA2: ";
    cin >> s2;

    // 길이가 다르면 같은 위치끼리 비교할 수 없으므로 오류 처리
    if (s1.length() != s2.length())
        cout << "오류: 길이가 다름" << endl;
    else {
        // 문자열은 문자의 배열과 같아서 인덱스로 한 글자씩 접근 가능
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) // 같은 위치의 글자가 다르면 거리 1 증가
                count += 1;
        }
        cout << "해밍 거리는 " << count << endl;
    }
    return 0;
}
