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
	cout << "가로, 세로 길이를 입력하세요." << endl;
	cin >> x.width >> x.height;
	cout << "직사각형 넓이는 : " << x.width * x.height << "입니다.";
}