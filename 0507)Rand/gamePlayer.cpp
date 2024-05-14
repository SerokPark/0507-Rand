#include "GameCharacter.h"
#include <iostream>

int main() 
{
    //
    // 캐릭터 이름 설정, 2명 생성
    //
    string playerName1;
    cout << "1번 캐릭터의 이름을 입력하세요: ";
    cin >> playerName1;
    Character player1(playerName1);
    player1.showStat();

    string playerName2;
    cout << "2번 캐릭터의 이름을 입력하세요: ";
    cin >> playerName2;
    Character player2(playerName2);
    player2.showStat();
    

    //player2.damage(player1.getAttackPoint());

    // 캐릭터 두명 이름 생성->정보 보여주고 -> 
    // 설정할 건지, 공격할 건지 선택 -> 
    // 캐릭터 번호 입력하면, 캐릭터 설정(초이스로 넘어감)
    // 공격 누르면 왔다갔다 서로 공격 flipflap(true일땐 1번, 

    //
    //
    //
    //
    int sChoice;
    
    do {
        cout << "조작 번호를 입력하세요 (0: 캐릭터 설정 종료, 1: 이름 변경, 2: 레벨 업, 3: 아이템 줍기, 4: 아이템 사용, 5: 상태 출력): ";
        cin >> sChoice;
        switch (sChoice) {
        case 0:
            cout << "캐릭터 설정을 종료합니다." << endl;
            break;
        case 1:
            cout << "새로운 이름을 입력하세요: ";
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
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    } while (sChoice != 0);

    int aChoice ;
        
    while (1)

    {
        cout << "플레이어 1의 순서입니다. 조작 번호를 입력하세요 ( 0번 : 상대방 공격, 1번 : 포션 먹기 -> 체력 회복 50 )" << endl;
        cin >> aChoice;
        switch (aChoice)
        {
        case 0:
            cout << "상대방 공격 !" << endl;
            player2.damage(player1.getAttackPoint());
            cout << "플레이어 2의 ";
            player2.showHP();
            break;

        case 1:
            cout << "포션을 먹었습니다. " << endl;
            player1.potion();
            cout << "플레이어 1의 ";
            break;

        default:
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
            break;
        }
        if (player2.getHP() <= 0)
        {
            cout << "무찔렀다!\(@^0^@)/" << endl;
            break;
        }

        cout << "플레이어 2의 차례입니다. 조작 번호를 입력하세요 ( 0번 : 상대방 공격, 1번 : 포션 먹기 -> 체력 회복 50 )" << endl;
        cin >> aChoice;
        switch (aChoice)
        {
        case 0:
            cout << "상대방 공격 !" << endl;
            player1.damage(player2.getAttackPoint());
            cout << "플레이어 1의 ";
            player1.showHP();
            break;

        case 1:
            cout << "포션을 먹었습니다. " << endl;
            player2.potion();
            cout << "플레이어 2의 ";
            break;

        default:
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
            break;
        }
        if (player1.getHP() <= 0)
        {
            cout << "플레이어가 사망했습니다.ε=ε=ε=┏(?ロ?;)┛" << endl;
            break;
        }

    }

    return 0;
}
