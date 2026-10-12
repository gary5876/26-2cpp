// 2026-10-07
// 헤더 파일에 선언된 sum 함수를 호출하는 프로그램
// 이 파일만 빌드하면 sum의 구현을 찾지 못해 링크 단계에서 실패함 (undefined reference to sum)
// 구현이 들어 있는 calculator.cpp도 같이 빌드해야 함:
//   g++ calculator.cpp calculator_main.cpp -o calculator_main
#include <iostream>
#include "calculator.h" // sum 함수의 선언을 가져옴
using namespace std;

int main(){
    // 선언만 보고 호출하고, 실제 구현과는 링크 단계에서 연결됨
    int result = sum(10, 5);
    cout << result << endl;
    return 0;
}
