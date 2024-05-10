#include <iostream>

using namespace std;

class Rectangle
{
public:
	Rectangle();
	//~Rectangle();
	Rectangle(float width, float height) : m_width(width), m_height(height) {}
	
	// getter�Լ�
	float getWidth() { return m_width; }
	float getHeight() { return m_height; }

	// setter�Լ�
	void setWidth(float width) { this->m_width = width; }
	void setHeight(float height) { this->m_height = height; }


	float area() { return m_width * m_height; }
private:
	float m_width;
	float m_height;
};

int main()
{
	float width, height;

	Rectangle rect( 1, 2 );
	cout << "���̴�: " << rect.area() << endl;

	cout << "�簢���� ���ο� ���� ���̸� �Է����ּ���. (����� ����) ";
	cin >> width >> height;

	rect.setWidth(width);
	rect.setHeight(height);
	cout << "���̴�: " << rect.area() << endl;
	cout << "���� ���� ���̴�: " << rect.getWidth() << " " << rect.getHeight() << endl;

	return 0;
}