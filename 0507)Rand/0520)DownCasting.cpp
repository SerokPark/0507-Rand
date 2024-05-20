#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Snack 클래스 정의
class Snack {
private:
    string company;

public:
    // Snack 클래스의 생성자
    explicit Snack(string c) : company(c) {}

    // 제조 회사를 출력하는 함수
    virtual void printCompany() const {
        cout << "제조 회사: " << company << endl;
    }

    // 각 멤버 변수에 대한 getter 함수들
    string getTaste() const { return taste; }
    float getPrice() const { return price; }
    string getName() const { return name; }
    string getCompany() const { return company; }
};

// Candy 클래스 정의, Snack 클래스로부터 상속
class Candy : public Snack {
public:
    // Candy 클래스의 생성자
    explicit Candy(string c) : Snack(c) {}

    // 제조 회사를 출력하는 함수
    void printCompany() const override 
    {
        cout << "Candy 제조 회사: " << getCompany() << endl;
    }
};

// Chocolate 클래스 정의, Snack 클래스로부터 상속
class Chocolate : public Snack {
public:
    // Chocolate 클래스의 생성자
    explicit Chocolate(string c) : Snack(c) {}

    // 제조 회사를 출력하는 함수
    void printCompany() const override {
        cout << "Chocolate 제조 회사: " << getCompany() << endl;
    }
};

int main() 
{
    vector<Snack*> snackBasket;
    string company;
    int choice;

    // 사용자로부터 스낵 종류와 제조사를 입력 받음
    cout << "스낵 종류를 선택하세요 (1: Candy, 2: Chocolate): ";
    cin >> choice;
    cin.ignore(); 
    cout << "제조사를 입력하세요: ";
    getline(cin, company);

    // 선택에 따라 Candy 또는 Chocolate 객체를 생성하고 snackBasket에 추가
    switch (choice) 
    {
    case 1:
        snackBasket.push_back(new Candy(company));
        break;
    case 2:
        snackBasket.push_back(new Chocolate(company));
        break;
    default:
        cout << "잘못된 선택입니다." << endl;
        return 1;
    }

    // snackBasket에 있는 각 인스턴스의 제조 회사를 출력
    for (const auto& snack : snackBasket) {
        // 다운캐스팅을 사용
        const Candy* candy = dynamic_cast<const Candy*>(snack);
        if (candy) 
        {
            candy->printCompany();
        }
        else 
        {
            const Chocolate* chocolate = dynamic_cast<const Chocolate*>(snack);
            if (chocolate) 
            {
                chocolate->printCompany();
            }
            else 
            {
                snack->printCompany();
            }
        }
    }

    // 동적으로 할당된 메모리 해제
    for (auto& snack : snackBasket) 
    {
        delete snack;
    }
    snackBasket.clear();

    return 0;
}
