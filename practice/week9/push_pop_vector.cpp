// 2026-10-28
// push_back()으로 요소 추가, pop_back()으로 끝에서부터 삭제
#include <vector>
#include <iostream>
using namespace std;

int main(void) {
    vector<int> v; // 크기 미지정
    for (int i = 0; i < 10; ++i) {
        v.push_back(i); // 끝에 추가
    }

    cout << "현재의  v =  ";
    for (auto& e : v)
        cout << e << " ";
    cout << endl;

    cout << "삭제 요소 =  ";
    // 벡터가 빌 때까지 pop_back() 호출
    while (v.empty() != true) {
        cout << v.back() << " "; // 마지막 요소
        v.pop_back();            // 마지막 요소 삭제
    }
    cout << endl;
    return 0;
}
