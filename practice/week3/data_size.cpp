// sizeof 연산자로 자료형의 크기(byte) 확인하기
#include <iostream>
using namespace std;

int main()
{
    cout << "char 크기 : " << sizeof('p') << endl;
    cout << "int 크기 : " << sizeof(10) << endl;
    cout << "double 크기 : " << sizeof(10.0) << endl;

    return 0;
}
