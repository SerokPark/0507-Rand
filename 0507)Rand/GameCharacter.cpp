#include "GameCharacter.h"


Character::Character(string name) : name(name), item_num(0) 
{
    srand(time(0));
    level = rand() % 10 + 1;
    HP = 50 + level * 10;
    attackPoint = level * 5;
    potion_num = level - 1;
}

void Character::changeName(string newName) {
    name = newName;
}

void Character::levelUp() {
    level++;
    HP = 50 + level * 10;
}

void Character::pickItem() {
    item_num++;
}

void Character::useItem() 
{
    if (item_num > 0) {
        item_num--;
        cout << "���� ������ ���� : " << item_num << "�Դϴ�." << endl;
    }
    else {
        cout << "�������� �����ϴ�!" << endl;
    }
}

void Character::potion() 
{
    if (potion_num > 0)
    {
        if (HP <= level * 10)
        {
            HP = HP + 50;
            cout << "���� ü���� : " << HP << "�Դϴ�." << endl;
        }
        else
        {
            HP = 50 + level * 10;
            cout << "���� ü���� : " << HP << ". �ִ�ġ �Դϴ�." << endl;
        }
    }
    else
    {
        cout << "����� �� �ִ� ������ �����ϴ�." << endl; //���� ���� ����ó��
    }
}

void Character::showStat() const 
{
    cout << "�̸�: " << name << ", ü��: " << HP << ", ����: " << level << ", ������ ��: " << item_num << ", ���� ��: " << potion_num << endl;
}

void Character::showHP() 
{
    cout << "���� ü����: " << HP << endl;
}

void Character::attack(Character& player, Character& target)
{
    cout << "�׾��" << endl;
    target.HP = target.HP - player.level * 5; //���� ����Ʈ //������
    
    if (target.HP > 0) 
    {
        cout << "���� ��ҽ��ϴ�. ������ ���� ü���� " << target.HP << "�Դϴ�." << endl;
    }
    else 
    {
        cout << "���񷶴�!" << endl;
    }
}

void Character::damage(int damage)
{
    HP -= damage; //���� ������->������ ��������Ư�� 
}

int Character::getAttackPoint()
{
    return this->attackPoint;
}