// 2026-10-28
// sort()와 비교 함수로 Person 벡터를 나이순 정렬
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 사람 클래스
class Person {
private:
    string name;
    int age;
public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
    string GetName() { return name; }
    int GetAge()     { return age; }
    void Print()     {
        cout << name << " " << age << endl;
    }
};

bool Compare(Person &p, Person &q)
{
    // Compare가 true를 반환하면 첫번째가 두번째 앞에 위치
    return p.GetAge() < q.GetAge();
}

int main()
{
    vector<Person> list;

    list.push_back(Person("Kim", 30));
    list.push_back(Person("Park", 22));
    list.push_back(Person("Lee", 26));

    sort(list.begin(), list.end(), Compare); // 나이 오름차순

    for (auto& e : list) {
        e.Print();
    }
    return 0;
}
