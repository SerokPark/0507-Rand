#include <fstream>
#include<iostream>
#include <vector>
#include <string>

using namespace std;
//bool openCheck(ofstream file)
//{
//	if (file.is_open() == true)
//	{
//		file.close();
//	}
//};//kk


// file은 열고 닫기 필수. 그래야 저장 됨
// fstream file;
// file.open("파일 명")
// 파일 경로 정확히 알기. 아님 안열림
// 파일 경로가 "C:\new_folder"이면 \n이라 줄바꿈이 되서 안열릴 수도 있음
// C:\\new_folder \\두개쓰면 열림
// 파일이 제대로 열렸는지 확인해야함
// ifstream(input file stream)
// ofstream(output file stream)

// std :: ifstream read_file;(변수이름) //파일 담을 변수 선언
// read_file.open("경로"); // 파일 열기

int main()
{
	vector<string> v;
	v = { "Hello World!", "I love programming", "I love c++" };
	std :: fstream file;
	//file.open("hello.txt");
	std::ofstream write_file;
	write_file.open("hello.txt");

	for (int i=0; i < v.size(); i++)
	{
		write_file << v[i] << endl;
	}
	if (write_file.is_open() == true)
	{
		write_file.close();
	}
	std::ifstream read_file("hello.txt");
	string line;
	vector<string> s;
	
	for (int i = 0; i < 3; i++)
	{
		getline(read_file, line);
		cout << line << endl;
		s.push_back(line);
	}
	std::ofstream write_file2;
	write_file2.open("output.txt");
	int size = s.size() - 1;
	for (int i = size; i >=0; i--)
	{
		write_file2 << s[i] << endl;
	}
	if (read_file.is_open() == true)
	{
		read_file.close();
	}
	if (write_file2.is_open() == true)
	{
		write_file2.close();
	}
}
