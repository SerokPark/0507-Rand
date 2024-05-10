#include <iostream>

using namespace std;

class Rectangle
{
public:
	Rectangle();
	//~Rectangle();
	Rectangle(float width, float height) : m_width(width), m_height(height) {}
	Rectangle(const Rectangle& rect2)
	{
		m_width = rect2.m_width;
		m_height = rect2.m_height;
	}
	float area() { return m_width * m_height; }
private:
	float m_width;
	float m_height;
};

int main()
{
	Rectangle rect1(3, 4);
	Rectangle rect2(rect1); //���� ������ ȣ��

	cout << "���� �������� ���̴� : " << rect2.area() << endl; // ������ ������ ����

	Rectangle rect3(rect2);
	cout << "�⺻ �����ڿ� ������ ���̴� : " << rect3.area() << endl; // ������ ������ ����

	return 0;
}