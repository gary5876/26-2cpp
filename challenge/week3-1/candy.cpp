// 2026-09-14
#include <iostream>
using namespace std;

int main()
{
    int money, price;

    cin >> money;   // 가지고 있는 돈 입력
    cin >> price;   // 캔디 가격 입력

    int count = money / price;    // 몫: 최대로 살 수 있는 캔디 개수
    int remain = money % price;   // 나머지: 캔디 구입 후 남은 돈

    cout << "현재 가지고 있는 돈: " << money << endl;
    cout << "캔디의 가격 : " << price << endl;
    cout << "최대로 살 수 있는 캔디 = " << count << endl;
    cout << "캔디 구입 후 남은 돈 = " << remain << endl;

    return 0;
}
