#include<cstdlib>
#include<ctime>
#include <vector>
#include <iostream>

using namespace std;


int main()
{
	srand(1); //���� ���� seed ����
	vector<int> v;

	while (1)
	{
		if (v.size() == 6) break;

		int tmpNum = rand();

		int num = tmpNum % 45 + 1;

		bool isExist = false;
		
		for (int elem : v)
		{
			if (num == elem)
			{
				isExist = true;
				break;
			}
		}
		if (!isExist) v.push_back(num);
	}

	cout << "��÷ ��ȣ : ";
	for (int elem : v)
	{
		cout << elem << " ";
	}
}