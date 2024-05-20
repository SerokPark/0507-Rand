#include <iostream>


using namespace std;

class Person
{
public: 
	virtual void intro() 
	{
	cout << "사람입니다~" << endl;
	}
};

class Student : public Person
{
	string name;

public : 
	Student(string name)
	{
		this->name = name;
	}
	void intro()
	{
		cout << name << "학생입니다." << endl;
	}
	void learn()
	{
		cout << "배웁니다." << endl;
	}
};

class Teacher : public Person
{
	string name;

public : 
	Teacher(string name)
	{
		this->name = name;
	}
	void intro()
	{
		cout << name << "선생님입니다." << endl;
	}
	void teach()
	{
		cout << "가르칩니다." << endl;
	}
};

int main()
{
	Person* pList[3];
	string names[3];

	cout << "3명의 이름을 입력해주세요.(선생님, 학생, 학생)" << endl;
	cin >> names[0] >> names[1] >> names[2];

	// names[]배열 이용하여 각 class 생성
	Person* teacher = new Teacher(names[0]);
	Person* studentA = new Student(names[1]);
	Person* studentB = new Student(names[2]);

	// pList에 할당하는 코드 추가
	pList[0] = teacher;
	pList[1] = studentA;
	pList[2] = studentB;

	for (auto p : pList)
	{
		p->intro();
	}

	// 각 class의 고유 함수 실행(teach(), learn(), learn())
	((Teacher*)pList[0])->teach();
	((Student*)pList[1])->learn();
	((Student*)pList[2])->learn();
}