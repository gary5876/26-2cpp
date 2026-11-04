// 2026-11-04
// 동적 메모리 할당(new[]), 사용, 반납(delete[]) 및 난수 생성
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    int *ptr;
    srand(time(NULL)); // 난수 발생기 시드 설정
    ptr = new int[10]; // ① 동적 메모리 할당

    for (int i = 0; i < 10; i++)
        ptr[i] = rand(); // ② 동적 메모리 사용

    for (int i = 0; i < 10; i++)
        cout << ptr[i] << " ";

    delete[] ptr; // ③ 동적 메모리 반납
    cout << endl;
    return 0;
}
