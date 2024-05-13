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
        cout << "아이템이 없습니다!" << endl;
    }
}

void Character::showStat() const {
    cout << "이름: " << name << ", 레벨: " << level << ", 아이템 수: " << item_num << endl;
}
