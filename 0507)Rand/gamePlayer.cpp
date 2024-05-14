#include "GameCharacter.h"
#include <iostream>

int main() 
{
    //
    // ĳ���� �̸� ����, 2�� ����
    //
    string playerName1;
    cout << "1�� ĳ������ �̸��� �Է��ϼ���: ";
    cin >> playerName1;
    Character player1(playerName1);
    player1.showStat();

    string playerName2;
    cout << "2�� ĳ������ �̸��� �Է��ϼ���: ";
    cin >> playerName2;
    Character player2(playerName2);
    player2.showStat();
    

    //player2.damage(player1.getAttackPoint());

    // ĳ���� �θ� �̸� ����->���� �����ְ� -> 
    // ������ ����, ������ ���� ���� -> 
    // ĳ���� ��ȣ �Է��ϸ�, ĳ���� ����(���̽��� �Ѿ)
    // ���� ������ �Դٰ��� ���� ���� flipflap(true�϶� 1��, 

    //
    //
    //
    //
    int sChoice;
    
    do {
        cout << "���� ��ȣ�� �Է��ϼ��� (0: ĳ���� ���� ����, 1: �̸� ����, 2: ���� ��, 3: ������ �ݱ�, 4: ������ ���, 5: ���� ���): ";
        cin >> sChoice;
        switch (sChoice) {
        case 0:
            cout << "ĳ���� ������ �����մϴ�." << endl;
            break;
        case 1:
            cout << "���ο� �̸��� �Է��ϼ���: ";
            cin >> playerName1;
            player1.changeName(playerName1);
            break;
        case 2:
            player1.levelUp();
            break;
        case 3:
            player1.pickItem();
            break;
        case 4:
            player1.useItem();
            break;
        case 5:
            player1.showStat();
            break;
        default:
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    } while (sChoice != 0);

    int aChoice ;
        
    while (1)

    {
        cout << "�÷��̾� 1�� �����Դϴ�. ���� ��ȣ�� �Է��ϼ��� ( 0�� : ���� ����, 1�� : ���� �Ա� -> ü�� ȸ�� 50 )" << endl;
        cin >> aChoice;
        switch (aChoice)
        {
        case 0:
            cout << "���� ���� !" << endl;
            player2.damage(player1.getAttackPoint());
            cout << "�÷��̾� 2�� ";
            player2.showHP();
            break;

        case 1:
            cout << "������ �Ծ����ϴ�. " << endl;
            player1.potion();
            cout << "�÷��̾� 1�� ";
            break;

        default:
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
            break;
        }
        if (player2.getHP() <= 0)
        {
            cout << "���񷶴�!\(@^0^@)/" << endl;
            break;
        }

        cout << "�÷��̾� 2�� �����Դϴ�. ���� ��ȣ�� �Է��ϼ��� ( 0�� : ���� ����, 1�� : ���� �Ա� -> ü�� ȸ�� 50 )" << endl;
        cin >> aChoice;
        switch (aChoice)
        {
        case 0:
            cout << "���� ���� !" << endl;
            player1.damage(player2.getAttackPoint());
            cout << "�÷��̾� 1�� ";
            player1.showHP();
            break;

        case 1:
            cout << "������ �Ծ����ϴ�. " << endl;
            player2.potion();
            cout << "�÷��̾� 2�� ";
            break;

        default:
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
            break;
        }
        if (player1.getHP() <= 0)
        {
            cout << "�÷��̾ ����߽��ϴ�.��=��=��=��(?��?;)��" << endl;
            break;
        }

    }

    return 0;
}
