//
// 240507, Serok, 실습 1 회원 명부 작성하기
//
#include <fstream>
#include<iostream>
#include <vector>
#include <string>

using namespace std;

// 사용자에게 3명의 회원에 대한 이름 비밀번호 입력 받기

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
        // c가 숫자가 아닌 문자일 경우 == 0
        if (isdigit(c) == 0)
        {
            cout << "문자를 제외하고 다시 입력해주세요.\n" << endl;
            return false;
        }
    }
    if (str.length() < 4 || str.length() > 16)
    {
        cout << "비밀번호는 4~16자리 입니다. 다시 입력해주세요.\n" << endl;
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
        // c가 문자가 아닌 숫자일 경우 == 0
        if (isalpha(c) == 0)
        {
            cout << "숫자를 제외하고 다시 입력해주세요.\n" << endl;
            return false;

        }
    }
    return true;
}

void inputStudentData(vector<members_info>& members)
{
    for (int i = 0; i < members.size(); ++i) {
        cout << i + 1 << "번째 회원 이름 입력: ";
        while (!CheckInputAlpha(members[i].name));

        cout << i + 1 << "번째 회원 비밀번호 입력: ";
        while (!CheckInputNumber(members[i].code));

    }
}

void printStudentInfo(const vector<members_info>& members)
{
    for (const auto& member : members) {
        cout << "이름: " << member.name << " 비밀번호: " << member.code  << endl;
    }
}

int main()
{
    // 1. 사용자에게 3명의 회원에 대한 이름 비밀번호 받기(벡터 생성)
    int memberNum;
    cout << "회원 수를 입력하세요: ";
    cin >> memberNum;
    vector<members_info> members(memberNum);

    inputStudentData(members);

    // 2. 사용자로부터 입력된 정보를 member.txt에 기록
    std::ofstream write_file("member.txt");
    if (write_file.is_open())
    {
        for (const auto& member : members) {
            write_file <<  member.name << " " << member.code << endl;
        }
    }
    write_file.close();

    // 3. 회원명부 출력
    cout << "----------" << "회원 명부 파일 읽기" << "----------" << endl;
    int lineCount = 0;
    std::ifstream read_file("member.txt");
    string line;
    vector<string> v;
    while (getline(read_file, line))
    {
        cout << line << endl;
        lineCount++;
    }

    read_file.close();

}