// 2026-09-30
// main 함수의 매개변수(argc, argv)로 실행 인자를 받아 출력하는 프로그램
#include <iostream>
using namespace std;

// argc: 실행 인자 개수 (실행 파일 이름 포함), argv: 실행 인자 문자열 배열
int main(int argc, char *argv[]) {
    cout << argc << endl;

    // 실행 인자를 순서대로 "번호:값" 형태로 출력
    for (int i = 0; i < argc; i++) {
        cout << i << ":" << argv[i] << endl;
    }
    // 왜 안될까? : argv 갯수를 미리 알 수 없음!
    // for (auto arg : argv){
    //     cout << arg << endl;
    // }

    return 0;
}
