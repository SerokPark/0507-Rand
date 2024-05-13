#include "GameCharacter.h"

Character::Character(string name) : name(name), level(0), item_num(0) {}

void Character::changeName(string newName) {
    name = newName;
}

void Character::levelUp() {
    level++;
}

void Character::pickItem() {
    item_num++;
}

void Character::useItem() {
    if (item_num > 0) {
        item_num--;
    }
    else {
        cout << "�������� �����ϴ�!" << endl;
    }
}

void Character::showStat() const {
    cout << "�̸�: " << name << ", ����: " << level << ", ������ ��: " << item_num << endl;
}
