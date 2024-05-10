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
	cout << "사각형의 가로와 세로 길이를 입력해주세요. (띄어쓰기로 구분)" << endl;
	cin >> w >> h;
		
	Rectangle rect1(w, h);
	cout << "넓이는 : " << rect1.area() << endl;

	
	return 0;
}