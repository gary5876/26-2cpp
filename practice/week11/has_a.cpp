// 2026-11-09
// has-a 관계: 멤버로 다른 클래스 객체 포함
#include <iostream>
#include <string>
using namespace std;

class Date {
    int year, month, day;
public:
    Date(int y, int m, int d) { year = y; month = m; day = d; }
    void Print() {
        cout << year << "." << month << "." << day << endl;
    }
};

class Person {
    string name;
    Date birth; // Person has-a Date
public:
    // Date 기본 생성자 부재: 초기화 리스트 필수
    Person(string n, Date d) : name{ n }, birth{ d } { }
    void Print() {
        cout << name << ": ";
        birth.Print();
    }
};

int main()
{
    Date d{ 1998, 3, 1 };
    Person p{ "김철수", d };
    p.Print();
    return 0;
}
