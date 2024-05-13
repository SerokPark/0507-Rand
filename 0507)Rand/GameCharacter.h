#pragma once

#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include <string>
#include <iostream>

using namespace std;

class Character {
private:
    string name;
    int level;
    int item_num;

public:
    Character(string name);
    void changeName(string newName);
    void levelUp();
    void pickItem();
    void useItem();
    void showStat() const;
};

#endif
