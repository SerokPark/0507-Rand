#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Snack 클래스 정의
class Snack 
{
private:
    string taste;
    float price;
    string name;
    string company;

public:
    // Snack 클래스의 생성자
    Snack(string t, float p, string n, string c) : taste(t), price(p), name(n), company(c) {}

    // 각 멤버 변수에 대한 getter 함수들
    string getTaste() const { return taste; }
    float getPrice() const { return price; }
    string getName() const { return name; }
    string getCompany() const { return company; }

    // 제조 회사를 출력하는 함수
    virtual void printCompany() const 
    {
        cout << "제조 회사: " << getCompany() << endl;
    }

    
};

// Candy 클래스 정의, Snack 클래스로부터 상속
class Candy : public Snack 
{
public:
    // Candy 클래스의 생성자
    Candy(string t, float p, string n, string c) : Snack(t, p, n, c) {}

    // 제조 회사를 출력하는 함수
    void printCompany() const override {
        cout << "Candy 제조 회사: " << getCompany() << endl;
    }
};

// Chocolate 클래스 정의, Snack 클래스로부터 상속
class Chocolate : public Snack {
public:
    // Chocolate 클래스의 생성자
    Chocolate(string t, float p, string n, string c) : Snack(t, p, n, c) {}

    // 제조 회사를 출력하는 함수
    void printCompany() const override 
    {
        cout << "Chocolate 제조 회사: " << getCompany() << endl;
    }
};

int main() 
{
    // snackBasket 생성
    vector<Snack*> snackBasket;

    string taste, name, company;
    float price;
    int type;

    // 사용자로부터 입력 받음
    for (int i = 0; i < 4; ++i) {
        cout << "스낵 종류를 선택하세요 (1: Candy, 2: Chocolate): ";
        cin >> type;
        cout << "맛을 입력하세요: ";
        cin >> taste;
        cout << "가격을 입력하세요: ";
        cin >> price;
        cout << "이름을 입력하세요: ";
        cin >> name;
        cout << "제조사를 입력하세요: ";
        cin >> company;

        if (type == 1) 
        {
            snackBasket.push_back(new Candy(taste, price, name, company));
        }
        else if (type == 2) 
        {
            snackBasket.push_back(new Chocolate(taste, price, name, company));
        }
        else 
        {
            cout << "잘못된 스낵 종류입니다." << endl;
        }
    }

    // snackBasket에 있는 각 인스턴스의 제조 회사를 출력
    for (Snack* snack : snackBasket) 
    {
        snack->printCompany();
    }

    // 동적으로 할당된 메모리 해제
    for (Snack* snack : snackBasket) 
    {
        delete snack;
    }

    return 0;
}
