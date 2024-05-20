#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Snack Ŭ���� ����
class Snack 
{
private:
    string taste;
    float price;
    string name;
    string company;

public:
    // Snack Ŭ������ ������
    Snack(string t, float p, string n, string c) : taste(t), price(p), name(n), company(c) {}

    // �� ��� ������ ���� getter �Լ���
    string getTaste() const { return taste; }
    float getPrice() const { return price; }
    string getName() const { return name; }
    string getCompany() const { return company; }

    // ���� ȸ�縦 ����ϴ� �Լ�
    virtual void printCompany() const 
    {
        cout << "���� ȸ��: " << getCompany() << endl;
    }

    
};

// Candy Ŭ���� ����, Snack Ŭ�����κ��� ���
class Candy : public Snack 
{
public:
    // Candy Ŭ������ ������
    Candy(string t, float p, string n, string c) : Snack(t, p, n, c) {}

    // ���� ȸ�縦 ����ϴ� �Լ�
    void printCompany() const override {
        cout << "Candy ���� ȸ��: " << getCompany() << endl;
    }
};

// Chocolate Ŭ���� ����, Snack Ŭ�����κ��� ���
class Chocolate : public Snack {
public:
    // Chocolate Ŭ������ ������
    Chocolate(string t, float p, string n, string c) : Snack(t, p, n, c) {}

    // ���� ȸ�縦 ����ϴ� �Լ�
    void printCompany() const override 
    {
        cout << "Chocolate ���� ȸ��: " << getCompany() << endl;
    }
};

int main() 
{
    // snackBasket ����
    vector<Snack*> snackBasket;

    string taste, name, company;
    float price;
    int type;

    // ����ڷκ��� �Է� ����
    for (int i = 0; i < 4; ++i) {
        cout << "���� ������ �����ϼ��� (1: Candy, 2: Chocolate): ";
        cin >> type;
        cout << "���� �Է��ϼ���: ";
        cin >> taste;
        cout << "������ �Է��ϼ���: ";
        cin >> price;
        cout << "�̸��� �Է��ϼ���: ";
        cin >> name;
        cout << "�����縦 �Է��ϼ���: ";
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
            cout << "�߸��� ���� �����Դϴ�." << endl;
        }
    }

    // snackBasket�� �ִ� �� �ν��Ͻ��� ���� ȸ�縦 ���
    for (Snack* snack : snackBasket) 
    {
        snack->printCompany();
    }

    // �������� �Ҵ�� �޸� ����
    for (Snack* snack : snackBasket) 
    {
        delete snack;
    }

    return 0;
}
