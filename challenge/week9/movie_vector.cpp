// 2026-10-28
// 실습 2. vector로 영화 정보(이름, 평점) 저장 및 출력
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 영화 클래스
class Movie
{
private:
    string title;  // 이름
    double rating; // 평점
public:
    Movie(string t = "", double r = 0.0) { title = t; rating = r; } // 기본값 지정
    void PrintMovie() { cout << title << ": " << rating << endl; }
};

int main(void)
{
    vector<Movie> movies; // 영화 객체 동적 배열

    movies.push_back(Movie("titanic", 9.9));
    movies.push_back(Movie("gone with the wind", 9.6));
    movies.push_back(Movie("terminator", 9.7));

    for (auto& e : movies)
        e.PrintMovie();

    return 0;
}
