// 2026-11-04
// 스마트 포인터(unique_ptr) 배열: 범위 종료 시 자동 해제
#include <iostream>
#include <memory>
using namespace std;

int main()
{
    unique_ptr<int[]> buf(new int[10]);

    for (int i = 0; i < 10; i++) {
        buf[i] = i;
    }

    for (int i = 0; i < 10; i++) {
        cout << buf[i] << " ";
    }
    cout << endl;
    return 0; // delete[] 불필요
}
