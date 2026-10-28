// 2026-10-26
// 생성자, 소멸자 호출 시점 확인 (사각형 넓이 계산)
#include <iostream>
using namespace std;

// 사각형 클래스
class Rectangle {
    int width, height; // 기본값 private
public:
    Rectangle(int w, int h); // 생성자
    ~Rectangle();            // 소멸자: ~클래스명, 매개변수와 반환형 없음
    int CalcArea();          // 넓이 계산
};

// 생성자 정의: 멤버 초기화
Rectangle::Rectangle(int w, int h)
{
    cout << "생성자 호출!" << endl;
    width = w;
    height = h;
}

// 소멸자 정의 (주로 리소스 해제 용도)
Rectangle::~Rectangle()
{
    cout << "소멸자 호출!" << endl;
}

// 넓이 계산
int Rectangle::CalcArea()
{
    return width * height;
}

int main()
{
    Rectangle r{ 3, 4 }; // 생성자 호출

    cout << "사각형의 넓이 : " << r.CalcArea() << '\n'; // 12
    return 0; // main 종료 시 r 소멸, 소멸자 호출
}
