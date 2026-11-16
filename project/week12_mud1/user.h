// 2026-11-16
// User 클래스 선언부

class User {
private:
    int hp; // 체력
public:
    User();                       // hp 20 초기화
    void IncreaseHP(int inc_hp);  // HP 증가
    void DecreaseHP(int dec_hp);  // HP 감소
    int GetHP();                  // HP 반환
};
