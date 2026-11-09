// 2026-11-09
// 복사 생성자: 동적 멤버의 깊은 복사
#include <iostream>
using namespace std;

class MyArray {
public:
    int size;
    int* data;
    MyArray(int size);
    MyArray(const MyArray& other); // 복사 생성자
    ~MyArray();
};

MyArray::MyArray(int size)
{
    this->size = size;
    data = new int[size];
}

MyArray::MyArray(const MyArray& other)
{
    this->size = other.size;
    this->data = new int[other.size]; // 별도 메모리 할당
    for (int i = 0; i < size; i++)
        this->data[i] = other.data[i];
    cout << "복사생성자 호출!" << endl;
}

MyArray::~MyArray()
{
    if (data != nullptr) delete[] this->data;
    data = nullptr;
}

int main()
{
    MyArray buffer(10);
    buffer.data[0] = 1;
    {
        MyArray clone = buffer; // 복사 생성자 호출
    }   // clone 소멸: clone의 data만 해제
    buffer.data[0] = 2;         // 얕은 복사였다면 해제된 메모리 접근
    cout << "buffer.data[0]: " << buffer.data[0] << endl;

    return 0;
}
