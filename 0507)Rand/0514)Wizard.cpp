#include <iostream>

using namespace std;

class Monster
{
public :
	string m_Name;
	int m_HP;
private :
	int m_MP;
protected :
	int m_DEF;
public :
	int GetHP()
	{
		return m_HP;
	}
	int GetMP()
	{
		return m_MP;
	}
	virtual void Func()
	{
		
	}
};

class Fighter : public Monster
{
public :
	void Func() override
	{
		m_HP;
		m_MP; // private 외부 접근 불가능 Monster 클래스에서만 접근 가능
		m_DEF; 
	}
};

class Archer : private Monster
{
public : 
	void Func() override
	{
		m_HP;
		m_MP; 
		m_DEF;
	}
};

class Wizard : protected Monster
{
public:
	void Func() override
	{
		m_HP;
		m_MP; // private 외부 접근 불가능 Monster 클래스에서만 접근 가능
		m_DEF;
	}
};

int main()
{
	Monster Temp_Monster;
	Fighter Temp_Fighter;
	Archer Temp_Archer;
	Wizard Temp_Wizard;

	Temp_Monster.m_HP;
	Temp_Fighter.m_MP;

}