// 2026-10-26
// 객체의 매개변수 전달 방식 및 객체 반환 비교
#include <iostream>
using namespace std;

// 피자 클래스
class Pizza {
public:
    Pizza(int s) : size(s) { } // 초기화 리스트
    int size;                  // 단위: 인치
};

// 1. 값 전달: 복사본 수정, 원본 불변
void MakeDoubleCopy(Pizza p) {
    p.size *= 2;
}

// 2. 참조자 전달: 원본 수정
void MakeDouble(Pizza& p) {
    p.size *= 2;
}

// 3. 객체 반환: 내용 복사 후 반환
Pizza CreatePizza() {
    Pizza p(10);
    return p;
}

int main() {
    Pizza pizza(10); 

    MakeDoubleCopy(pizza); // 원본 불변
    cout << pizza.size << "인치 피자" << endl; // 10

    MakeDouble(pizza); // 원본 2배
    cout << pizza.size << "인치 피자" << endl; // 20

    Pizza newPizza = CreatePizza(); // 반환 객체 복사
    cout << newPizza.size << "인치 피자" << endl; // 10

    return 0;
}
