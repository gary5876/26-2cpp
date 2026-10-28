// 2026-10-28
// erase()로 벡터 중간 요소 삭제
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

    v.erase(v.begin() + 5); // 5번 인덱스 삭제, 뒤 요소 앞으로 이동

    cout << "5번 인덱스를 제거한 후 v =  ";
    for (auto& e : v)
        cout << e << " ";
    cout << endl;

    return 0;
}
