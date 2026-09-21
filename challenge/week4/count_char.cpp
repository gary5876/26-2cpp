// 2026-09-21
// 영문자를 입력받아 모음과 자음의 개수를 세는 프로그램 (Ctrl+Z로 입력 종료, macOS/Linux는 Ctrl+D)
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char ch;
    int vowels = 0;
    int consonants = 0;

    cout << "영문자를 입력하고 콘트롤-Z를 치세요" << endl;

    while (cin >> ch) {
        if (!isalpha(ch))
            continue;

        switch (tolower(ch)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowels++;
                break;
            default:
                consonants++;
                break;
        }
    }

    cout << "모음: " << vowels << endl;
    cout << "자음: " << consonants << endl;

    return 0;
}
