// 2026-09-21
#include <iostream>
using namespace std;

int main()
{
    long long fact = 1;
    int n;

    cout << "정수를 입력하시요: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }

    cout << n << "!은 " << fact << "입니다." << endl;

    return 0;
}
