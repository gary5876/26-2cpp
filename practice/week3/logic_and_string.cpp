// 논리형(bool)과 문자열(string) 비교 연습
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "Good";
    string s2 = "Bad";
    bool b = (s1 == s2);   // 문자열이 다르므로 false(0)
    cout << b << endl;

    s2 = "Good";
    b = (s1 == s2);        // 문자열이 같아졌으므로 true(1)
    cout << b << endl;

    return 0;
}
