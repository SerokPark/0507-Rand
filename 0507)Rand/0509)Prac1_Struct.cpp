#include<iostream>
#include <vector>
#include <string>

using namespace std;

struct Rectangle
{
	float width = 0;
	float height = 0;
};

int main()
{
	Rectangle x;
	cout << "����, ���� ���̸� �Է��ϼ���." << endl;
	cin >> x.width >> x.height;
	cout << "���簢�� ���̴� : " << x.width * x.height << "�Դϴ�.";
}