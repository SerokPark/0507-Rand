#include <iostream>

using namespace std;

class Rectangle
{
public:
	Rectangle();
	//~Rectangle();
	Rectangle(float width, float height) : m_width(width), m_height(height) {}
	
	float area() { return m_width * m_height; }
private:
	float m_width;
	float m_height;
};

//Rectangle::Rectangle()
//{
//}
//
//Rectangle::~Rectangle()
//{
//}

int main()
{
	float w, h;
	cout << "�簢���� ���ο� ���� ���̸� �Է����ּ���. (����� ����)" << endl;
	cin >> w >> h;
		
	Rectangle rect1(w, h);
	cout << "���̴� : " << rect1.area() << endl;

	
	return 0;
}