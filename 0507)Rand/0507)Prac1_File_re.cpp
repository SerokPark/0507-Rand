#include <fstream>
#include<iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int lineCount = 0;
	std::ifstream read_file("hello.txt");
	string line;
	vector<string> v;
	while (getline(read_file, line))
	{
		v.push_back(line);
		lineCount++;
	}

	read_file.close();

	std::ofstream write_file3("Output.txt");
	if (write_file3.is_open())
	{
		for (int i = 0; i < v.size(); i++)
		{
			write_file3 << v.back() << endl;
			v.pop_back();
		}
	}
	
	write_file3.close();
	

}