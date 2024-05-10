#include <iostream>

using namespace std;

class Rectangle
{
public:
	Rectangle();
	//~Rectangle();
	Rectangle(float width, float height) : m_width(width), m_height(height) {}
	
	// getter함수
	float getWidth() { return m_width; }
	float getHeight() { return m_height; }

	// setter함수
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
	cout << "넓이는: " << rect.area() << endl;

	cout << "사각형의 가로와 세로 길이를 입력해주세요. (띄어쓰기로 구분) ";
	cin >> width >> height;

	rect.setWidth(width);
	rect.setHeight(height);
	cout << "넓이는: " << rect.area() << endl;
	cout << "가로 세로 길이는: " << rect.getWidth() << " " << rect.getHeight() << endl;

	return 0;
}