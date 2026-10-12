// 2026-10-07
// 주민등록번호를 입력 받아 -를 제거하고 출력하는 프로그램
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; // 입력 받은 주민등록번호를 저장할 문자열 객체
    cout << "주민등록번호를 입력하시오: ";
    cin >> s;

    cout << "-가 제거된 주민등록번호: ";
    // 문자열의 문자를 앞에서부터 하나씩 꺼내 확인 (char 대신 auto를 써도 됨)
    for (char c : s) {
        if (c == '-') { // -는 출력하지 않고 다음 문자로 넘어감
            continue;
        }
        cout << c;
    }
    cout << endl;

    return 0;
}
