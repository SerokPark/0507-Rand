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
	Rectangle rect2(rect1); //복사 생성자 호출

	cout << "복사 생성자의 넓이는 : " << rect2.area() << endl; // 복사한 변수의 넓이

	Rectangle rect3(rect2);
	cout << "기본 생성자에 복사한 넓이는 : " << rect3.area() << endl; // 복사한 변수의 넓이

	return 0;
}