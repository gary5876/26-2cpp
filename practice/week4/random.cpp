// 2026-09-23
// 1~100 사이의 난수 10개를 배열에 저장하고 최대값을 찾는 프로그램
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    int list[10];
    int max;

    for (int i = 0; i < 10; i++) {
        int elem = rand() % 100 + 1;
        list[i] = elem;
        cout << elem << " ";
    }
    cout << endl;
    max = list[0];
    for (auto elem : list) {
        if (elem > max)
            max = elem;
    }
    cout << "최대값=" << max << endl;
    return 0;
}
