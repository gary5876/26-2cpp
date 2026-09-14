// 최대한의 사탕 사기
// 가지고 있는 돈과 캔디 가격을 입력받아
// 최대로 살 수 있는 캔디 개수(몫)와 구입 후 남은 돈(나머지)을 계산한다
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
