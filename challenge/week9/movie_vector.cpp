// 2026-10-28
// 실습 2. vector로 영화 정보(이름, 평점) 저장 및 출력
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 영화 클래스
class Movie
{
    string title;  // 이름
    double rating; // 평점
public:
    Movie(string title, double rating) {
        this->title = title;
        this->rating = rating;
    }
    void Print() {
        cout << title << ": " << rating << endl;
    }
};

int main(void)
{
    vector<Movie> movies;

    movies.push_back(Movie("titanic", 9.9));
    movies.push_back(Movie("gone with the wind", 9.6));
    movies.push_back(Movie("terminator", 9.7));

    for (auto& m : movies)
        m.Print();

    return 0;
}
