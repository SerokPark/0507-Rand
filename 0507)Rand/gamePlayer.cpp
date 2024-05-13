#include "GameCharacter.h"
#include <iostream>

int main() {
    string playerName;
    cout << "캐릭터의 이름을 입력하세요: ";
    cin >> playerName;
    Character player(playerName);

    int choice;
    do {
        cout << "조작 번호를 입력하세요 (0: 종료, 1: 이름 변경, 2: 레벨 업, 3: 아이템 줍기, 4: 아이템 사용, 5: 상태 출력): ";
        cin >> choice;
        switch (choice) {
        case 0:
            cout << "게임을 종료합니다." << endl;
            break;
        case 1:
            cout << "새로운 이름을 입력하세요: ";
            cin >> playerName;
            player.changeName(playerName);
            break;
        case 2:
            player.levelUp();
            break;
        case 3:
            player.pickItem();
            break;
        case 4:
            player.useItem();
            break;
        case 5:
            player.showStat();
            break;
        default:
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    } while (choice != 0);

    return 0;
}
