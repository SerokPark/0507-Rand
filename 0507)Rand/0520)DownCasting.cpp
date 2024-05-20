#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Snack Ŭ���� ����
class Snack {
private:
    string company;

public:
    // Snack Ŭ������ ������
    explicit Snack(string c) : company(c) {}

    // ���� ȸ�縦 ����ϴ� �Լ�
    virtual void printCompany() const {
        cout << "���� ȸ��: " << company << endl;
    }

    // �� ��� ������ ���� getter �Լ���
    string getTaste() const { return taste; }
    float getPrice() const { return price; }
    string getName() const { return name; }
    string getCompany() const { return company; }
};

// Candy Ŭ���� ����, Snack Ŭ�����κ��� ���
class Candy : public Snack {
public:
    // Candy Ŭ������ ������
    explicit Candy(string c) : Snack(c) {}

    // ���� ȸ�縦 ����ϴ� �Լ�
    void printCompany() const override 
    {
        cout << "Candy ���� ȸ��: " << getCompany() << endl;
    }
};

// Chocolate Ŭ���� ����, Snack Ŭ�����κ��� ���
class Chocolate : public Snack {
public:
    // Chocolate Ŭ������ ������
    explicit Chocolate(string c) : Snack(c) {}

    // ���� ȸ�縦 ����ϴ� �Լ�
    void printCompany() const override {
        cout << "Chocolate ���� ȸ��: " << getCompany() << endl;
    }
};

int main() 
{
    vector<Snack*> snackBasket;
    string company;
    int choice;

    // ����ڷκ��� ���� ������ �����縦 �Է� ����
    cout << "���� ������ �����ϼ��� (1: Candy, 2: Chocolate): ";
    cin >> choice;
    cin.ignore(); 
    cout << "�����縦 �Է��ϼ���: ";
    getline(cin, company);

    // ���ÿ� ���� Candy �Ǵ� Chocolate ��ü�� �����ϰ� snackBasket�� �߰�
    switch (choice) 
    {
    case 1:
        snackBasket.push_back(new Candy(company));
        break;
    case 2:
        snackBasket.push_back(new Chocolate(company));
        break;
    default:
        cout << "�߸��� �����Դϴ�." << endl;
        return 1;
    }

    // snackBasket�� �ִ� �� �ν��Ͻ��� ���� ȸ�縦 ���
    for (const auto& snack : snackBasket) {
        // �ٿ�ĳ������ ���
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

    // �������� �Ҵ�� �޸� ����
    for (auto& snack : snackBasket) 
    {
        delete snack;
    }
    snackBasket.clear();

    return 0;
}
