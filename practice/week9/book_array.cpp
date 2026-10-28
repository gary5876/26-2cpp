// 2026-10-28
// 여러 책을 저장하는 Book 객체 배열
#include <iostream>
#include <string>
using namespace std;

// 책 클래스
class Book
{
    string title;
    int price;
public:
    Book(string name, int price) {
        title = name;        // 이름 상이, this 불필요
        this->price = price; // 이름 동일, this로 멤버 지정
    }
    void Print() {
        cout << "제목:" << title << ",  가격:" << price << endl;
    }
};

int main(void)
{
    // 기본 생성자 부재 -> 원소별 생성자 호출로 초기화
    Book books[2] = {
        Book("어서와 C++", 25000),
        Book("어서와 C  ", 22000)
    };

    cout << "소장하고 있는 책 정보" << endl;
    cout << "======================" << endl;
    for (Book& b : books)
        b.Print();
    cout << "======================" << endl;
    return 0;
}
