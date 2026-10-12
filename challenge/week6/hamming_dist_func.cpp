// 2026-10-07
// hamming_dist.cpp를 함수로 나누어 작성함
// 길이가 같은 문자열을 입력할 때까지 다시 입력 받고, 대소문자 관계 없이 해밍 거리를 구함
#include <iostream>
#include <string>
using namespace std;

// 문자열의 모든 문자를 소문자로 바꾼 문자열을 반환하는 함수
// str은 값으로 복사되어 전달되므로 여기서 바꿔도 호출한 쪽의 원본은 그대로임
string toLowerStr(string str) {
    for (char &c : str) { // 참조자(&)로 받아야 str 안의 문자가 실제로 바뀜
        c = tolower(c);
    }
    return str;
}

// 문자열의 모든 문자를 대문자로 바꾼 문자열을 반환하는 함수
string toUpperStr(string str) {
    for (char &c : str) {
        c = toupper(c);
    }
    return str;
}

// 대소문자 관계 없이 두 문자열의 해밍 거리를 구해 반환하는 함수
// (길이가 같은 두 문자열이 들어온다고 가정)
int calcHammingDist(string s1, string s2) {
    // 둘 다 소문자로 맞춘 뒤 비교하면 대소문자 차이는 거리에 포함되지 않음
    // (toUpperStr로 둘 다 대문자로 맞춰도 결과는 같음)
    s1 = toLowerStr(s1);
    s2 = toLowerStr(s2);

    int count = 0; // 같은 위치에서 서로 다른 글자의 개수
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) // 같은 위치의 글자가 다르면 거리 1 증가
            count += 1;
    }
    return count;
}

int main() {
    string s1, s2; // 비교할 두 문자열

    // 길이가 같은 문자열을 입력할 때까지 입력 요청 반복
    while (true) {
        cout << "DNA1: ";
        cin >> s1;
        cout << "DNA2: ";
        cin >> s2;

        if (s1.length() == s2.length()) // 길이가 같으면 반복 종료
            break;
        cout << "오류: 길이가 다름" << endl;
    }

    // 예) s1 = MisooKim, s2 = misookim 이면 대소문자만 다르므로 결과는 0
    int count = calcHammingDist(s1, s2);
    cout << "해밍 거리는 " << count << endl;
    return 0;
}
