#include "GameCharacter.h"
#include <iostream>

int main() {
    string playerName;
    cout << "ĳ������ �̸��� �Է��ϼ���: ";
    cin >> playerName;
    Character player(playerName);

    int choice;
    do {
        cout << "���� ��ȣ�� �Է��ϼ��� (0: ����, 1: �̸� ����, 2: ���� ��, 3: ������ �ݱ�, 4: ������ ���, 5: ���� ���): ";
        cin >> choice;
        switch (choice) {
        case 0:
            cout << "������ �����մϴ�." << endl;
            break;
        case 1:
            cout << "���ο� �̸��� �Է��ϼ���: ";
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
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    } while (choice != 0);

    return 0;
}
