// 2026-09-21
#include <iostream>
using namespace std;

int main()
{
    int dan;
    int n = 1;

    cout << "구구단 중에서 출력하고 싶은 단을 입력하시오: ";
    cin >> dan;

    while (n <= 9) {
        cout << dan << "*" << n << "=" << dan * n << endl;
        n++;
    }

    return 0;
}
