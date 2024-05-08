//
// 240507, Serok, �ǽ� 1 ȸ�� ��� �ۼ��ϱ�
//
#include <fstream>
#include<iostream>
#include <vector>
#include <string>

using namespace std;

// ����ڿ��� 3���� ȸ���� ���� �̸� ��й�ȣ �Է� �ޱ�

struct members_info 
{
    string name;
    string code;
};

bool CheckInputNumber(string& str)
{
    // str = "123ab321"; str[0], str[4]
    cin >> str;
    for (char c : str) // for-each
    {
        // c�� ���ڰ� �ƴ� ������ ��� == 0
        if (isdigit(c) == 0)
        {
            cout << "���ڸ� �����ϰ� �ٽ� �Է����ּ���.\n" << endl;
            return false;
        }
    }
    if (str.length() < 4 || str.length() > 16)
    {
        cout << "��й�ȣ�� 4~16�ڸ� �Դϴ�. �ٽ� �Է����ּ���.\n" << endl;
        return false;
    }
    return true;
}

bool CheckInputAlpha(string& str)
{
    // str = "123ab321"; str[0], str[4]
    cin >> str;
    for (char c : str) // for-each
    {
        // c�� ���ڰ� �ƴ� ������ ��� == 0
        if (isalpha(c) == 0)
        {
            cout << "���ڸ� �����ϰ� �ٽ� �Է����ּ���.\n" << endl;
            return false;

        }
    }
    return true;
}

void inputMemberData(vector<members_info>& members)
{
    for (int i = 0; i < members.size(); ++i) {
        cout << i + 1 << "��° ȸ�� �̸� �Է�: ";
        while (!CheckInputAlpha(members[i].name));

        cout << i + 1 << "��° ȸ�� ��й�ȣ �Է�: ";
        while (!CheckInputNumber(members[i].code));

    }
}


bool CheckLoginData(vector<members_info>& members,string& inputName, string& inputCode)
{
    cout << "�̸��� ��й�ȣ�� �Է��ϼ���." << endl;
    cin >> inputName >> inputCode;
    for (int i = 0; i < members.size(); ++i) 
    {
        if (members[i].name == inputName) 
        {
            if (members[i].code == inputCode)
            {
                cout << "�α��� ����.\n" << endl;
                cout << "�̸� : "<< inputName <<" "<< "��й�ȣ : " << inputCode << endl;
                return true; // ��ġ�ϴ� �̸��� ã���� ��
            }

        }
    }
    cout << "�α��� ����.\n" << endl;
    return false; // ��ġ�ϴ� �̸��� ���� ��
}

void printMemberInfo(const vector<members_info>& members)
{
    for (const auto& member : members) {
        cout << "�̸�: " << member.name << " ��й�ȣ: " << member.code  << endl;
    }
}

int main()
{
    // 1. ����ڿ��� 3���� ȸ���� ���� �̸� ��й�ȣ �ޱ�(���� ����)
    int memberNum;
    cout << "ȸ�� ���� �Է��ϼ���: ";
    cin >> memberNum;
    vector<members_info> members(memberNum);

    inputMemberData(members);

    // 2. ����ڷκ��� �Էµ� ������ member.txt�� ���
    std::ofstream write_file("member.txt");
    if (write_file.is_open())
    {
        for (const auto& member : members) {
            write_file <<  member.name << " " << member.code << endl;
        }
    }
    write_file.close();

    // 3. ȸ����� ���
    cout << "----------" << "ȸ�� ��� ���� �б�" << "----------" << endl;
    //int lineCount = 0;
    std::ifstream read_file("member.txt");
    string line;
    vector<members_info> read_members(memberNum);
    
    int count = 0;
    while (getline(read_file, line))
    {
        read_members[count].name = line.substr(0, line.find(" "));
        read_members[count].code = line.substr(line.find(" ")+1);
                        
        cout << line << endl;
        
        count++;
    }

    read_file.close();

    // �ǽ� 2. ȸ�� ��θ� ������ �α��� ���
    
    string inputName, inputCode;
    while (!CheckLoginData(read_members,inputName,inputCode));

    return 0;


}