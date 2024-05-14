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
        cout << "남은 아이템 수는 : " << item_num << "입니다." << endl;
    }
    else {
        cout << "아이템이 없습니다!" << endl;
    }
}

void Character::potion() 
{
    if (potion_num > 0)
    {
        if (HP <= level * 10)
        {
            HP = HP + 50;
            cout << "현재 체력은 : " << HP << "입니다." << endl;
        }
        else
        {
            HP = 50 + level * 10;
            cout << "현재 체력은 : " << HP << ". 최대치 입니다." << endl;
        }
    }
    else
    {
        cout << "사용할 수 있는 포션이 없습니다." << endl; //포션 갯수 예외처리
    }
}

void Character::showStat() const 
{
    cout << "이름: " << name << ", 체력: " << HP << ", 레벨: " << level << ", 아이템 수: " << item_num << ", 포션 수: " << potion_num << endl;
}

void Character::showHP() 
{
    cout << "현재 체력은: " << HP << endl;
}

void Character::attack(Character& player, Character& target)
{
    cout << "죽어라" << endl;
    target.HP = target.HP - player.level * 5; //어택 포인트 //데미지
    
    if (target.HP > 0) 
    {
        cout << "아직 살았습니다. 상대방의 남은 체력은 " << target.HP << "입니다." << endl;
    }
    else 
    {
        cout << "무찔렀다!" << endl;
    }
}

void Character::damage(int damage)
{
    HP -= damage; //내가 데미지->상대방의 어택포인특ㄹ 
}

int Character::getAttackPoint()
{
    return this->attackPoint;
}