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


// file�� ���� �ݱ� �ʼ�. �׷��� ���� ��
// fstream file;
// file.open("���� ��")
// ���� ��� ��Ȯ�� �˱�. �ƴ� �ȿ���
// ���� ��ΰ� "C:\new_folder"�̸� \n�̶� �ٹٲ��� �Ǽ� �ȿ��� ���� ����
// C:\\new_folder \\�ΰ����� ����
// ������ ����� ���ȴ��� Ȯ���ؾ���
// ifstream(input file stream)
// ofstream(output file stream)

// std :: ifstream read_file;(�����̸�) //���� ���� ���� ����
// read_file.open("���"); // ���� ����

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
