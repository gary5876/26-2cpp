// 온도 변환
// 화씨온도를 입력받아 섭씨온도로 변환한다
// 섭씨온도 = (5.0 / 9.0) * (화씨온도 - 32)
#include <iostream>
using namespace std;

int main()
{
    double fahrenheit;

    cin >> fahrenheit;   // 화씨온도 입력

    double celsius = (5.0 / 9.0) * (fahrenheit - 32);

    cout << "화씨온도: " << fahrenheit << endl;
    cout << "섭씨온도 = " << celsius << endl;

    return 0;
}
