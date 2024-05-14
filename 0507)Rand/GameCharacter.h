#pragma once

#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include <string>
#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class Character {
private:
    string name;
    int level;
    int item_num;
    int HP;
    int attackPoint;
    int potion_num;

public:
    Character(string name);
    void changeName(string newName);
    void levelUp();
    void pickItem();
    void useItem();
    void showStat() const;
    void showHP();
    void potion();
    void attack(Character& player, Character& target);
    void damage(int damage);
    int getAttackPoint();
    int getHP() { return HP; } // HP값 가져오는 getter
        
};

#endif
