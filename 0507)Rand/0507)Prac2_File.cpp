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
    string telNum;
};

bool CheckInputNumber(string& str)
{
    // str = "123ab321"; str[0], str[4]
    //cin >> str;
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

void inputMemberData(vector<members_info>& members)
{
    for (int i = 0; i < members.size(); ++i) {
        cout << i + 1 << "번째 회원 이름 입력: ";
        while (!CheckInputAlpha(members[i].name));

        cout << i + 1 << "번째 회원 비밀번호 입력: ";
        cin >> members[i].code;
        while (!CheckInputNumber(members[i].code));

    }
}



bool CheckLoginData(vector<members_info>& members,string& inputName, string& inputCode)
{
    cout << "이름과 비밀번호를 입력하세요." << endl;
    cin >> inputName >> inputCode;
    for (int i = 0; i < members.size(); ++i) 
    {
        if (members[i].name == inputName) 
        {
            if (members[i].code == inputCode)
            {
                cout << "로그인 성공.\n" << endl;
                cout << "이름 : "<< inputName <<" "<< "비밀번호 : " << inputCode << endl;
                return true; // 일치하는 이름을 찾았을 때

            }

        }
    }
    cout << "로그인 실패.\n" << endl;
    return false; // 일치하는 이름이 없을 때
}

void UpdateTelephoneFile(vector<members_info>& members, string& inputName, string& inputTelNum) 
{
    fstream fs;
    fs.open("member_tel.txt");
    fs.seekg(0, ios::beg);

    string line;
    bool found = false;
    int pos;

    while (getline(fs, line)) 
    {
        size_t namePos = line.find(inputName);
        if (namePos != string::npos) {
            found = true;
            break;
        }
        pos = fs.tellg(); //위치값 pos에 저장
    }
    if (found) 
    {
        fs.seekp(pos, ios::beg); // 쓰기 위치 지정자를 찾은 위치로 이동
        fs << inputName << ' ' << inputTelNum << endl; // 전화번호 업데이트
        cout << "기존에 있는 회원입니다. 전화 번호를 업데이트 합니다." << endl;
        cout << "---------------------------" << endl;
        cout << "이름 : " << inputName << "전화번호 : " << inputTelNum << endl;
    }
    else 
    {
        // 새로운 회원 정보 추가
        fs.clear(); // EOF  지우고
        fs.seekp(0, ios::end); // 쓰기 위치 지정자를 파일의 끝으로 이동
        fs << inputName << ' ' << inputTelNum << endl; // 새로운 회원 정보 작성
        cout << "전화번호가 입력됩니다." << endl;
        cout << "---------------------------" << endl;
        cout << "이름 : " << inputName << "전화번호 : " << inputTelNum << endl;

    }

    fs.close(); // 파일 닫기
}

void printMemberInfo(const vector<members_info>& members)
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

    inputMemberData(members);

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

    // 실습 2. 회원 명부를 응용한 로그인 기능
    
    string inputName, inputCode, inputTelNum;
    char quit = ' ';

    while (quit != 'q') 
    {
        cout << "--------------" << "로그인 시스템" << "--------------" << endl;
        if (CheckLoginData(read_members, inputName, inputCode)) 
        {
            
            cout << "전화번호를 입력하세요.(공백, 특수문자 제외)/종료를 원할 시 'q' 입력" << endl;
            getline(cin, inputTelNum);
            if (inputTelNum == "q")
            {
                break;
            }

            while (!CheckInputNumber(inputTelNum)) 
            {
                cout << "전화번호를 입력하세요.(공백, 특수문자 제외)/종료를 원할 시 'q' 입력" << endl;
                getline(cin, inputTelNum);
                if (inputTelNum == "q") break;
            }

            if (inputTelNum != "q") 
            {
                UpdateTelephoneFile(read_members, inputName, inputTelNum);
            }
        }

        cout << "계속하려면 아무 키나 입력하세요. 종료하려면 'q'를 입력하세요." << endl;
        quit = cin.get();
        
    }

    return 0; 


}