// 2026-10-12
// 멤버 함수(메소드)를 중복 정의(overloading)해 자료형에 따라 다른 print가 호출되는 프로그램
#include <iostream>
#include <string>
using namespace std;

// 이름은 같고 매개변수의 자료형이 다른 print 멤버 함수 3개를 가진 클래스
class PrintData {
public:
    void print(int i) { cout << i << endl; }     // 정수를 출력
    void print(double f) { cout << f << endl; }  // 실수를 출력
    void print(string s = "No Data!") { cout << s << endl; } // 문자열을 출력 (생략하면 기본값 사용)
};

int main() {
    PrintData obj;

    // 전달한 값의 자료형에 맞는 print가 자동으로 선택됨
    obj.print(1);                // int 버전 호출
    obj.print(3.14);             // double 버전 호출
    obj.print("C++14 is cool."); // string 버전 호출
    obj.print();                 // 인자가 없으므로 기본값이 있는 string 버전 호출 (No Data! 출력)
    return 0;
}
