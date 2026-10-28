// 2026-10-28
// insert()로 벡터 중간에 값 삽입
#include <vector>
#include <iostream>
using namespace std;

int main(void) {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    cout << "현재의  v =  ";
    for (auto& e : v)
        cout << e << " ";
    cout << endl;

    // it의 타입은 vector<int>::iterator
    auto it = v.begin() + 5;
    v.insert(it, 100); // 5번 인덱스에 삽입, 기존 요소 뒤로 이동

    cout << "5번 인덱스에 값을 추가한 후 v =  ";
    for (auto& e : v)
        cout << e << " ";
    cout << endl;

    return 0;
}
